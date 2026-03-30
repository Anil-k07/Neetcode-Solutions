class Solution {
public:

    bool check(vector<vector<char>>& board,int a,int b){
        vector<int>temp;
        for(int i = a;i<a+3;++i){
            for(int j = b;j<b+3;++j){
                if(board[i][j]!='.'){
                    temp.push_back(board[i][j]-'0');
                    //cout<<"i: "<<i<<" j: "<<j<<" : "<< board[i][j]-'0' <<"\n";
                }
            }
        }
        int n = temp.size();
        set<int>s(temp.begin(),temp.end());
        int m = s.size();
        if(n!=m)
            return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ans = true;
        vector<vector<int>>comp;
        for(int i=0;i<9;++i){
            vector<int>temp;
            for(int j=0;j<9;++j){
                if(board[i][j]!='.')
                    temp.push_back(board[i][j]-'0');
            }
            int n = temp.size();
            set<int>s(temp.begin(),temp.end());
            int m = s.size();
            if(n!=m)
                return false;
        }
        for(int i=0;i<9;++i){
            vector<int>temp;
            for(int j=0;j<9;++j){
                if(board[j][i]!='.')
                    temp.push_back(board[j][i]-'0');
            }
            int n = temp.size();
            set<int>s(temp.begin(),temp.end());
            int m = s.size();
            if(n!=m)
                return false;
        }
        for(int i=0;i<7;i+=3){
            for(int j=0;j<7;j+=3){
                ans&=check(board,i,j);
            }
        }

        return ans;
    }
};
