#include<string>
#include<stdint.h>
using namespace std;
class Solution {
public:
	string convert(string s, int nRows) {
		int len = s.length();
		if (len <= nRows || nRows == 1)
		{
			return s;
		}
		int divide = nRows * 2 - 2;
		int shang = len / divide;
		int reminder = len % divide;

		string tmp = "";

		for (int i = 0; i < nRows; i++)
		{
			for (int j = 0; j < shang; j++)
			{
				tmp.append(s, j*divide + i, 1);
				if (i != 0 && i != nRows-1) // not the first line or last line
				{
					tmp.append(s, j*divide + divide - i, 1);
				}
			}

			if (reminder>i)
			{
				tmp.append(s, shang*divide + i, 1);
			}
			if (reminder + i>= divide + 1 && i != 0 && i != nRows -1 )
			{
				tmp.append(s, shang*divide + divide - i, 1);
			}

		}
		return tmp;
	}

};

int main()
{
	int c = 11 & 0x1;
	int d = 11 >> 1;
	Solution *s = new Solution();
	string a = "PAYPALISHIRING";
	string b = s->convert("ABCDEF", 4);
	return 0;
}
