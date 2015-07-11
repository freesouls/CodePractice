// TODO: a faster version, this version is two slow
class Solution {
public:
    long str2long(string s){
        long res = 0;
        for (int i=0;i<10;i++){
            if (s[i] == 'A'){res = res*10 + 1;}
            if (s[i] == 'T'){res = res*10 + 2;}
            if (s[i] == 'C'){res = res*10 + 3;}
            if (s[i] == 'G'){res = res*10 + 4;}
        }
        return res;
    }
    string long2str(long s){
        string res = "";
        for (int i=0;i<10;i++){
            int d = s%10;
            if (d == 1) {res= "A" + res;}
            if (d == 2) {res= "T" + res;}
            if (d == 3) {res= "C" + res;}
            if (d == 4) {res= "G" + res;}
            s = s /10;
        }
        return res;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        map<long, int> d;
        vector<string> res;
        for (int i=0;i<n-9;i++){
            string sub = s.substr(i,10);
            long idx = str2long(sub);
            if (d.find(idx) == d.end()){
                d[idx] = 0;
            }else{
                d[idx] = d[idx] + 1;
            }
        }
        for (auto it= d.begin();it!=d.end();it++){
            if (it->second >= 1){
                res.push_back(long2str(it->first));
            }
        }
        return res;

    }
};
