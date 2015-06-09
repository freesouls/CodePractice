class Solution {
public:
    int countPrimes(int n) {
        bool *tag = new bool[n];
        int *prime = new int[n];
        int cnt = 0;
        memset(tag, true, sizeof(bool) * n);
        for (int i = 2; i < n; ++i) {
            if (tag[i]) prime[cnt++] = i;
            for (int j = 0; j < cnt && i * prime[j] < n; ++j) {
                tag[i * prime[j]] = false;
                if (i % prime[j] == 0) break;
            }
        }
        delete [] tag;
        delete [] prime;
        return cnt;
    }


    // vector<int> dic;
    // int countPrimes(int n) {
    //     if (n < 3){
    //         return 0;
    //     }
    //     if ( n < 4){
    //         return 1;
    //     }
    //     if ( n < 6){
    //         return 2;
    //     }
    //     if ( n < 8){
    //         return 3;
    //     }
    //     if ( n < 12){
    //         return 4;
    //     }
    //     //dic.reserve(n/2);
    //     dic.push_back(2);
    //     dic.push_back(3);
    //     dic.push_back(5);
    //     dic.push_back(7);
    //     dic.push_back(11);
    //     int count = 5;
    //     for (int i = 13; i < n; i = i+2){
    //         int root = sqrt(i);
    //         int s = dic.size();
    //         bool flag = false;
            
    //         for (int j = 1; dic[j] <= root && j < s; ++j){
    //             if (i % dic[j] == 0){
    //                 flag = true;
    //                 break;
    //             }
    //         }
    //         if (!flag){
    //             count++;
    //             dic.push_back(i);
    //         }
    //     }
    //     return count;
    // }
    
    // int sqrt(int x) {
    //     int left = 1, right = x / 2;
    //     int last_mid; // 记录最近一次 mid
    //     //if (x < 2) return x;
    //     while(left <= right) {
    //         int mid = left + (right - left) / 2;
    //         if(x/mid>mid){ // 不要用 x>mid*mid,会溢出
    //             left = mid + 1;
    //             last_mid = mid;
    //         } else if(x / mid < mid) {
    //             right = mid - 1;
    //         } else {
    //             return mid;
    //         }
    //     }
    //     return last_mid;
    // }
};