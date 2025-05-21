#include <bits/stdc++.h>

using namespace std;

void quick_sort(vector<int>& n,int l,int r) {
	if(l>=r)return;
	int i=l;
	int j=r;
	int p=n[(l+r)/2];
	while(i<=j){
		while(n[i]<p)i++;
		while(n[j]>p)j--;
		if(i<=j){
			swap(n[i],n[j]);
			i++;
			j--;
		}
	}
	if(l<j)quick_sort(n,l,j);
	if(i<r)quick_sort(n,i,r);
}

int main(){
     int n;cin>>n;
     vector<int> nums;
     for(int i=0;i<n;++i){
          int k;cin>>k;
          nums.emplace_back(k);
     }
     quick_sort(nums,0, nums.size()-1);
     for(auto v:nums){
          cout<<v<<" ";
     }
     return 0;
}