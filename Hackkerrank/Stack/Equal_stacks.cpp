#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int minim(int b1,int b2,int b3){  
    if (b1 <= b2 && b1 <= b3)
        return b1;
    else if (b2 <= b1 && b2 <= b3)
        return b2;
    else
        return b3;
}

int main(){
    int n1,n2,n3,x,y,z;
    cin>>n1>>n2>>n3;
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    for(int i=0;i<n1;i++){
        cin>>x;
        v1.push_back(x);
    }
    for(int i=0;i<n2;i++){
        cin>>y;
        v2.push_back(y);
    }
    for(int i=0;i<n3;i++){
        cin>>z;
        v3.push_back(z);
    }
    stack<int>s1;
    stack<int>s2;
    stack<int>s3;
    int a1=0,a2=0,a3=0;
    for(int i=n1-1;i>=0;i--){
        s1.push(v1[i]);
        a1=a1+v1[i];
    }
    for(int i=n2-1;i>=0;i--){
        s2.push(v2[i]);
        a2=a2+v2[i];
    }
    for(int i=n3-1;i>=0;i--){
        s3.push(v3[i]);
        a3=a3+v3[i];
    }
    int mini;
    mini=minim(a1,a2,a3);
    while(!(a1==a2 && a2==a3) && mini>0){
        if(a1>mini){
            a1=a1-s1.top();
            s1.pop();
        }
        if(a2>mini){
            a2=a2-s2.top();
            s2.pop();
        }
        if(a3>mini){
            a3=a3-s3.top();
            s3.pop();
        }
        mini=minim(a1,a2,a3);
    }
    if(mini<=0){
        cout<<"0";
    }
    else{
        cout<<mini;
    }
    return 0;
}
