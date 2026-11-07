class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> freeServer;

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > busy;

        int n = servers.size();

        for(int i = 0; i < n; i++)
            freeServer.push({servers[i], i});

        vector<int> ans;
        long long time = 0;

        for(int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            while(!busy.empty() && get<0>(busy.top()) <= time) {
                auto [t,w,idx] = busy.top();
                busy.pop();
                freeServer.push({w, idx});
            }

            if(freeServer.empty()) {
                time = get<0>(busy.top());

                while(!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [t,w,idx] = busy.top();
                    busy.pop();
                    freeServer.push({w, idx});
                }
            }

            auto [w, idx] = freeServer.top();
            freeServer.pop();

            ans.push_back(idx);

            busy.push({time + tasks[i], w, idx});
        }

        return ans;
    }
};