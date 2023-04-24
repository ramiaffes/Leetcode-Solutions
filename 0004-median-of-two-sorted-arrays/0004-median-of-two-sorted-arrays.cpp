class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int j1=nums1.size()-1;
        int j2=nums2.size()-1;
        int i1=0;
        int i2=0;
        int val1=0;
        int val2=0;
        int val3=0;
        int val4=0;
        while(1){
           if((j1==i1)and(j2==i2)){
               double result=nums1[j1]+nums2[j2];
               return (result)/2;
           }
         else if((j1==i1)and(i2>j2)){
             return nums1[j1];
         }
        else if((j2==i2)and(i1>j1)){
            return nums2[j2];
        }
        else{
            if(i1>j1){
                 double val=nums2[j2]+nums2[i2];
                if(j2==(i2+1))return val/2;
                j2--;
                i2++;
            }
            else if(i2>j2){
                double val=nums1[j1]+nums1[i1];
                if(j1==(i1+1))return val/2;
                j1--;
                i1++;
            }
           else if(i1==j1){
               val1=nums1[i1];
               val2=nums2[i2];
               val3=nums2[j2];
               if(val1<=val2){
                   i1++;
                   j2--;
               }
              else if((val2<=val1)and(val1<=val3)){
                  i2++;
                  j2--;
              }
              else{
                  i1++;
                  i2++;
              }
           }
        else if(i2==j2){
             val1=nums2[i2];
               val2=nums1[i1];
               val3=nums1[j1];
               if(val1<=val2){
                   i2++;
                   j1--;
               }
               else if((val2<=val1)and(val1<=val3)){
                  i1++;
                  j1--;
              }
              else{
                  i2++;
                  i1++;
              }
        }
        else {
            val1=nums2[i2] ;
               val2=nums1[i1] ;
              val3=nums1[j1] ;
            val4=nums2[j2] ;
        
        if((val1<=val2)and(val1<=val3)and(val2<=val4)and(val3<=val4)){
            
            i2++;
            j2--;
        }
        else if((val2<=val1)and(val1<=val4)and(val3<=val4)){
            i1++;
            j2--;
            
        }
        else  if((val1<=val2)and(val1<=val4)and(val4<=val3)and(val2<=val3)){
            j1--;
            i2++;
        }
        else {
           
            j1--;
            i1++;
        }
        }
        }
            
        
            
            
        }
        
       return 0; 
    }
};