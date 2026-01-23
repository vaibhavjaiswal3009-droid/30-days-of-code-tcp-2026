#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string frequencySort(string s) {
        vector<int>count(128,0);

        for(auto c:s)
        {
            count[c]++;
        }
        vector<pair<int,char>>freq;
        for(int i=0;i<128;i++)
        {
            if(count[i]>0)
            {
                freq.push_back({count[i],(char)i});
            }
        }
        sort(freq.rbegin(),freq.rend());

        string res="";
        for(auto &i:freq)
        {
            res.append(i.first,i.second);
        }
        return res;


    }
int main()
{
    string s="tree";
    cout<<frequencySort(s);
    return 0;
}