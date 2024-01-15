class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>vis1;
        map<int,int>vis2;
        set<int>se;
        for(int i=0;i<matches.size();i++){
            vis1[matches[i][0]]=1;
            vis2[matches[i][1]]+=1;
            se.insert(matches[i][0]);
            se.insert(matches[i][1]);
        }
    vector<int>res1;
    vector<int>res2;
    vector<vector<int>>answers(2);
    for(auto v:se){
        if(vis2[v]==0){
            res1.push_back(v);
        }
    if(vis2[v]==1){
            res2.push_back(v);
        }
    }
    answers[0]=res1;
    answers[1]=res2;
    return answers;
    }
};