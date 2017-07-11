#include <iostream>

using namespace std;

struct Node{
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

//lista simples sem cabeca
struct SList{
    Node * head;
    int _size {0};

    SList(){
        head = nullptr;
    }

    void push_front (int value){
        Node * node = new Node(value, head);
        head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;

        auto aux = head;
        head = head->next;
        delete aux;
    }

    int size(){
        int cont = 0;
        auto node = head;

        if(node == nullptr)
            return 0;

        while(node != nullptr){
            node = node->next;
            cont++;
        }
        return cont;
    }

    bool isEmpty(){
        if(head == nullptr)
            return true;
        else
            return false;
    }

    void push_back(int value){
        Node *novo = new Node(value, head);

        if(head->next == nullptr){
            head->next = novo;
            novo->next = nullptr;
        }
        else{
            auto aux = head->next;

            while(aux->next != nullptr){
                aux = aux->next;
            }

            aux->next = novo;
            novo->next = nullptr;
        }
    }

    void pop_back(){      
        if(head == nullptr)
            return;
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

    //retorna o node ou null
    Node * find(int value){
        if(head == nullptr){
            return nullptr;
        }

        auto aux = head->next;

        while(aux != nullptr){
            if(aux->value == value)
                break;
            aux = aux->next;
        }

        return aux;
    }

    bool erase(int value){
        auto node = head;
        if(node == nullptr){
           return false;
        }

        if(head->value == value){
            auto aux = head;
            head = head->next;
            delete aux;
            aux = nullptr;
            return true;
        }

        while(node->next != nullptr){
                if(node->next->value == value){
                    auto aux = node->next;
                    node->next = node->next->next;
                    delete aux;
                    aux = nullptr;
                    return true;
                }
                node = node->next;
        }
        return false;
    }

    //remove esse nó da lista
    bool erase(Node * node){
        if(head == nullptr)
            return false;

        if(node == nullptr){
            auto aux_no = head;
            head = head->next;
            delete aux_no;
            aux_no = nullptr;
            return true;
        }

        auto aux_node = head;
        auto aux = head->next;

        while(aux != nullptr){
            if(aux == node)
                break;
            else{
                aux_node = aux;
                aux = aux->next;
            }
        }
        aux_node->next = aux->next;
        delete aux;
        aux = nullptr;

        return true;
    }

    //insere o elemento antes desse no
    bool insert(Node * node, int value){
//        if(node == nullptr){
//            Node * node_new = new Node(value, head);
//            head = node_new;
//            return true;
//        }
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
};



int rsomar(int i){
    if(i <= 5)
        return 0;
    return i + 2 + rsomar(i - 3);
}
int somar(){
    return rsomar(30);
}

int pegar_casa(int num){
    if(num == 0)
        return 0;

    return (num % 10) + pegar_casa(num / 10);
}





int main()
{
    SList lista;

   // cout << "Size: " << lista.size() << endl;

   cout << pegar_casa(123456) << endl;



    return 0;
}

