//solution of largestRectangle HackkerRank problem in time complexity of O(nlg(n))
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

long largestRectangle(vector<int> h) {
long temp=0, area=0;
    for(int i=0;i<h.size();i++){
        int j=i, k=i-1, count=0;
        if(h[i]<=h[j]){
            while(h[j]>=h[i] && j<h.size()){
                count++;
                j++;
            }   
        }
        if(h[i]<=h[k]){
            while(h[k]>=h[i] && k>=0){
                count++;
                k--;
            }   
        }
        area=(count)*h[i];
        if(area>temp)
            temp=area;
    }
    return temp;
}

int main(){
    int n,x;//,y,area=0,mini;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    cout<<largestRectangle(v)<<endl;
}
