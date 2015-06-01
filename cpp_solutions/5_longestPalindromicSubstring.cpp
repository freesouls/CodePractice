#include<string>
#include<stdint.h>
using namespace std;

/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.
wiki:
http://www.wikiwand.com/en/Longest_palindromic_substring
*/
class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		if (len <= 1)
		{
			return s;
		}
		else
		{
			int maxLen = 1;
			int begin = 0;
			//string longestString = s[0];
			for (int i = 0; i < len-1; i++)
			{
				getLongest(s, i, i, begin, maxLen);
				getLongest(s, i, i + 1, begin, maxLen);
			}
			return s.substr(begin, maxLen);
		}
	}

	void getLongest(string s, int left, int right, int& begin, int& maxLen)
	{
		int len = 0;
		while (left>=0 && right <= s.length() && s[left]==s[right])
		{
			if (left == right)
			{
				len = len + 1;
			}
			else
			{
				len = len + 2;
			}
			left--;
			right++;
		}
		if (len > maxLen)
		{
			maxLen = len;
			begin = left + 1;
		}
	}

};

int main()
{
	int c = 11 & 0x1;
	int d = 11 >> 1;
	Solution *s = new Solution();
	string a = "aaaaaaa";
	string b = s->longestPalindrome(a);
	return 0;
}