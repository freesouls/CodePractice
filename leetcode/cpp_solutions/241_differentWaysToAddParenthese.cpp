// TODO: non-recursive if possible
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if (input.size() == 0){
            return res;
        }

        vector<int> nums;
        vector<char> ops;

        for (int i = 0; i < input.size(); i++){
            if (input[i] >= '0' && input[i] <= '9'){
                int tmp = 0;
                while(input[i] >= '0' && input[i] <= '9'){
                    tmp = tmp*10 + input[i] - '0';
                    i++;
                }
                i--;
                nums.push_back(tmp);
            }
            // else if(input[i] == '+'){
            //     ops.push_back(0);
            // }
            // else if(input[i] == '-'){
            //     ops.push_back(1);
            // }
            else{
                ops.push_back(input[i]); // *
            }
        }
        return getVec(nums, ops, 0, nums.size() - 1);
    }



    // f(N), N is the number of nums, f(N) is the total possible Results
    // f(N) = f(1)*f(N-1) + f(2)*f(N-2) + ... + f(N-1)*f(1)
    vector<int> getVec(vector<int>& nums, vector<char>& ops, int s, int e){
        vector<int> res;
        if (s == e){
            res.push_back(nums[e]);
            return res;
        }

        for (int i = s; i < e; i++){
            vector<int> a = getVec(nums, ops, s, i);
            vector<int> b = getVec(nums, ops, i + 1, e);
            for (int j = 0; j < a.size(); j++){
                for (int k = 0; k < b.size(); k++){
                    if (ops[i] == '+'){
                        res.push_back(a[j]+b[k]);
                    }
                    else if (ops[i] == '-'){
                        res.push_back(a[j]-b[k]);
                    }
                    else{
                        res.push_back(a[j]*b[k]);
                    }
                }
            }
        }
        return res;
    }
};
