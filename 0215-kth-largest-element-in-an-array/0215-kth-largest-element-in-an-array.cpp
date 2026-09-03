class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int ans;
        priority_queue<int>pq(nums.begin(),nums.end());
        while(k>0)
        {
            ans=pq.top();
            pq.pop();
            k--;
        }
        return ans;
        
    }
};