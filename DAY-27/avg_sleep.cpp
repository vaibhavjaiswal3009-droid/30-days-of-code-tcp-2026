#include <bits/stdc++.h>
using namespace std;

long long res(const vector<int>&arr,int k)
{
     
    long long  curr_sum=0;
    for(int i=0;i<k;i++)
    {
        curr_sum+=arr[i];
    }
    long long  sum=curr_sum;
    
    
    for(size_t i=k;i<arr.size();i++)
    {
        curr_sum+=arr[i]-arr[i-k];
        sum+=curr_sum;
    }
    return sum;
}
int main()
{
    
    int size;
    
     int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    double win=(n-k+1);
    double final_sum=res(arr,k);
     
     
    cout<<fixed<<setprecision(10)<<final_sum/win;
    return 0;
    
}