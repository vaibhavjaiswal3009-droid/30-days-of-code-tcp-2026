#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findMinPath(vector<vector<int>> &V, int r, int c)
 {
    int R = V.size();
    int C = V[0].size();
    if (r >= R || c >= C) return 100000000;  
    if (r == R - 1 && c == C - 1) return V[r][c]; 
    return V[r][c] + min(findMinPath(V, r + 1, c), findMinPath(V, r, c + 1));
}

int main() 
{    
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Min Path Sum: " << findMinPath(grid, 0, 0) << endl;
    return 0;
}