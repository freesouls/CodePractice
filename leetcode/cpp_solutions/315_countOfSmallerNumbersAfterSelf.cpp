class Node {
public:
    int value;
    int index;
    Node(int val, int ind): value(val), index(ind) {};
    
};

class Solution {
public:
    vector<Node* > arr;
    vector<Node* > tmp;
public:
    vector<int> countSmaller(vector<int>& nums) {
        arr.clear();
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(new Node(nums[i], i));
        }
        tmp.resize(nums.size(), NULL);
        vector<int> res(nums.size(), 0);
        merge_sort(res, 0, nums.size() - 1);
        return res;
    }
    
    void merge_sort(vector<int>& res, int start, int end) {
        if (start>= end) {
            return;
        }
        int mid = (start + end)/2;
        if (mid - start >= 1) {
            merge_sort(res, start, mid);
        }
        if (end - (mid + 1) >= 1) {
            merge_sort(res, mid+1, end);
        }
        int i = start;
        int j = mid + 1;
        
        // vector<Node* > tmp(end - start + 1, NULL);
        int p = 0;
        while(i <= mid && j <= end) {
            if (arr[i]->value <= arr[j]->value) {
                res[arr[i]->index] += j - (mid + 1);
                tmp[p++] = arr[i++];
                // tmp.push_back(arr[i]);
                // i++;
            }
            else {
                tmp[p++] = arr[j++];
                // tmp.push_back(arr[j]);
                // j++;
            }
        }
        
        while(i <= mid) {
            res[arr[i]->index] += j - (mid + 1);
            // tmp.push_back(arr[i]);
            tmp[p++] = arr[i++];
            // i++;
        }
        
        while(j <= end) {
            // tmp.push_back(arr[j]);
            tmp[p++] = arr[j++];
            // j++;
        }
        
        for (int i = start; i <= end; i++) {
            arr[i] = tmp[i-start];
        }
    }
};


class Node {
public:
    int value;
    int index;
    Node(int val, int ind): value(val), index(ind) {};
    
};

class Solution {
public:
    vector<Node* > arr;
public:
    vector<int> countSmaller(vector<int>& nums) {
        arr.clear();
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(new Node(nums[i], i));
        }
        
        vector<int> res(nums.size(), 0);
        merge_sort(res, 0, nums.size() - 1);
        return res;
    }
    
    void merge_sort(vector<int>& res, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = (start + end)/2;
        merge_sort(res, start, mid);
        merge_sort(res, mid+1, end);
        int i = start;
        int j = mid + 1;
        
        vector<Node* > tmp(end - start + 1, NULL);
        int p = 0;
        while(i <= mid && j <= end) {
            if (arr[i]->value <= arr[j]->value) {
                res[arr[i]->index] += j - (mid + 1);
                tmp.push_back(arr[i]);
                i++;
            }
            else {
                tmp.push_back(arr[j]);
                j++;
            }
        }
        
        while(i <= mid) {
            res[arr[i]->index] += j - (mid + 1);
            tmp.push_back(arr[i]);
            i++;
        }
        
        while(j <= end) {
            tmp.push_back(arr[j]);
            j++;
        }
        
        for (int i = start; i <= end; i++) {
            arr[i] = tmp[i-start];
        }
    }
};