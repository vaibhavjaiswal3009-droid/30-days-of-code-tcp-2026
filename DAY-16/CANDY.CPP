#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int min_candy(vector<int>& rating)
{
    int sum=0;
    int n=rating.size();
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        arr[i]=1;
    }

    for(int i=1;i<n;i++){
        if(rating[i]>rating[i-1])
        {
            arr[i]=arr[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(rating[i]>rating[i+1])
        {
            arr[i]=max(arr[i],arr[i+1]+1);
        }
    }
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    int size;;
    cout<<"Enter the size : ";
    cin>>size;
    vector<int>rating;
    if(size>0)
    {
        for(int i=0;i<size;i++)
        {
            cout<<"Element "<<i+1<<": ";
            int element;
            cin>>element;
            rating.push_back(element);
        }
    }
    cout<<"Result= "<<min_candy(rating);

}