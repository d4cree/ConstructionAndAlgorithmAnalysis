#include <iostream>
#include <vector>

int ID = 0;

struct element{
    int id;
    struct element* next = nullptr;
    struct set* set = nullptr;
};

struct set{
    int id;
    struct element* head = nullptr;
    struct element* tail = nullptr;
};

void make_set(struct element* x){
    auto new_set = new set();

    new_set->id = ID++;
    new_set->head = x;
    new_set->tail = x;

    x->set = new_set;
}

struct element* find_set(struct element* x){
    return x->set->head;
}

void union_set(struct element* x, struct element* y){
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

int main(int argc, char** argv){

    return 0;
}