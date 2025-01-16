class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int>vect1;
        int p=x;
        vect1.push_back(1);
        while(p<=bound){if(x==1)break;
            vect1.push_back(p);
            
            p*=x;
        }
        vector<int>vect2;
         p=y;
        vect2.push_back(1);
        while(p<=bound){if(y==1)break;
            vect2.push_back(p);
            p*=y;
        }
        vector<int>res;
        map<int,bool>vis;
        for(int i=0;i<vect1.size();i++){
            for(int j=0;j<vect2.size();j++){
                if((vis[vect1[i]+vect2[j]]==0)and((vect1[i]+vect2[j])<=bound))res.push_back(vect1[i]+vect2[j]);
                vis[vect1[i]+vect2[j]]=1;

            }
        }
        return res;



    }
};