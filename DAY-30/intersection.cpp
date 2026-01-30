#include<iostream>
#include<vector>
using namespace std;

void intersect(vector<int>& arr1,vector<int>&arr2)
{
    int i=0,j=0;
    while (i<arr1.size() && j<arr2.size())
    {
        if(i>0 && arr1[i]==arr1[i-1])
        {
            i++;
            continue;
        }
        else if(arr1[i]>arr2[j])
        {
            j++;
        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else{
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }
}
int main()
{
    vector<int>arr1={1,2,3,4,5};
    vector<int>arr2={1,2,3,6,7};
    intersect(arr1,arr2);
    return 0;
}