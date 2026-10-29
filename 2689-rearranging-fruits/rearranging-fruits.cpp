class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        
        unordered_map<int,int>freq;
        int minEl = INT_MAX;

        for(auto &x : basket1)
        {
            freq[x]++;
            minEl = min(minEl,x);
        }

        for(auto &x : basket2)
        {
            freq[x]--;
            minEl = min(minEl,x);
        }
        

        vector<int>extra;

        for(auto x : freq)
        {
            int elem = x.first;
            int freq = x.second;

            if(freq == 0)
            continue;

            if(freq % 2 != 0)
            return -1;

            for(int i = 0 ;i< abs(freq) / 2 ; i++)
            extra.push_back(elem);
        }

        sort(extra.begin(),extra.end());
        
        long long ans = 0;
        for(int i = 0 ;i < extra.size() / 2 ; i++)
        {
         ans += min(extra[i] , 2 * minEl);
        }

        return ans;
    }
};