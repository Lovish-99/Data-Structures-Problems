class Solution {
public:
    int reverse(int x){
        int size;
        string str1;
        char str2;
        str1=to_string(x);
        size=str1.length();
        int initial=0, end=size-1;
        if(str1[0]!='-'){
           while(initial<end){
                str2=str1[initial];
                str1[initial]=str1[end];
                str1[end]=str2;
               initial++;
               end--;
           }
            if(stol(str1)>INT_MAX || stol(str1)<INT_MIN){
                return 0;
            }
            else{
                x = stol(str1);
                return x;
            }
        }
        else{
            int k=1;
            str1[0]='-';
            while(initial<end){
                str2=str1[k];
                str1[k]=str1[end];
                str1[end]=str2;
                initial++;
                end--;
                k++;
           }
            if(stol(str1)>INT_MAX || stol(str1)<INT_MIN){
                return 0;
            }
            else{
                x = stol(str1);
                return x;
            }
        }
     }
};
