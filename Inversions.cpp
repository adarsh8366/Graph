#include<vector>
long long merge(long long *arr,int left,int mid,int right) {
    int sz1 = mid-left+1;
    int sz2 = right-mid;
    
    vector<long long> temp1(sz1);
    vector<long long> temp2(sz2);
    
    int ct = 0;
    for(int i=left;i<=mid;++i) {
        temp1[ct++] = arr[i];
    }
    ct = 0;
    for(int i=mid+1;i<=right;++i) {
        temp2[ct++] = arr[i]; 
    }
    ct = left;
    int i = 0, j =0;
    long long ans = 0;
    while(i<sz1 and j<sz2) {
        if(temp1[i]<=temp2[j]) {
            arr[ct++] = temp1[i++];
        } else {
            ans += sz1-i;
            arr[ct++] = temp2[j++]; 
        }
    }
    
    while(i<sz1) {
        arr[ct++] = temp1[i++];
    } 
    
    while(j<sz2) {
        arr[ct++] = temp2[j++];
    }
    return ans;
}
long long mergeSort(long long *arr,int left,int right) {
	long long ans = 0;
    if(left<right) {
        int mid = left + (right-left)/2;
        ans += mergeSort(arr,left,mid);
        ans += mergeSort(arr,mid+1,right);
        ans += merge(arr,left,mid,right);
    }
    
    return ans;
}
long long getInversions(long long *arr, int n){
    return mergeSort(arr,0,n-1);
}
