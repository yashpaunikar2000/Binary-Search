class Solution {
  public:
  int solve(vector<int>&arr,int mid,int k){
    int bouquets=0,cnt=0;
    for(int i=0;i<arr.size();i++){
        if(mid>=arr[i]){
            cnt++;
        }else{
            cnt=0;
        }
        if(cnt==k){
            bouquets++;
            cnt=0;
        }
    }
    return bouquets;
  }
    int minDaysBloom(int m, int k, vector<int> &arr) {
        int s=1;
        int e=*max_element(arr.begin(),arr.end());
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int result=solve(arr,mid,k);
            if(result>=m){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};
