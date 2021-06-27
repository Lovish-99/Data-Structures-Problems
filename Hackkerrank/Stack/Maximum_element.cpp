#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main(){
    stack<int>s;
    int n,x,y,size;
    cin>>n;
    vector<vector<int>>v(n);
    vector<int> v2;
    for(int i=0;i<n;i++){
        cin>>x;
        v[i].push_back(x);
        if(x==1){
            cin>>y;
            v[i].push_back(y);
        }
    }
    for(int i=0;i<n;i++){
        if(v[i][0]==1){
            if(s.empty())
                s.push(v[i][1]);
            else{
                //important line <<<<<----->>>>>
                s.push(max(v[i][1],s.top()));
            }
        }
        else if(v[i][0]==2){
            s.pop();
        }
        else{
            cout<<s.top()<<endl;
        }
    }
    return 0;
}
