class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
            for(int i= 0;i< prerequisites.size();i++){
                int u  = prerequisites[i][0];
                int v  = prerequisites[i][1];
                
                // THe order is reverse so make sure to make this reverse
                adj[v].push_back(u);
            }
            
            // Indegree
            vector<int> indegree(numCourses);
            for(auto i:adj){
                for(auto j: i.second){
                    indegree[j]++;
                }
            }
            
            //Now in queue push 0 indegree node
            queue<int> q;
            for(int i = 0; i < numCourses;i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
            
            //Do BFS
            vector<int> ans;
            while(!q.empty()){
                int front = q.front();
                q.pop();
                
                //Answer Store
                ans.push_back(front);
                
                //neighbour indegree update
                for(auto neighbour: adj[front]){
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 0){
                        q.push(neighbour);
                    }
                }
            }
            if(ans.size() == numCourses){
                return true;
            }
            return false;
    }
};