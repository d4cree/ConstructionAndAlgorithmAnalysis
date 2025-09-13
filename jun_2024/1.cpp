//dato segmentno stablo, optimizovati ga za problem ispitivanja da li 
//je neki podniz datog niza strogo rastući i obezbediti da može da se 
//efikasno promeni vrednost niza

//???????????????????????????????????????????????????????????????????
//Radicu da vazi samo da ima pozitivnih brojeva ja stvarno ne znam drugacije.

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <climits>

using namespace std;

void build(vector<int> &tree, vector<int> &array, const int k, const int start, const int end){
    if(start == end){
        tree[k] = array[start];
        return;
    }

    int middle = (start+end)/2;

    build(tree, array, 2*k+1, start, middle);
    build(tree, array, 2*k+2, middle+1, end);

    tree[k] = min(tree[2*k+1], tree[2*k+2]);
}

void update(vector<int> &seg_tree, const int k, const int start, const int end, const int index, const int value){
    if(start == end){
        seg_tree[k] = value;
        return;
    }

    int middle = (start+end)/2;

    if(index <= middle){
        update(seg_tree, 2*k+1, start, middle, index, value);
    } else {
        update (seg_tree, 2*k+2, middle+1, end, index, value);
    }

    seg_tree[k] = min(seg_tree[2*k+1], seg_tree[2*k+2]);
}

int rastuce(vector<int> &seg_tree, const int k, const int start, const int end, const int left, const int right){
    
    if(right < start || left > end)
        return INT_MAX;
    
    if(right >= end && left <= start){
            return seg_tree[k];
    }
    int middle = (start+end)/2;

    int left_rez = rastuce(seg_tree, 2*k+1, start, middle, left, right);
    int right_rez = rastuce(seg_tree, 2*k+2, middle+1, end, left, right);

    return min(left_rez, right_rez);

}

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> niz(n);
    for(int i = 0; i < n; i++){
        cin >> niz[i];
    }

    vector<int> diff(n-1);
    for(int i = 0; i < n-1; i++){
        diff[i] = niz[i+1] - niz[i];
    }

    int height = ceil(log2(n-1));
    int size = 2*pow(2, height) - 1;

    vector<int> seg_tree(size);

    build(seg_tree, diff, 0, 0, n-2);

    for(int x : seg_tree){
        cout << x << " ";
    }
    cout << endl;

    while(q--){
        char query;
        cin >> query;
        if(query == 'u'){
            int index, value;
            cin >> index >> value;
            niz[index] = value;
            if(index > 0)
                update(seg_tree, 0, 0, n-2, index-1, niz[index] - niz[index-1]);
            if(index < n-1)
                update(seg_tree, 0, 0, n-2, index, niz[index+1] - niz[index]);

            for(int x : seg_tree){
                cout << x << " ";
            }
            cout << endl;  
        } else if(query == 'r'){
            int left, right;
            cin >> left >> right;
            int ras_niz = 0;
            ras_niz = rastuce(seg_tree, 0, 0, n-2, left, right-1);
            cout << ras_niz << endl;
            if(ras_niz > 0)
                cout << "Strogo rastuci" << endl;
            else 
                cout << "Nije strogo rastuci" << endl;
        }
    }

    return 0;

}