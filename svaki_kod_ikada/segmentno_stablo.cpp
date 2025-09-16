#include <iostream>
#include <vector>

using namespace std;

void build(vector<int> &seg_tree, vector<int> &array, const int k, const int start, const int end){
    if(start == end){
        seg_tree[k] = array[start];
        return;
    }

    int middle = (start+end)/2;

    build(seg_tree, array, 2*k+1, start, middle);
    build(seg_tree, array, 2*k+2, middle+1, end);

    seg_tree[k] = seg_tree[2*k+1] + seg_tree[2*k+2];
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
        update(seg_tree, 2*k+2, middle+1, end, index, value);
    }

    seg_tree[k] = seg_tree[2*k+1] + seg_tree[2*k+2];
}

int query(vector<int> &seg_tree, const int k, const int start, const int end, const int left, const int right){
    if(right < start || left > end){
        return 0;
    }

    if(start >= left && end <= right){
        return seg_tree[k];
    }

    int middle = (start+end)/2;

    int calc_left = query(seg_tree, 2*k+1, start, middle, left, right);
    int calc_right = query(seg_tree, 2*k+2, middle+1, end, left, right);

    return calc_left + calc_right;
}

int main(){

    return 0;
}