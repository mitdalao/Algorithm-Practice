#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string tmp;
    vector<string> str;
    while(cin >> tmp){
        str.push_back(tmp);
    }
    for(int i = str.size() - 1; i >= 0; i--){
        cout << str[i];
        if(i > 0)
            cout << " ";
    }
    cout << endl;
    return 0;
}