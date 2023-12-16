//Question Link
// https://leetcode.com/problems/find-eventual-safe-states/?envType=list&envId=pnz711or


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>outdegree;
        queue<int>q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<graph[i].size();j++){
                mp[graph[i][j]].push_back(i);
            }
            outdegree[i] = graph[i].size();
            if(outdegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>res;
        vector<int>safe(n,0);

        while(!q.empty()){
            auto t = q.front();
            q.pop();
            safe[t] = 1;

            for(auto x:mp[t]){
                outdegree[x]--;
                if(outdegree[x] == 0){
                    q.push(x);
                }
            }
        }

        for(int i = 0;i<n;i++){
            if(safe[i] == 1){
                res.push_back(i);
            }
        }

        return res;
    }
};