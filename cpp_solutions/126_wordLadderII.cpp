// TO DO
class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        pathes.clear();
        dict.insert(start);
		dict.insert(end);
		vector<string> prev;
		unordered_map<string, vector<string> > traces;
		for (unordered_set<string>::const_iterator citr = dict.begin(); 
				citr != dict.end(); citr++) {
			traces[*citr] = prev;
		}
		
		vector<unordered_set<string> > layers(2);
		int cur = 0;
		int pre = 1;
		layers[cur].insert(start);
		while (true) {
			cur = !cur;
			pre = !pre;
			for (unordered_set<string>::const_iterator citr = layers[pre].begin();
					citr != layers[pre].end(); citr++)
				dict.erase(*citr);
			layers[cur].clear();
			for (unordered_set<string>::const_iterator citr = layers[pre].begin();
					citr != layers[pre].end(); citr++) {
				for (int n=0; n<(*citr).size(); n++) {  
                    string word = *citr;  
                    int stop = word[n] - 'a';  
                    for (int i=(stop+1)%26; i!=stop; i=(i+1)%26) {  
                        word[n] = 'a' + i;  
                        if (dict.find(word) != dict.end()) {  
                            traces[word].push_back(*citr);
    				        layers[cur].insert(word); 
                        }  
                    }
                }
			}
            if (layers[cur].size() == 0)
                return pathes;
			if (layers[cur].count(end))
				break;
		}
		vector<string> path;
		buildPath(traces, path, end);

		return pathes;
	}

	private:
		void buildPath(unordered_map<string, vector<string> > &traces, 
				vector<string> &path, const string &word) {
			if (traces[word].size() == 0) {
                path.push_back(word);
				vector<string> curPath = path;
				reverse(curPath.begin(), curPath.end());
				pathes.push_back(curPath);
                path.pop_back();
				return;
			}

			const vector<string> &prevs = traces[word];
			path.push_back(word);
			for (vector<string>::const_iterator citr = prevs.begin();
					citr != prevs.end(); citr++) {
				buildPath(traces, path, *citr);
			}
			path.pop_back();
		}

		vector<vector<string> > pathes;
};
