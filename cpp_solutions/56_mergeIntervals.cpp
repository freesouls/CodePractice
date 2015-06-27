/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct customSort {
    inline bool operator()(Interval& a, Interval& b){
        return a.start < b.start;
    }
};

class Solution {
public:
    inline
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0){
            return res;
        }

        std::sort(intervals.begin(), intervals.end(), customSort());
        // int i = 0;
        for(int i = 0; i < intervals.size(); i++){
            Interval tmp = intervals[i];
            int j = i + 1;
            for(; j < intervals.size(); j++){
                if (tmp.end >= intervals[j].start){
                    tmp.end = std::max(intervals[j].end, tmp.end);
                }
                else{
                    break;
                }
            }
            res.push_back(tmp);
            i = j - 1;
        }

        return res;
    }
};
