class Solution {
public:
    bool fun(int index , vector<int>&arr , vector<bool>&visited)
    {
        if(arr[index] == 0)
        return true;
        
        if(visited[index])     // agr phle pohoch chuka tha aur ab dubara aagya to false;
        return false;        

        visited[index] = true;

        bool left = (index - arr[index] >= 0) ? fun(index - arr[index] , arr , visited) : false;
        bool right = (index + arr[index] < arr.size()) ? fun(index + arr[index] , arr ,visited) : false;

        return left || right;
    }
 
    bool canReach(vector<int>& arr, int start) {
        
        //ex -> arr-> {1,1} and start = 0 ; -> without visited 
                                        //    in this case it will go to infinite recurrsion

        vector<bool>visited(arr.size(),0);                                

        return fun(start,arr,visited);
    }
};