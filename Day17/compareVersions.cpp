// Hi, here's your problem today. This problem was recently asked by Amazon:

// Version numbers are strings that are used to identify unique states of software products. A version number is in the format a.b.c.d. and so on where a, b, etc. are numeric strings separated by dots. These generally represent a hierarchy from major to minor changes. Given two version numbers version1 and version2, conclude which is the latest version number. Your code should do the following:
// If version1 > version2 return 1.
// If version1 < version2 return -1.
// Otherwise return 0.

// Note that the numeric strings such as a, b, c, d, etc. may have leading zeroes, and that the version strings do not start or end with dots. Unspecified level revision numbers default to 0.

// Example:
// Input:
// version1 = "1.0.33"
// version2 = "1.0.27"
// Output: 1
// #version1 > version2

// Input:
// version1 = "0.1"
// version2 = "1.1"
// Output: -1
// #version1 < version2

// Input:
// version1 = "1.01"
// version2 = "1.001"
// Output: 0
// #ignore leading zeroes, 01 and 001 represent the same number.

// Input:
// version1 = "1.0"
// version2 = "1.0.0"
// Output: 0
// #version1 does not have a 3rd level revision number, which
// defaults to "0"

#include <iostream>
#include <string>

using namespace std;

int compareVersion(string version1, string version2)
{
    int levelStart1 = 0;
    int levelStart2 = 0;
    int l = 0;
    while (l<3)
    {
        int i = levelStart1;
        int j = levelStart2;
        int versionLevel1 = 0, versionLevel2 = 0;
        for (; i < version1.length(); i++)
        {
            if (version1[i] == '.')
            {
                break;
            }
        }
        if(levelStart1 < version1.length()){
            string versionLevelStr1 = version1.substr(levelStart1, i - levelStart1);
            versionLevel1 = stoi(versionLevelStr1);
        }
        
        levelStart1 = i + 1;
        for (; j < version2.length(); j++)
        {
            if (version2[j] == '.')
            {
                break;
            }
        }
        
        if(levelStart2 < version2.length()){
            string versionLevelStr2 = version2.substr(levelStart2, j - levelStart2);
            versionLevel2 = stoi(versionLevelStr2);
        }
        cout << versionLevel1 << "," << versionLevel2 <<endl;
        levelStart2 = j + 1;
        if (versionLevel1 > versionLevel2)
        {
            return 1;
        }
        else if (versionLevel1 < versionLevel2)
        {
            return -1;
        }
        else
        {
            if (levelStart1 >= version1.length() && levelStart2 >= version2.length())
            {
                return 0;
            }
            else
            {
                continue;
            }
        }
        l++;
    }
    return 0;
}

int main()
{
    string version1 = "1.0.33";
    string version2 = "1.0.27";
    cout << compareVersion(version1, version2) << endl;
    return 0;
}