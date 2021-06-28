//solution of queue using two stacks.here the order of complexity for all the three operations is od O(1).
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
            s1.push(k);
        }
        else if(x==2){
            if(!s2.empty()){
                s2.pop();
            }
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                s2.pop();
            }
        }
        else{
             if(!s2.empty()){
                cout<<s2.top()<<endl;
            }
            else{
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                cout<<s2.top()<<endl;
            }
        }
    }
    return 0;
}
