class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int reach = startFuel;
        int stops = 0;
        priority_queue<int>pq;
        int i = 0 , n = stations.size();
        while(reach < target)
        {
            while(i<n && stations[i][0] <= reach)
            {
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty())
            return -1;

            if(!pq.empty())
            {
                reach += pq.top();
                pq.pop();
                stops++;
            }

        }

        return stops;
    }
};