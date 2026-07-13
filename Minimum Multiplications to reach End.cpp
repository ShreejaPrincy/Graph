// Time Complexity:
// O(1000 * N)
// where N = arr.size().
// There are only 1000 possible states (0 to 999),
// and for each state we try all N multipliers.

// Space Complexity:
// O(1000)
// O(1000) for the distance array
// and O(1000) in the worst case for the queue.

class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        int mod=1000;
        
        queue<pair<int,int>>q;
        q.push({0,start});
        
        vector<int>dist(1000,INT_MAX);
        dist[start]=0;
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            int step=it.first;
            int node=it.second;
            
            if(node==end)   return step;
            
            for(int i=0;i<arr.size();i++){
                int newNode=(node*arr[i])%mod;
                
                if(step+1<dist[newNode]){
                    dist[newNode]=step+1;
                    q.push({step+1,newNode});
                }
            }
        }
        
        return -1;
    }
};
