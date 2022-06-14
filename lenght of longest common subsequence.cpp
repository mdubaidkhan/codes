/*leetcode template*/

class Solution {
public:
    vector<vector<int>> vec;
    
    void make_matrix(string s1,string s2){
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                    vec[i][j]=vec[i-1][j-1]+1;
                }
                else{
                vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
                }
            }
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
       vec=vector<vector<int>>(n+1,vector<int>(m+1,0));
        make_matrix(text1,text2);
        
        return vec[n][m];
    }
};
