class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start=*max_element(weights.begin(),weights.end());
        int end=accumulate(weights.begin(),weights.end(),0);
        int result=0;
        while(start<=end){
            int cntdays=1;
            int load=0;
            int mid=start+(end-start)/2;
            for(int i=0;i<weights.size();i++){
                if(load+weights[i]>mid){
                    load=weights[i];
                    cntdays++;
                }else{
                    load=load+weights[i];
                }
            }
            if(cntdays<=days){
                result=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return result;
    }
};
