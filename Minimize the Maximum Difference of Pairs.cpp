class Solution {
public:
    bool solve(vector<int>&nums,int mid,int p){
        int i=0,count=0;
        int n=nums.size();
        while(i<n-1){
            if(nums[i+1]-nums[i]<=mid){
                count++;
                i+=2;
            }else{
                i++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int start=0;
        int n=nums.size();
        int ans=INT_MAX;
        sort(begin(nums),end(nums));
        int end=nums[n-1]-nums[0];
        while(start<=end){
            int mid=start+(end-start)/2;
            if(solve(nums,mid,p)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};
