class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto it=find(num1.begin(),num1.end(),'+');
        string real1=num1.substr(0,it-num1.begin());
        string imag1=num1.substr(it-num1.begin()+1,num1.end()-(it+1)-1);
        it=find(num2.begin(),num2.end(),'+');
        string real2=num2.substr(0,it-num2.begin());
        string imag2=num2.substr(it-num2.begin()+1,num2.end()-(it+1)-1);
        int real3=stoi(real1)*stoi(real2)-stoi(imag1)*stoi(imag2);
        int imag3=stoi(real1)*stoi(imag2)+stoi(imag1)*stoi(real2);
        return to_string(real3)+'+'+to_string(imag3)+'i';
    }
};