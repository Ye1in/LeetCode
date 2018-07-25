#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>
#include <assert.h>
#include <queue>
using namespace std;
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
  public:
    int firstBadVersion(int n)
    {
        int min = 0, max = n, mid{};
        while (min <= max)
        {
            mid = min + (max - min) / 2;
            if (isBadVersion(mid))
                max = mid - 1;
            else
                min = mid + 1;
        }
        return min;
    }
};