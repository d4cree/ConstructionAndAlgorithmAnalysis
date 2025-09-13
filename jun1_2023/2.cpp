#include <iostream>

using namespace std;

//a*x+b*y = euklid(a, b)
int pros_euklid(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = pros_euklid(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

int ctr(int a, int n, int b, int m){
    int x, y;
    int g = pros_euklid(n, m, x, y);

    if((b-a) % g!= 0) 
        return -1;
    
    int lcm = n/g*m;
    int t = (a +  (b-a) / g * x % (m/g) * n) % lcm;
    if(t < 0)
        t+=lcm;
    return t;
}

int main(){

    int n;
    int i1, j1, i2, j2;
    cin >> n >> i1 >> j1 >> i2 >> j2;

    // Normalizacija modula
    int a = ((i2 - i1) % n + n) % n;       // t ≡ a (mod n)
    int b = ((j1 - j2) % (n+1) + (n+1)) % (n+1); // t ≡ b (mod n+1)

    int ans = ctr(a, n, b, n+1);

    cout << ans << "\n";
    return 0;

    return 0;
}