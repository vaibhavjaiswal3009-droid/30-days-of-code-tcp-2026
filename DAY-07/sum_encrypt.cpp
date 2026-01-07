#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int number(int numb)
 {
        int maxDigit = 0;
        int count = 0;
        int temp = numb;
        while (temp > 0) 
        {
            maxDigit = max(maxDigit, temp % 10);
            temp /= 10;
            count++;
        }
        int  new_num = 0;
        for (int i = 0; i < count; i++) 
        {
            new_num = new_num * 10 + maxDigit;
        }
        return new_num;    
}
int sumOfEncryptedInt(vector<int>& nums)
{
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
             sum+=number(nums[i]);
        }
          return sum;
        
}
int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    vector<int>nums(size);
    if(size>0)
    {
        for(int i=0;i<size;i++)
        {
            cout<<"Enter the element at index "<<i<<" : ";
            cin>>nums[i];
        }
    }
    int res=sumOfEncryptedInt(nums);
    cout<<"The sum of the encrypted integers is "<<res;
    return 0;
}
