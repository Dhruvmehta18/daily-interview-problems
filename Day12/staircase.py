# Hi, here's your problem today. This problem was recently asked by LinkedIn:

# You are given a positive integer N which represents the number of steps in a staircase.
# You can either climb 1 or 2 steps at a time.
# Write a function that returns the number of unique ways to climb the stairs.

# Can you find a solution in O(n) time?

prev = [1, 1]


def staircase(n):
    for i in range(len(prev), n+1):
        prev.append(prev[i-1] + prev[i-2])
    return prev[n]


print(staircase(4))
# 5
print(staircase(5))
# 8


class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [0]*n
        return self.Climb_Stairs(0, n, dp)

    def Climb_Stairs(self, i, n, dp):
        if i > n:
            return 0
        if i == n:
            return 1
        if dp[i] > 0:
            return dp[i]
        dp[i] = self.Climb_Stairs(i+1,n,dp) + self.Climb_Stairs(i+2,n,dp)
        return dp[i]
