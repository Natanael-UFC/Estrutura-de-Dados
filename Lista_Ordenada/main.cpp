#include <iostream>
#include <sstream>

using namespace std;

struct Node{
    int value;
    Node * next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{
    Node * head {nullptr};

    SList(){
    }

    SList(string serial){
        stringstream sstring(serial);
        int value;
        while(sstring >> value){
            insert_rec(value);
        }
    }

    Node * rinsert(Node * node, int value){
        if(node == nullptr){
            return new Node(value);
        }
        if(node->value > value){
            return new Node(value, node);
        }

        node->next = rinsert(node->next, value);
        return node;
    }

    void insert_rec(int value){
        head = rinsert(head, value);
    }

    void rinsert_elo(Node ** casa, int value){
        auto node = *casa;
        if(node == nullptr){
            *casa = new Node(value);
        }
        if(node->value > value){
            *casa = new Node(value, node);
        }
        rinsert_elo(&node->next, value);
    }

    void insert_elo(int value){
        rinsert_elo(&head, value);
    }

    Node * rremove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto next = node->next;
            delete node;
            return next;
        }

        node->next = rremove(node->next, value);
        return node;
    }

    void remove_rec(int value){
        head = rremove(head, value);
    }

    void insert_interativo(int value){
        if(head == nullptr || head->value > value){
            head = new Node(value, head);
            return;
        }

        auto node = head;
        while(true){
            if(node->next == nullptr || node->next->value > value){
                node->next = new Node(value, node->next);
                break;
            }
            node = node->next;
        }
    }

    void rshow(Node * node){
        if(node == nullptr)
            return;

        cout << node->value << " ";
        rshow(node->next);
    }

    void show(){
        cout << "[ ";
        rshow(this->head);
        cout << "]" << endl;
    }

};

int main()
{
    SList lista("1 2 3 4 5");
    lista.show();
    lista.insert_rec(6);
    cout << endl;
    lista.show();
    return 0;
}

