class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s=1;
        long long e=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(s<=e){
            long long mid=s+(e-s)/2;
            long long sumhour=0;
            for(int i=0;i<piles.size();i++){
                sumhour=sumhour+((piles[i]+mid-1)/mid);
            }
            if(sumhour<=h){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};
