#include<iostream>
#include<stack>

using namespace std;

int main(){
    int n,size;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        stack<char>st;
        size=s.length();
        for(int i=0;i<size;i++){
            if(s[i]=='{'||s[i]=='['||s[i]=='('){
               st.push(s[i]);
            }
            else{
                while(!st.empty()&&((s[i]==')'&&st.top()=='(')||(s[i]==']'&&st.top()=='[')||(s[i]=='}'&&st.top()=='{'))){
                    st.pop();
                }
            }
        }
        if(st.empty()){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
