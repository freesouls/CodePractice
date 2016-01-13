#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		map<int, int> dic;
		vector<int> results;
		for (int i = 0; i < numbers.size(); i++)
		{
			int res = dic.count(numbers[i]);
			if (res == 0)
			{
				dic.insert(make_pair(target - numbers[i], i));
			}
			else
			{
				int j = dic[numbers[i]];
				if (i>j)
				{
					results.push_back(j+1);
					results.push_back(i+1);
				}
				else
				{
					results.push_back(i+1);
					results.push_back(j+1);
				}
					
				return results;
			}
		}
	
		return results;
	}

	void sort(vector<int> &numbers, int begin, int end){
		int i = begin, j = end;
		int pivot = numbers[(begin + end) / 2];

		while (i<=j)
		{
			while (numbers[i] < pivot) i++;
			while (numbers[j] > pivot) j--;
			if (i<=j)
			{
				int tmp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = tmp;
				i++;
				j--;
			}
		}

		if (begin < j)
		{
			sort(numbers, begin, j);
		}
		if (i < end)
		{
			sort(numbers, i, end);
		}
	}
};

int main()
{
	Solution *s = new Solution();
	/* 0,3,4,0
	   -3,4,3,90*/
	vector<int> a,b;
	a.push_back(-3);
	a.push_back(4);
	a.push_back(3);
	a.push_back(90);
	b = s->twoSum(a, 0);
	return 0;
}
