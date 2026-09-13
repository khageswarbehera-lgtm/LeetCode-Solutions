class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        vector<pair<int,int>> A, B;
        
        // Store coordinates of all 1s
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(img1[i][j] == 1)
                    A.push_back({i, j});
                
                if(img2[i][j] == 1)
                    B.push_back({i, j});
            }
        }
        
        unordered_map<string, int> mp;
        int ans = 0;
        
        // Difference between coordinates represents a shift
        for(auto a : A) {
            for(auto b : B) {
                int dx = a.first - b.first;
                int dy = a.second - b.second;
                
                string key = to_string(dx) + "," + to_string(dy);
                mp[key]++;
                
                ans = max(ans, mp[key]);
            }
        }
        
        return ans;
    }
};