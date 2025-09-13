//3. na farmi postoje određeni stubovi, metalni i drveni. između dva metalna može stajati isključivo metalna ograda, između dva 
//drvena može isključivo drvena ograda, a između dve različite je nebitno. izračunati minimalnu cenu ograđivanja maksimalne 
//površine na farmi, ako su zadate koorde stubova, kao i cena drvene i metalne ograde.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

struct Point{
    int x, y;
    char type;
};

int orientation(Point P, Point Q, Point R){
    return (Q.y - P.y)*(R.x - Q.x) - (Q.x - P.x)*(R.y - Q.y);
}

double distance(Point P, Point Q){
    return sqrt((P.x-Q.x)*(P.x-Q.x) + (P.y - Q.y)*(P.y - Q.y));
}

vector<Point> sorting(vector<Point> farm){
    int n = farm.size();
    if(n <= 1) return farm;

    Point p0 = *min_element(farm.begin(), farm.end(), [](Point a, Point b){
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });

    sort(farm.begin(), farm.end(), [&p0](const Point &a, const Point &b){
        int o = orientation(p0, a, b);

        if (o == 0){
            return distance(p0, a) < distance(p0, b);
        }

        return o > 0;
    });

    vector<Point> st;
    for(int i = 0; i < n; i++){
        //dokle god je orijentacija u smeru kazaljke na satu, izbaci srednju tacku
        while(st.size() > 1 && orientation(st[st.size() - 2], st.back(), farm[i]) <= 0){
            st.pop_back();
        }

        st.push_back(farm[i]);
    }

    return st;

}

int main(){
    vector<Point> farm = {{0,0,'M'}, {0,5,'D'}, {5,5,'M'}, {5,0,'D'}, {2,2,'M'}};

    double priceWood = 3;
    double priceMetal = 5;

    vector<Point> sorted = sorting(farm);

    for(auto s : sorted){
        cout << s.x << " " << s.y << " " << s.type << endl;
    }

    double sum = 0;
    int i = 0;
    for(int i = 0; i < sorted.size(); i++){
        Point A = sorted[i];
        Point B = sorted[(i+1) % sorted.size()];

        double len = distance(A,B);
        if(A.type=='M' && B.type=='M') 
            sum += priceMetal*len;
        else if(A.type=='D' && B.type=='D') 
            sum += priceWood*len;
        else 
            sum += min(priceWood, priceMetal)*len;
    }

    cout << sum << endl;
    return 0;
}