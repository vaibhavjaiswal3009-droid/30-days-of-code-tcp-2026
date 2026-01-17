#include<iostream>
using namespace std;

long long MOD=1e9+7;

long long expo(long long base, long long power)
{
    long long res=1;
    base=base%MOD;

    while(power>0)
    {
        if(power%2==1)
        {
            res=(res*base)%MOD;
        }
        base=(base*base)%MOD;
        power/=2;
    }
    return res%MOD;
}
int main()
{
    long long n;
    cout<<"Enter the number: ";
    cin>>n;

    long long even=(n-(n/2));
    long long odd=(n/2);
    long long res=(expo(5,even)*expo(4,odd))%MOD;
    cout<<res;
    return 0;
}