// Hi, here's your problem today. This problem was recently asked by Google:

// A chess board is an 8x8 grid. Given a knight at any position (x, y) and a number of moves k, we want to figure out after k random moves by a knight, the probability that the knight will still be on the chessboard. Once the knight leaves the board it cannot move again and will be considered off the board.

#include <iostream>
#include <unordered_map>

using namespace std;

// size of the chessboard
#define N 8

template <class T1, class T2>
struct ChessBoardStep
{

    T1 x, y;
    T2 step;

    ChessBoardStep(T1 x, T1 y, T2 step)
    {
        this->x = x;
        this->y = y;
        this->step = step;
    }

    bool operator==(const ChessBoardStep &cbs) const
    {
        return x == cbs.x && y == cbs.y && step == cbs.step;
    }
};

struct hash_pair_step
{
    template <class T1, class T2>
    size_t operator()(const ChessBoardStep<T1, T2> &cbs) const
    {
        auto hash1 = hash<T1>{}(cbs.x);
        auto hash2 = hash<T1>{}(cbs.y);
        auto hash3 = hash<T2>{}(cbs.step);
        return hash1 ^ hash2 ^ hash3;
    }
};

// direction vector for the Knight
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

bool inside(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

float is_knight_on_board(int x, int y, int k, unordered_map<ChessBoardStep<int, int>, float, hash_pair_step> &cache)
{
    ChessBoardStep<int, int> point(x, y, k);
    if (cache.find(point) != cache.end())
    {
        return cache[point];
    }
    else
    {
        if (k == 0)
        {
            cache[point] = 1;
            return 1;
        }
        if (k == 1)
        {
            float probability = 0;
            for (int i = 0; i < N; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (inside(nx, ny))
                {
                    probability++;
                }
            }
            probability /= 8.0;
            cache[point] = probability;

            return probability;
        }
        else
        {
            float probability = 0;

            for (int i = 0; i < N; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (inside(nx, ny))
                {
                    probability += is_knight_on_board(nx, ny, k - 1, cache);
                }
            }
            probability /= 8.0;
            cache[point] = probability;
            return probability;
        }
    }
}

int main()
{
    unordered_map<ChessBoardStep<int, int>, float, hash_pair_step> cache;
    cout << is_knight_on_board(0, 0, 100, cache);
    return 0;
}