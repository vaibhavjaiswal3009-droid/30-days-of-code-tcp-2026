#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int first(vector<int>& arr, int target)
{
     int n=arr.size();
     int low=0;
     int high=n-1;
     while(low<=high)
     {
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            if(mid==0 || arr[mid-1]!=target)
            {
                return mid;
            }
            else{
                high=mid-1;
            }
        }
        else if(arr[mid]>target)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
     }
     return -1;
}
int last(vector<int>& arr, int target)
{
     int n=arr.size();
     int low=0;
     int high=n-1;
     while (low<=high)
     {
        int mid=low+(high-low)/2;
        if(arr[mid]==target)
        {
            if(mid==n-1 || arr[mid+1]!=target){
                return mid;
            }
            else{
                low=mid+1;
            }
        }
        else if(arr[mid]>target)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
     }
     return -1;
     
}
vector<int>position(vector<int>& arr, int target)
{
     int res1=first(arr,target);
    int res2=last(arr,target);
    return {res1,res2};
}
int main()
{
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    vector<int>arr;
    if(size>0)
    {
        cout<<"Enter the elements of the array: ";
        for(int i=0;i<size;i++)
        {
            int val;
            cin>>val;
            arr.push_back(val);
        }
    }
     
    int target;
    cout<<"Enter the element : ";
    cin>>target;
    vector<int>res=position(arr,target);
    cout<<"The index of "<<target<<" : "<<res[0]<<" and "<<res[1];
    
   return 0;

}