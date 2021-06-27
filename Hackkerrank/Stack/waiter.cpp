//Solution of the HackkerRank Waiter Problem.
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

stack<int> element(vector<int>p ,stack<int>a){
    stack<int>answer;
    stack<int>b;
    int siz=p.size();
    for(int i=0;i<siz;i++){
        vector<int>v;
        while(!a.empty()){
            if(a.top()%p[i]==0){
                b.push(a.top());
                a.pop();
            }
            else{
                v.push_back(a.top());
                a.pop();
            }
        }
        int s3;
        s3=v.size();
        for(int j=0;j<s3;j++){
            a.push(v[j]);
        }
        while(!b.empty()){
            answer.push(b.top());
            b.pop();
        }
        if(a.empty()){
            break;
        }
    }
    if(!a.empty()){
        while(!a.empty()){
            answer.push(a.top());
            a.pop();
        }
    }
    return answer;    
}

int main(){
    int n,q,y;
    stack<int>arr;
    vector<int>pri;
    cin>>n>>q;
    for(int k=0;k<n;k++){
        cin>>y;
        arr.push(y);
    }
    int ct=0,m=0,i=1,j=1;  
    while(m<q)  
    {  
        j=1;  
        ct=0;  
        while(j<=i)  
        {  
            if(i%j==0)  
            ct++;  
            j++;   
        }  
        if(ct==2)  
        {  
            pri.push_back(i);
            m++;  
        } 
        i++;
    }
    stack<int>s2;
    vector<int>result;
    s2=element(pri,arr);
    while(!s2.empty()){
        result.push_back(s2.top());
        s2.pop();
    }
    int s5;
    s5=result.size();
    for(int m=s5-1;m>=0;m--){
        cout<<result[m]<<endl;
    }
    /*int s;
    s=pri.size();
    for(int k=0;k<s;k++){
        cout<<pri[k]<<endl;
    }*/
    return 0;
}
