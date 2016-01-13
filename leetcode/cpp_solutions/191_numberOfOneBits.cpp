/*
Write a function that takes an unsigned integer and 
returns the number of ’1' bits it has (also known as 
the Hamming weight).For example, the 32-bit integer ’11' 
has binary representation 00000000000000000000000000001011, 
so the function should return 3.
*/
class Solution {
public:
	int hammingWeight(unsigned int n) {
		int count = 0;
		for (int i = 0; i < 32; i++)
		{
			if (n&0x1==1)
			{
				count++;
			}
			n = n >> 1;
		}
		return count;
	}

};

int main()
{
	Solution *s = new Solution();
	int b = s->hammingWeight(11);
	return 0;
}