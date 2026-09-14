class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        // Check horizontal overlap
        int left = max(rec1[0], rec2[0]);
        int right = min(rec1[2], rec2[2]);
        
        // Check vertical overlap
        int bottom = max(rec1[1], rec2[1]);
        int top = min(rec1[3], rec2[3]);
        
        // Positive width AND positive height
        return left < right && bottom < top;
    }
};