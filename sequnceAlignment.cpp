#include <iostream>
#include <string>
#include <vector>
using namespace std;

int alignment(const string &x, const string &y, int i, int j, vector<vector<int>> &dp){
    const int gap = 2;
    const int mismatch = 3;
    if(i == 0) return j*gap;
    if(j == 0) return i*gap;
    if(dp[i][j] != -1) return dp[i][j];
    if(x[i-1]==y[j-1]){
        dp[i][j]= alignment(x,y,i-1,j-1,dp);
    }
    else{
        int a = mismatch+ alignment(x,y,i-1, j-1,dp);
        int b = gap + alignment(x,y,i-1,j,dp);
        int c = gap + alignment(x,y,i,j-1,dp);
        dp[i][j]= min(a, min(b,c));
    }
    return dp[i][j];
}
int main(){
    string x = "hello";
    string y = "hxllo";
    int len_x = x.length();
    int len_y = y.length();
    vector<vector<int>>dp(len_x+1, vector<int>(len_y+1, -1));
    cout<<"the cost is: "<<alignment(x,y, len_x,len_y,dp)<<endl;
    return 0;
}