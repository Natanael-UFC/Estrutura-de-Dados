#include <iostream>
#include <sstream>
#include <ostream>

using namespace std;

struct Node{
    int value;

    Node * left{nullptr};
    Node * right{nullptr};

    Node(int value = 0){
        this->value = value;
    }
};

struct BTree{
    Node * root;

    BTree(){
        root = new Node(8);
        root->left = new Node(5);
        root->right = new Node(4);
        root->left->left = new Node(9);
        root->left->right = new Node(7);
        root->right->right = new Node(11);
        root->left->right->left = new Node(1);
        root->left->right->right = new Node(12);
        root->right->right->left = new Node(3);
        root->left->right->right->left = new Node(2);
    }

    Node * rfind(Node * node, int value){
        if(node == nullptr || node->value == value)
            return node;
        if(value < node->value)
            return rfind(node->left, value);
        return rfind(node->right, value);
    }

    Node * find(int value){
        return rfind(root, value);
    }

    Node ** rsmart_find(Node ** elo, int value){
        auto node = *elo;
        if(node == nullptr || node->value == value)
            return elo;
        if(value < node->value)
           return rsmart_find(&node->left, value);
        return rsmart_find(&node->right, value);
    }

    Node ** smart_find(int value){
        return rsmart_find(&root, value);
    }

    Node * rinsert(Node * node, int value){
        if(node == nullptr)
            return new Node(value);
        if(node->value < value)
            node->right = rinsert(node->right, value);
        if(node->value > value)
            node->left = rinsert(node->left, value);
        return node;
    }

    void insert(int value){
       // root = rinsert(root, value);
        auto elo = smart_find(value);
        if(*elo == nullptr)
            return new Node(value);
    }

    void rremove(Node ** elo, int value){
        auto node = *elo;

        if(node->left == nullptr && node->right == nullptr){
            *elo = nullptr;
            delete node;
            return;
        }
        if(node->left == nullptr && node->right != nullptr){
            *elo = node->right;
            delete node;
            return;
        }
        if(node->left != nullptr && node->right == nullptr){
            *elo = node->left;
            delete node;
            return;
        }

        auto sucessor = &node->right;
        while((*sucessor)->left != nullptr){
            sucessor = &(*sucessor)->left;
        }
    }

    bool remove(int value){
        auto elo = smart_find(value);
        if(*elo != nullptr){
            *elo = rremove(elo, value);
            return true;
        }
        return false;
    }



    Node * cloneserial(stringstream & ss){
        string elem;
        ss >> elem;

        if(elem == "#")
            return nullptr;

        int value;
        stringstream(elem) >> value;
        Node * node = new Node(value);
        node->left = cloneserial(ss);
        node->right = cloneserial(ss);
        return node;
    }

    BTree(string serial){
        stringstream ss(serial);
        root = cloneserial(ss);
    }

    void rserialize(Node * node, ostream & of){
        if(node == nullptr){
            of << "# ";
            return;
        }

        of << node->value << " ";
        rserialize(node->left, of);
        rserialize(node->right, of);
    }

    string serialize(){
        stringstream ss;
        rserialize(root, ss);
        return ss.str();
    }

    bool requals(Node * node, Node * other){
        if(node == nullptr && other == nullptr)
            return true;
        if(node != nullptr || other != nullptr)
            return false;
        if(node->value != other->value)
            return false;
        return requals(node->left , other->left) &&
               requals(node->right, other->right);
    }

    bool equals(BTree other){
        return requals(root, other.root);
    }

    void clone_elo(Node ** elo, Node * other){
        if(other == nullptr)
            return;

        (*elo) = new Node(other->value);

        auto node = *elo;

        clone_elo(&node->left, other->left);
        clone_elo(&node->right, other->right);
    }

    Node * clone(Node * other){
        if(other == nullptr)
            return nullptr;
        Node * node = new Node(other->value);
        node->left = clone(other->left);
        node->right = clone(other->right);
        return node;
    }

    BTree(BTree &other){
        //root = clone(other.root);
        clone_elo(&root, other.root);
    }

    void apagar(Node * node){
        if(node == nullptr)
            return;
        apagar(node->left);
        apagar(node->right);
        delete(node);
    }

    void clear(){
        apagar(root);
        root = nullptr;
    }

    ~BTree(){
        clear();
    }

    void rshow(Node * node){
        if(node == nullptr)
            return;

        rshow(node->left);
        cout << node->value << endl;
        rshow(node->right);
    }

    void bshow_dual(Node * node, string heranca, ostream & fout){
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            bshow_dual(node->left , heranca + "l", fout);
        int tam = heranca.size();
        for(int i = 0; i < tam - 1; i++){
            if(heranca[i] != heranca[i + 1])
                fout << "│" << "   ";
            else
                fout << " " << "   ";
        }
        if(heranca != ""){
            if(heranca.back() == 'l')
                fout << "┌───";
            else
                fout << "└───";
        }
        if(node == nullptr){
            fout << "#" << endl;
            return;
        }
        fout << node->value << endl;
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            bshow_dual(node->right, heranca + "r", fout);
    }

    void show(){
        bshow_dual(root, "", cout);
    }

    int soma(Node * node){
        if(node == nullptr)
            return 0;
        return node->value + soma(node->left) + soma(node->right);
    }

};

int main()
{
    BTree tree;
    cout << tree.serialize() << endl;

    return 0;
}

