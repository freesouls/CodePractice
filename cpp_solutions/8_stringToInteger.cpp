#include<string>
#include<stdint.h>
using namespace std;

class Solution {
public:
	int atoi(string str) {
		// INT_MAX (2147483647) or INT_MIN (-2147483648)
		if (str.length() < 1)
		{
			return 0;
		}

		int sign = 1;
		int start = -1;

		while (str[++start] == ' '&&start<str.length()){}

		if (str[start]=='+')
		{
			//sign = 1;
			start++;
		}
		else if (str[start] == '-')
		{
			sign = 0;
			start++;
		}

		int res = 0;
		for (int i = start; i < str.length(); i++)
		{
			if ('0' <= str[i] && str[i] <= '9')
			{
				if (res>INT_MAX/10 || (res == INT_MAX/10 && INT_MAX%10<str[i]-'0'))
				{
					return sign ? INT_MAX : INT_MIN;
				}
				res = res * 10 + str[i] - '0';
			}
			else
			{
				break;
			}
		}

		return sign ? res : res*-1;


		/* version 2
		//change the sign to -1 when judge '-'
		double tmp = 0;
		for (int i = start; i < str.length(); i++)
		{
			if ('0'<=str[i]&&str[i]<='9')
			{
				tmp = tmp*10 + (str[i] - '0')*sign;
				//check bounds
				if (tmp > INT_MAX){
					return INT_MAX;
				}
				else if (tmp < INT_MIN)
				{
					return INT_MIN;
				}
			}
			else
			{
				break;
			}
		}

		return (int)tmp;
		*/
	}
};

int main()
{
	Solution *s = new Solution();
	int b = s->atoi("-1");
	return 0;
}
