//Queue using two stacks with TLE problem.
#include <cmath>
#include <vector>
#include <iostream>
#include<stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q,x,k;
    cin>>q;
    stack<int>s1;
    stack<int>s2;
    for(int i=0;i<q;i++){
        cin>>x;
        if(x==1){
            cin>>k;
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(k);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        else if(x==2){
            s1.pop();
        }
        else{
            cout<<s1.top()<<endl;
        }
    }
    return 0;
}
