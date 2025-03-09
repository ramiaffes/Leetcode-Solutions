class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        vector<int>vect;
        for(auto v:colors)vect.push_back(v);
        for(auto v:colors)vect.push_back(v);
        int res=0;
        int i=0;
        int j=0;
        while(j<(colors.size()+k-2)){
            if(vect[j]!=vect[j+1]){j++;}
            else{j++;i=j;}
            if(j==(i+k-1)){
                res++;
                i++;
            }
            
        }
        return res;

        
    }
};