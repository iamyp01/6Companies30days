/*
Link - https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/
Author - Yuvraj Parashar
*/
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // 1st Step -> Create Graph with the given edges [prerequisites]
	    // 2nd Step -> create an indegree container and fill it
	    // 3rd step -> Create a queue and push all vertices having 0 indegree
	    // 4th Step -> pop the front and store in vector and check connected vertices list, and decrease indegree of all connected vertices by 1
	    // 5th step -> if vector size == N then it means we can do all tasks
	    
	    //-----------------------------------------------------------------------------
	    
	    // create graph [It is an directed graph]
	    vector<int> adj[N];
	    
	    // add edges to graph
	    for(auto& it : prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    
	    // calculating indegree in graph
	    vector<int> indegree(N, 0);
	    for(int i = 0; i < N; i++){
	        for(auto& it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    // It will store the tasks that will be finally completed
	    vector<int> final_tasks;
	    
	    // queue to process all indegrees and tasks
	    queue<int> q;
	    
	    // Push all tasks that don't have any prerequisites
	    for(int i = 0; i < N; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int temp = q.front();
	        q.pop();
	        final_tasks.push_back(temp);
	        // decrease indegree of all coneected vertices by 1
	        // 1 ----> 2
	        // then 1 will be done right now and so 2 will have 0 indegree now
	        for(auto& it : adj[temp]){
	            indegree[it]--;
	            // if indegree becomes 0 then push it in the queue[that is the rule to push in queue]
	            if(indegree[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    // size() means that these number of tasks can finally completed
	    return (final_tasks.size() == N);
	}
};
