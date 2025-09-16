#include <iostream>

long long dopuna_do_kvadrata(long long n){
    long long m = 1;
    long long p = 2;

    while(p*p <= n){
        int k = 0;

        while(n % p == 0){
            n /= p;
            k++;
        }

        if(k % 2 != 0)
            m *= p;
        
        p++;
    }

    if(n > 0)
        m *= n;
    
    return m;
}