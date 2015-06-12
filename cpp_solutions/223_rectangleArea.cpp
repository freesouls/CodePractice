class Solution {
public:
    // explain http://www.programcreek.com/2014/06/leetcode-rectangle-area-java/
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (D - B)*(C - A) + (G - E)*(H - F);
        if (C <= E || G <= A){
            return area;
        }
        
        if (H <= B || D <= F){
            return area;
        }
        
        int left = max(A, E);
        int right = min(C, G);
        int top = min(D, H);
        int bottom = max(B, F);
        
        return area - (right - left)*(top - bottom);
    }
};