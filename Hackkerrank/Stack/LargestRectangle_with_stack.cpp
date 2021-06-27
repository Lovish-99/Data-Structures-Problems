//Solution of Largest Rectangle HackkerRank
//order of complexity is O(n^2)
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
    int n,x,y,area=0,mini;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    stack<int>s;
    for(int i=0;i<n-1;i++){
        int k=1;
        mini=v[i];
        for(int j=i+1;j<n;j++){
            if(mini>v[j]){
                mini=v[j];
            }
            if(v[i]<v[j]){
                if(v[i]<=mini){
                    y=v[i]*(k+1);
                    s.push(y);
                }
                else{
                    y=mini*(k+1);
                    s.push(y);
                }
            }
            else{
                if(v[j]<v[j-1]){
                    if(v[j]<=mini){
                        y=v[j]*(k+1);
                        s.push(y);
                    }
                    else{
                        y=mini*(k+1);
                        s.push(y);
                    }
                }
                else{
                    if(v[j-1]<=mini){
                        y=v[j-1]*(k+1);
                        s.push(y);
                    }
                    else{
                        y=mini*(k+1);
                        s.push(y);
                    }
                }
            }
            k++;
        }
    }
    while(!s.empty()){
        if(area<s.top()){
            area=s.top();
            s.pop();
        }
        else{
            s.pop();
        }
    }
    cout<<area<<endl;
}
