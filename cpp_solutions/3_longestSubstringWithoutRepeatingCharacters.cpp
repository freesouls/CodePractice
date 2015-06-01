#include<string>

using namespace std;
/*
Given a string, find the length of the longest substring without repeating
characters. For example, the longest substring without repeating letters 
for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest 
substring is "b", with the length of 1.
*/

int max(int a, int b)
{
	return a > b ? a : b;
}

#define MAX_CHAR 128

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
  
		int index[MAX_CHAR]; // -1 means unknown index
		memset(index, -1, MAX_CHAR * sizeof(int));//set all the index to -1

		int maxLen = 0, len=0;
		for (int i = 0; i < s.size(); i++)
		{
			if (index[s[i]-'\0']>=0) // use '\0' is because the character can be anything like ',' 
			{
				maxLen = max(maxLen, len);
				len = 0;
				i = index[s[i] - '\0'] + 1;//get the new start index
				memset(index, -1, MAX_CHAR*sizeof(int));//set all the index to -1
			}
			index[s[i] - '\0'] = i;
			len++;
		}

		return max(len, maxLen);
	}
};

int main()
{
	Solution *s = new Solution();
	string a = "brnk";
	int b = s->lengthOfLongestSubstring(a);
	//int c = max(1, 2);
	return 0;
}