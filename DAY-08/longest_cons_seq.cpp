 #include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSeq(vector<int>& arr) 
{
     int longest=0;
     unordered_map<int,bool>map;
     for(int num:arr)
     {
          map[num]=false;
     }
     for(int num:arr)
     {
        if (map[num] == true) continue;
        map[num]=true;
        int currlen=1;
        int next=num+1;
        while(map.count(next) && map[next]==false)
        {
            map[next]=true;
            currlen++;
            next++;
        }
        int prev=num-1;
        while(map.count(prev) && map[prev]==false)
        {
            map[prev]=true;
            currlen++;
            prev--;
        }
        if(currlen>longest)
        {
            longest=currlen;
        }
     }
     return longest;

}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Array is empty." << endl;
        return 0;
    }

    vector<int> arr(size);
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Capture the returned vector
     int seq = longestSeq(arr);

     cout<<seq;

    return 0;
}