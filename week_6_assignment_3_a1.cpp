//leetcode soloution for the question 

class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int m = a.size();
        int n = a[0].size();
        if (m == 0) return; // Handle empty matrix case
        bool zeroRow = false;//no zero in row
        bool zeroCol = false;//no zero in coloumn
        //checking first row for any zeroes
        for(int j =0; j<n; j++){
            if(a[0][j]==0) {zeroRow = true;
            break;}
        }
        //checking first col for any zeroes
        for(int i =0; i<m; i++){
            if(a[i][0]==0) {zeroCol = true;
            break;}
        }

        //traverse from a[1][1] to a[m][n]
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(a[i][j]==0){
                    a[i][0]=0;
                    a[0][j]=0;
                }
            }
        }
        //traverse in 0th row:-->> and populate coloumns
        for(int j=1; j<n; j++){
            if (a[0][j] == 0){
                for(int i=1; i<m; i++){
                    a[i][j]=0;
                }
            }
        }
        //traverse in 0th coloumn and populate rows
        for(int i =1; i<m; i++){
            if(a[i][0]==0){
                for(int j=1;j<n;j++){
                    a[i][j]=0;
                }
            }
        }

        //if zerocol is zero;
        if(zeroCol==true){
            for(int i =0; i<m; i++){
                a[i][0] = 0;
            }
        }
        //if zeroRow is zero;
        if(zeroRow==true){
            for(int j =0; j<n; j++){
                a[0][j] = 0;
            }
        }


        return;
    }
};