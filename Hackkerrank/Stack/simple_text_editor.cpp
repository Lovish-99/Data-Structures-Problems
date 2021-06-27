//solution of simpleTextEditor in HackkerRank with one error.
#include<bits/stdc++.h>
#include <vector>
#include<stack>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q;
    cin>>q;
    stack<char>text;
    stack<int>querry;
    stack<string>str1;
    stack<string>str;
    for(int i=0;i<q;i++){
        int t;
        cin>>t;
        if(t==1){
            querry.push(t);
            string s;
            cin>>s;
            str.push(s);
            for(int j=0;s[j]!='\0';j++){
                text.push(s[j]);
            }
        }
        else if(t==2){
            int k;
            cin>>k;
            querry.push(t);
            string s3="";
            while(k!=0){
                s3=s3 + text.top();
                text.pop();
                k--;
            }
            reverse(s3.begin(), s3.end());
            str1.push(s3);
        }
        else if(t==3){
            int k,m,counter=0;
            cin>>k;
            m=text.size()-k;
            while(!text.empty()){
                if(m==counter){
                    cout<<text.top()<<endl;
                    break;
                }
                counter++;
                m--;
                text.pop();
            }
        }
        else if(t==4){
            int y;
            y=querry.top();
            if(y==1){
                string s1;
                s1=str.top();
                int size;
                size=s1.length();
                for(int w=0;w<size;w++){
                    text.pop();
                }
                str.pop();
            }
            else if(y==2){
                string s4;
                s4=str1.top();
                int size1;
                size1=s4.length();
                for(int w=0;w<size1;w++){
                    text.push(s4[w]);
                }
                str1.pop();
            }
            querry.pop();
        }
    } 
    return 0;
}