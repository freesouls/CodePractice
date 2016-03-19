/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    /*
    将所有区间的start与end放在一起排序，但是要标记其是属性，然后统一排序，问题就转化成了括号匹配嵌套的问题了(最大有多少层括号嵌套，比如说((()))就是一个3层嵌套，()(()))最大嵌套是2)，这里start相当于左括号，end相当于右括号，只要用一个cnt来记录，遇到start就加1，遇到end就减1，记录过程中的最大值就是答案。
    */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        vector<pair<int, int>> container;

        for (int i = 0; i < airplanes.size(); i++) {
            container.push_back(make_pair(airplanes[i].start, 1));
            container.push_back(make_pair(airplanes[i].end, 0));
        }
        std::sort(container.begin(), container.end());

        int cnt = 0;
        int res = 0;
        for (int i = 0; i < container.size(); i++) {
            if (container[i].second) {
                cnt++;
            }
            else{
                cnt--;
            }
            res = std::max(res, cnt);
        }
        return res;
    }
};
