#include <iostream>

using namespace std;

struct Node{
    int value;
    Node * next;

    Node(int value = 0, Node * node = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct Iter{
    Node * node;

    Iter(Node * node){
        this->node = node;
    }

    int &get_value(){
       return node->value;
    }

    void go_next(){
            node = node->next;
    }

    bool is_end(){
        return (node == nullptr);
    }
};

struct SList{
    Node * head;
    int _size {0};

    SList(){
        head = nullptr;
    }

    Iter begin(){
        return Iter(head);
    }

    void push_front(int value){
        Node * node = new Node(value, head);
        head = node;
    }

    void pop_front(){
        if(head == nullptr){
            return;
        }

        auto aux = head;
        head = head->next;
        delete aux;
    }

    void push_back(int value){
        auto node = head;
        if(node == nullptr){
            push_front(value);
            return;
        }

        while(node->next != nullptr){
            node = node->next;
        }
        node->next = new Node(value, nullptr);
    }

    void pop_back(){
        if(head == nullptr){
            return;
        }

        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }

        auto node = head;
        while(node->next->next != nullptr){
            node = node->next;
        }
        delete node->next;
        node->next = nullptr;
    }

    int size(){
        int cont = 0;
        auto node = head;

        if(node == nullptr){
            return 0;
        }

        while(node != nullptr){
            node = node->next;
            cont++;
        }
        return cont;
    }

    bool is_empty(){
        if(head == nullptr){
            return true;
        }
        return false;
    }

    void print(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

    Node * find(int value){
        auto node = head;
        if(node == nullptr){
            return nullptr;
        }

        while (node != nullptr) {
            if(node->value == value){
                return node;
            }
            node = node->next;
        }
        return nullptr;
    }

    bool erase(int value){
        auto node = head;
        if(node == nullptr){
            return false;
        }

        if(node->value == value){
            auto vai_morrer = head;
            head = head->next;
            delete vai_morrer;
            return true;
        }

        while(node->next != nullptr){
            if(node->next->value == value){
                auto vai_morrer = node->next;
                node->next = node->next->next;
                delete vai_morrer;
                return true;
            }
            node = node->next;
        }

        return false;
    }


};

int main()
{
    SList lista;

    int total = 0;

    for(int i = 0; i < 10; i++){
        lista.push_back(i);
    }

    Iter it = lista.begin();
    while(!it.is_end()){
        cout << it.get_value() << " ";
        total += it.get_value();
        it.go_next();
    }

    cout << endl << total << endl;







    return 0;
}

