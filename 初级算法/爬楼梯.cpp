#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>
#include <assert.h>
using namespace std;
class Solution
{
  public:
    int climbStairs(int n)
    {
        if (n == 1 || n == 2)
            return n;
        int *a = new int[n + 1];
        a[1] = 1;
        a[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            a[i] = a[i - 1] + a[i - 2];
        }
        return a[n];
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        int n = stringToInteger(line);

        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}