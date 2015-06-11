class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string result;
        if(numerator<0 ^ denominator<0 ) result+='-';
        long long int n=numerator,d=denominator;// overflow
        n=abs(n);d=abs(d);              
        
        result+=to_string(n/d);
        long long int r=n%d;
        if(r==0) return result;
        else result+='.';
        unordered_map<int,int> map;
        while(r){
            // for integer divide, once the remainder start repeating, it means it is recurring
            // while for real number it is not the case: 0.44 / 3 = 0.113333,
            // 1 start repeating but it is not the right recurring number
            if(map.find(r)!=map.end()){
                result.insert(map[r],1,'(');   
                result+=')';
                break;
            }
            map[r]=result.size();
            r*=10;
            result+=to_string(r/d);
            r=r%d;
        }
        return result;
    }
};