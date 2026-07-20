class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        while(left < right){
            int width = right - left;
            int currArea = min(height[left],height[right]) * (right - left);
            area = max(area,currArea);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right --;
            }
        }
        return area;
    }
};