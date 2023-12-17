//Question Link
//https://leetcode.com/problems/find-eventual-safe-states/?envType=list&envId=pnz711or
//Solution

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        //Construct a graph that leads from destination to source
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>outdegree;  // the number of outgoing edges for each node
        queue<int>q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<graph[i].size();j++){
                mp[graph[i][j]].push_back(i);
            }
            outdegree[i] = graph[i].size();
            // When we dont have any outgoing edges, then it is in a safe state
            if(outdegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>res;

        // Keeping track of all the safe nodes.
        vector<int>safe(n,0);

        while(!q.empty()){
            auto t = q.front();
            q.pop();
            safe[t] = 1;

            for(auto x:mp[t]){
                outdegree[x]--;
                // Again if all edges are explored , hence they are all coming from the safe nodes, hence current node is also safe.
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