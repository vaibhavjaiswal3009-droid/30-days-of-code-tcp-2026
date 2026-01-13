#include<iostream>
#include<vector>
using namespace std;

int miniEatingSpeed(vector<int>& arr, int h)
{
    int low=1;
    int high=arr[0];
    for(int i:arr)
    {
        if(high<i)
        {
            high=i;
        }
    }
    int res=high;

    while(low<=high)
    {
        int k=low+(high-low)/2;

        long long total_time=0;

        for(int i:arr)
        {
            total_time+=(i+k-1)/k;
        }
        if(total_time<=h)
        {
            res=k;
            high=k-1;
        }
        else{
            low=k+1;
        }
    }
    return res;
}
int main(){
    int size;
    cout<<"Enter the size of piles: ";
    cin>>size;
    vector<int>arr;
    if(size>0)
    {
        cout<<"Enter the array: ";
        for(int i=0;i<size;i++)
        {
            int element;
            cin>>element;
            arr.push_back(element);
        }
    }
    int h;
    cout<<"Enter the number of hours the guard will be gone: ";
    cin>>h;
    int res=miniEatingSpeed(arr,h);
    cout<<"the minimum integer to eat all bananas in "<<h<<" hours is "<<res;
    return 0;
}