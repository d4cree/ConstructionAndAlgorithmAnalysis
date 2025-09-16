#include <iostream>
#include <vector>

using namespace std;

vector<int> z_alg(const string &s){
    int l = 0;
    int r = 0;
    int n = s.size();
    vector<int> z(n);

    for(int i = 0; i < n; i++){
        if(i <= r){
            z[i] = min(r-i+1, z[i-l]);
        }

        while(i+z[i] < n && s[z[i]] == s[i+z[i]])
            z[i]++;
        
        if(z[i]+i-1 > r){
            l = i;
            r = z[i]+i-1;
        }
    }
    return z;
}