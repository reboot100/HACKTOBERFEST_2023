//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution{
    public:
        
        void solve (int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis,int di[],int dj[]){
            if(i==n-1 && j==n-1){ // this is destination 
                ans.push_back(move); // if reached push move into ans
                return; // ans return
            }
            
    // // INSTEAD OF USING 4 LOOPS WE CAN CONVERT IT INTO A SINGLE LOOP
    
    //         //Downward
    //         if(i+1<n && !vis[i+1][j] && a[i+1][j]==1){
    //             // (is inside boundary && is not visited && path not blocked)
    //             vis[i][j]=1; // then mark it visited
    //             solve (i+1,j,a,n,ans,move+'D',vis); // run recursion call
    //             vis[i][j]=0; // after call completion remove mark
    //         }
            
    //         //Left
    //         if(j-1>=0 && !vis[i][j-1] && a[i][j-1]==1){
    //             vis[i][j]=1;
    //             solve(i,j-1,a,n,ans,move+'L',vis);
    //             vis[i][j]=0;
    //         }
            
    //         // Right
    //         if(j+1<n && !vis[i][j+1] && a[i][j+1]==1){
    //             vis[i][j]=1;
    //              solve (i,j+1,a,n,ans,move+'R',vis);
    //              vis[i][j]=0;
    //         }
            
    //         // Upwards
    //         if(i-1>=0 && !vis[i-1][j] && a[i-1][j]==1){
    //             vis[i][j]=1;
    //             solve(i-1,j,a,n,ans,move+'U',vis);
    //             vis[i][j]=0;
    //         }
            
            //SINGLE LOOP INCOMING aaaaaaaaaaaaa
            
            string dir = "DLRU";
            for(int ind = 0; ind<4 ; ind++){
                int nexti = i+di[ind];
                int nextj = j+dj[ind];
                if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && !vis[nexti][nextj] && a[nexti][nextj]==1){
                    vis[i][j]=1;
                    solve(nexti, nextj, a,n,ans,move+dir[ind],vis,di,dj);
                    vis[i][j]=0;
                }
            }
            
        }
        
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans; // this to store the ans string at each level
        vector<vector<int>> vis (n, vector<int> (n,0)); //nXn vector it is
        
        // ADDING NEW CODE
        int di[]={+1,0,0,-1};
        int dj[]={0,-1,1,0};
        
        if(m[0][0]==1) solve(0,0,m,n,ans,"",vis,di,dj); // if path open run solve function
        return ans; // return ans 
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
