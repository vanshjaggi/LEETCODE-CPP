//Concising to two line for fun
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int intersection = (bx2>ax1 && bx1<ax2 && by1<ay2 && by2>ay1)  ? (min(ay2,by2) - max(ay1,by1)) * (min(ax2,bx2) - max(ax1,bx1)) : 0 ;
        return ((abs((ax2-ax1) * (ay2-ay1)))+(abs((bx2-bx1)*(by2-by1)))-intersection);
    }
};

//More visible version
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = abs((ax2-ax1) * (ay2-ay1));
        int area2 = abs((bx2-bx1)*(by2-by1));

        int intersection = 0;
        if(bx2>ax1 && bx1<ax2 && by1<ay2 && by2>ay1){
            int width = min(ax2,bx2) - max(ax1,bx1);
            int length = min(ay2,by2) - max(ay1,by1);
            intersection = length * width;
        } 
        int total = area1+area2-intersection;
        return total;
    }
};
