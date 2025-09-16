#include <iostream>

using namespace std;

int ojlerova_funkcija(int n){
    int d = 2;
    int proizvod = n;
    while(d*d <= n){
        if(n % d == 0){
            proizvod = (proizvod/d)*(d-1);
        }
        while(n % d == 0)
            n /= d;
        
        d++;
    }

    if(n > 1)
        proizvod = (proizvod/n)*(n-1);
    
    return proizvod;
}