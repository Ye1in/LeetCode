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
class Solution {
public:
	string countAndSay(int n) {
		string s1 = "1", s2 = "";
		while (--n) {
			for (int i = 0; i < s1.size(); i++) {
				for (int j = 0; ; j++) {
					if (i + j < s1.size() && s1[i + j] == s1[i + j + 1]) continue;
					j++;
					s2 = s2 + to_string(j) + s1[i];
					i = i + j - 1;
					break;
				}
			}
			s1 = s2;
			s2 = "";
		}
		return s1;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);

		string ret = Solution().countAndSay(n);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}