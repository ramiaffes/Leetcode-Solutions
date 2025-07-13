class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int val=0;
        int som=0;
        for(int i=0;i<players.size();i++){
            while((val<trainers.size())and(players[i]>trainers[val])){
                val++;
            }
        if(val<trainers.size()){som++;val++;}
        }
    return som;
    }
};