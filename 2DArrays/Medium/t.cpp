//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public:
    int r,c;
    bool isInBounds(vector<vector<int>> &matrix,int i,int j)
    {
       
        if(i<0 || i>=matrix[0].size() || j<0 || j>=matrix.size()) return false;
        
        return true;
    }
    
    bool isBlocked(vector<vector<int>> &matrix,int i ,int j)
    {
        if(!isInBounds(matrix,i,j)) return true;
        if(matrix[i][j] ==-1) return true;
        
        return false;
    }
    
    void spirallyDFS(vector<vector<int> > &matrix ,int i,int j,int dir, vector<int> &res)
    {
        if(isBlocked(matrix,i,j)) return ;
        
        bool allBlocked = true;
        
        for(int k =-1;k<=1;k+=2)
        {
            allBlocked = allBlocked && isBlocked(matrix,i+k,j) && isBlocked(matrix, i ,j+k);
        }
        res.push_back(matrix[i][j]);
        matrix[i][j]=-1;
        
        if(allBlocked) return;
        
        int nxt_i = i, nxt_j=j,nxt_dir =dir;
        
        if(dir ==0)
        {
            if(!isBlocked(matrix, i, j+1)) nxt_j++;
            else
            {
                nxt_dir =1;
                nxt_i++;
            }
        }
        else if(dir ==1)
        {
            if(!isBlocked(matrix, i+1, j)) nxt_i++;
            else
            {
                nxt_dir =2;
                nxt_j--;
            }
        }
        else if(dir ==2)
        {
            if(!isBlocked(matrix, i, j-1)) nxt_j--;
            else
            {
                nxt_dir =3;
                nxt_i--;
            }
        }
        else if(dir ==3)
        {
            if(!isBlocked(matrix, i-1, j)) nxt_i--;
            else
            {
                nxt_dir =0;
                nxt_j++;
            }
        }
        
        spirallyDFS(matrix, nxt_i,nxt_j,nxt_dir,res);
    }
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) 
    {
        // code here
        vector<int> res;
        spirallyDFS(matrix, 0, 0, 0, res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t=3;
    // cin>>t;
    
     while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends