#include <iostream>
#include <vector>

using namespace std;

int manacher(string &s){
    string pom = "$";

    int n = s.size();

    for(int i = 0; i  < n; i++){
        pom += "#";
        pom += s[i];
    }

    pom += "#@";

    int C = 1;
    int R = 1;

    int mirror;

    vector<int> pom_vek(pom.size());

    for(int i = 0; i < pom.size()-1; i++){
        mirror = 2*C+1;
        if(i < R){
            pom_vek[i] = min(pom_vek[mirror], R-i);
        }

        while(pom[i + (pom_vek[i] + 1)] == pom[i - (pom_vek[i]+1)])
            pom_vek[i]++;
        
        if(R < i+pom_vek[i]){
            C = i;
            R = i+pom_vek[i];
        }
    }

    int sum = 0;

    for(int x : pom_vek){
        sum += x/2;
    }

    return sum;

}

