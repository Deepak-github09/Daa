#include <iostream>
#include <string>
#include <vector>
using namespace std;

int alignment(const string &x, const string &y){
    const int gap = 2;
    const int mismatch = 3;
    int len_x = x.length();
    int len_y = y.length();
    vector<vector<int>> dp(len_x+1, vector<int>(len_y +1, 0));
    for (int i = 0; i<=len_x; ++i)
    {
        dp[i][0] = i*gap;
    }    
    for (int j = 0; j<=len_y; ++j)
    {
        dp[0][j] = j*gap;
    }

    for (int i = 1; i<=len_x; ++i){
        for(int j = 1; j<=len_y; ++j){
            if(x[i-1]==y[j-1]){
                dp[i][j]= dp[i-1][j-1];
            }
            else{
                int a = mismatch+ dp[i-1][j-1];
                int b = gap + dp[i-1][j];
                int c = gap + dp[i][j-1];
                dp[i][j]= min(a, min(b,c));
                }
        }
    }
    
    return dp[len_x][len_y];
}
int main(){
    string x = "hello";
    string y = "hxllo";
    cout<<"the cost is: "<<alignment(x,y)<<endl;
    return 0;
}