#include<iostream>
using namespace std;
class Solution{
    public:
    int table[256];
    Solution(){
        table[0]=0;
        for(int i=1;i<256;i++)
        {
            table[i]=table[i&(i-1)]+1;
        }
    }
    int count(int n)
    {
        unsigned int num=(unsigned int)n;
        return table[num&255]+table[(num>>8)&255]+table[(num>>16)&255]+table[num>>24];
    }
};
int main(){
   int n;
   cout<<"Enter the number: ";
   cin>>n;
   Solution s1;
   cout<<"The number of set bits: "<<s1.count(n);
   return 0;
}