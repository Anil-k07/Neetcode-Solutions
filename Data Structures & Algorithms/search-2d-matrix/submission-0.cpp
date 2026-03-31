class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = n*m;
        while(l<r){
            int mid = l+(r-l)/2;
            int row = mid/m;
            int col = mid - (row*m);
            //cout<<matrix[row][col]<<"\n";
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col]>target)
                r = mid;
            else
                l = mid+1;
        }
        return false;
    }
};
