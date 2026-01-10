#include<iostream>
#include<vector>
using namespace std;

void sorting(vector<int>& arr)
{
    int n=arr.size();
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            int temp=arr[mid];
            arr[mid]=arr[low];
            arr[low]=temp;
            mid++;
            low++;
        }
        else if(arr[mid]==2)
        {
            int temp=arr[mid];
            arr[mid]=arr[high];
            arr[high]=temp;
            high--;
        }
        else{
            mid++;
        }
    }
}
int main()
{
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;

    vector<int>arr(size);
    if(size>0)
    {
        cout<<"Enter the elements(0,1,2) of the array: ";
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
    }
    sorting(arr);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}