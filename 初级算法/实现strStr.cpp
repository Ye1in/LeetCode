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
	int strStr(string haystack, string needle)
	{
		int j;
		if (needle.empty())
			return 0;
		for (int i = 0; i < haystack.size(); ++i)
		{
			if (haystack[i] == needle[0])
			{
				for (j = 0; j < needle.size(); ++j)
				{
					if (haystack[i + j] != needle[j])
					{
						break;
					}
				}
				if (j == needle.size())
				{
					return i;
				}
			}
		}
		return -1;
	}
};
string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string haystack = stringToString(line);
		getline(cin, line);
		string needle = stringToString(line);

		int ret = Solution().strStr(haystack, needle);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}