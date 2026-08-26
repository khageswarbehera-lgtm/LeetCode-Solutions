class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftmax=0;
        int rightmax=height.size()-1;
        int area=0;
        while(leftmax<rightmax)
        {
            int currarea=min(height[leftmax],height[rightmax])*(rightmax-leftmax);
           if(height[leftmax]<height[rightmax])
           {
            leftmax++;
           }
           else
           rightmax--;
           area=max(area,currarea);
        }
        return area;
        
    }
};