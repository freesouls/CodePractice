class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &wordDict) 
	{
		vector<string> rs;
		string tmp;
		vector<vector<int> > tbl = genTable(s, wordDict);
		word(rs, tmp, s, tbl, wordDict);
		return rs;
	}
	void word(vector<string> &rs, string &tmp, string &s, vector<vector<int> > &tbl,
		unordered_set<string> &dict, int start=0)
	{
		if (start == s.length())
		{
			rs.push_back(tmp);
			return;
		}
		for (int i = 0; i < tbl[start].size(); i++)
		{
			string t = s.substr(start, tbl[start][i]-start+1);
			if (!tmp.empty()) tmp.push_back(' ');
			tmp.append(t);
			word(rs, tmp, s, tbl, dict, tbl[start][i]+1);
			while (!tmp.empty() && tmp.back() != ' ') tmp.pop_back();//tmp.empty()
			if (!tmp.empty()) tmp.pop_back();
		}
	}
	vector<vector<int> > genTable(string &s, unordered_set<string> &dict)
	{
		int n = s.length();
		vector<vector<int> > tbl(n);
		for (int i = n - 1; i >= 0; i--)
		{
			if(dict.count(s.substr(i))) tbl[i].push_back(n-1);
		}
		for (int i = n - 2; i >= 0; i--)
		{
			if (!tbl[i+1].empty())//if we can break i->n
			{
				for (int j = i, d = 1; j >= 0 ; j--, d++)
				{
					if (dict.count(s.substr(j, d))) tbl[j].push_back(i);
				}
			}
		}
		return tbl;
	}
};