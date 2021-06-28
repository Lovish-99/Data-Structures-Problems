#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, vector<int> queries, int size){
    vector<int>ans;
    for(int i=0; i<size; i++){
        int j=0;
        int max_=-1;
        if(queries[i] == 1){
            ans.push_back(*min_element(arr.begin(),arr.end()));
        }
        else{
            int s3;
            s3=arr.size();
            while(j < (s3+1-queries[i])){
                vector<int>temp;
                
            //here we create a vector temp to enter the elements from j to j+queries[i]
                for(int d=j; d < j + queries[i]; d++){
                    temp.push_back(arr[d]);
                }
                
                int m=std::max_element(temp.begin(),temp.end())-temp.begin();
                
                j+=m+1;
                if(temp[m] < max_ || max_ == -1){
                    max_=temp[m];
                }
            }    
            ans.push_back(max_);
        }   
    }
    return ans;
}

int main(){
    int no_of_elements, x, no_of_queries, y;
    cin >> no_of_elements >> no_of_queries;
    
    vector<int>arr;
    vector<int>queries;
    vector<int>answer;
    
    for(int i=0; i < no_of_elements; i++){
        cin >> x;
        arr.push_back(x);
    }
    for(int i=0; i < no_of_queries; i++){
        cin >> y;
        queries.push_back(y);
    }
    
    answer=solve(arr,queries,no_of_queries);
    
    for(int k=0; k < no_of_queries; k++){
        cout << answer[k] << endl;
    }
    return 0;
}
