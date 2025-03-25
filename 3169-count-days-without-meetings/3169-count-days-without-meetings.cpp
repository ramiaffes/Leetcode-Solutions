class Solution {
public:
 
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        
        int som=0;
        int min2=1e9;
        int ans=0;
        for(int i=0;i<(meetings.size()-1);i++){ 
          if((meetings[i+1][0]>ans)and(meetings[i][1]<ans)){
                som+=meetings[i+1][0]-ans-1;
            }
            else if((meetings[i+1][0]<=ans)){
                som+=0;
            }

            else if(meetings[i+1][0]>meetings[i][1]){

    
                som+=meetings[i+1][0]-meetings[i][1]-1;
            }
            ans=max(ans,meetings[i][1]);
            min2=min(min2,meetings[i][0]);
           
           
        }ans=max(ans,meetings[meetings.size()-1][1]);min2=min(min2,meetings[0][0]);
        return som+days-ans+min2-1;
    

    }
};