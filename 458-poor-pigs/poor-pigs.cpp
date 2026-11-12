class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        
        if(buckets == 1)   // only 1 bucket then it's the poisonous one;
        return 0;

        int trials = minutesToTest / minutesToDie;

        int pigs = 1;

        while(pow(trials + 1, pigs) < buckets)
        pigs++;

        return pigs;
    }
};