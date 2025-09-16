#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Node{
    bool end_node = false;
    unordered_map<char, Node* > children;
    string word = "";
};

void add(Node *tree, const string &word){
    for(const char c : word){
        if(tree->children.find(c) == tree->children.end()){
            tree->children[c] = new Node();
        }

        tree = tree->children[c];
    }

    tree->end_node = true;
    tree->word = word;
}

void free(Node *tree){
    if(tree != nullptr){
        for(auto [_, node] : tree->children)
            free(node);
    }

    delete tree;
}

//Moze sad ovde sve i svasta, da se nadje najduzi prefiks 
//da se vidi koje sve reci mogu da se ispisu itd
//za autocomplete cemo dodati string word u strukturu kako bismo \
//mogli da ispisemo svaki put kada stignemo do kraja reci u stablu.

string longest_common_prefix(Node *tree){
    string prefix = "";

    while(tree->children.size() == 1 & tree->end_node == false){
        auto [c, node] = *tree->children.begin();

        prefix += c;
        tree = node;
    }

    return prefix;
}

void print(Node *tree){
    if(tree->end_node == true)
        cout << tree->word << endl;

    for(auto [_, node] : tree->children)
        print(node);
}


void autocomplete(Node* tree, const string &prefix){
    for(const char c : prefix){
        if(tree->children.find(c) == tree->children.end()){
            cout << "-1" << endl;
            return;
        }

        tree = tree->children[c];
    }

    print(tree);
}

int main(int argc, char** argv){

    return 0;
}