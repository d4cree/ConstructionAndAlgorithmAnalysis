/*Drustvene mreze    (disjunktni skupovi)
Ljudi koriste drustvene mreze i povezuju se jedni sa drugima.
napisi program koji ce da ima dve radnje:
    M - spajamo osobu a i b
    Q - ispisujemo koliko osoba ima u mrezi u kojoj je  

ulaz: h, broj ljudi i q, broj upita, pa onda q upita koji imaju M ili Q radnju 
    ako je M onda unosimo jos a i b 
    ako je Q onda unosimo jos a 

izlaz: za svaki Q upit da ispise koliko ima ljudi ima u toj a mrezi

test primer:
3 6
Q 1
M 1 2 
Q 2
M 2 3
Q 3
Q 2

izlaz:
1
2
3
3*/

#include <iostream>
#include <vector>

using namespace std;

int ID = 0;

struct element{
    int id;
    struct set* set = nullptr;
    struct element* next = nullptr;
};

struct set{
    int id;
    struct element *head = nullptr;
    struct element *tail = nullptr;
};

void make_set(struct element *x){
    auto new_set = new set();

    new_set -> id = ID++;
    new_set -> head = x;
    new_set -> tail = x;

    x -> set = new_set;
}

struct element* find_set(struct element *x){
    return x -> set -> head;
}

void union_set(struct element *x, struct element *y){
    auto x_set = find_set(x)->set;
    auto y_set = find_set(y)->set;

    x_set->tail->next = y_set->head;
    x_set->tail = y_set->tail;

    auto y_head = y_set->head;
    while(y_head != nullptr){
        y_head->set = x_set;
        y_head = y_head->next;
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    int n_copy = n;

    vector<element*>niz(n+1);
    for(int i = 1; i <= n; i++){
        auto elem = new element();
        elem->id = i;
        make_set(elem);
        niz[i] = elem;
    }

    while(q--){
        char query;
        cin >> query;
        if(query == 'M'){
            int a, b;
            cin >> a >> b;
            union_set(niz[a], niz[b]);
        } else if (query == 'Q'){
            int a;
            cin >> a;
            auto a_set = find_set(niz[a])->set;
            auto a_head = a_set->head;
            int count = 0;
            while(a_head != nullptr){
                count++;
                a_head = a_head->next;
            }
            cout << count << endl;
        }
    }


    return 0;
}