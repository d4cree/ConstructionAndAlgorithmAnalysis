//Obican:
#include <iostream>

using namespace std;

int NZD(int a, int b){
    int tmp;
    while(b != 0){
        tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

//Prosireni euklidov algoritam

int pros_NZD(long long a, long long b, long long &s, long long &t){
    long long r0 = a, r1 = b;
    long long s0 = 1, s1 = 0;
    long long t0 = 0, t1 = 1;

    while(r1 > 0){
        long long q = r0/r1;
        long long tmp;

        tmp = r0;
        r0 = r1;
        r1 = tmp - q*r1;

        tmp = s0;
        s0 = s1;
        s1 = tmp - q*s1;

        tmp = t0;
        t0 = t1;
        t1 = tmp - q*t1;
    }
    s = s0;
    t = t0;
    
    return r0;
}

bool inverz(long long n, long long a, long long &t){
    long long s;
    long long r = pros_NZD(n, a, s, t);
    if(t < 0)
        t += n;
    return r == 1;
}

//Kineska teorema:
//Do sad sve isto kao euklid
//dodajes jos zm, pm, pmp

long long pm(long long x, long long y, long long n){
    return ((x%n) * (y%n))%n;
}

long long zm(long long x, long long y, long long n){
    return ((x%n) + (y%n))%n;
}

long long pmp(long long x, long long y, long long z){
    return z * (x%y);
}

bool kto(long long n[], long long a[], int duzina, long long &result){
    long long N = 1;
    for(int i = 0; i < duzina; i++)
        N *= n[i];
    
    result = 0;
    for(int i = 0; i < duzina; i++){
        long long pi = N / n[i];
        long long pi_inv;
        if(!inverz(n[i], pi, pi_inv))
            return false;
        
        result = zm(result, pmp(pm(a[i], pi_inv, N), n[i], pi), N);
    }
    return true;
}