#include <iostream>

using namespace std;

struct Fila{

    int *fila, *aux_fila;
    int aux, aux_tam;
    int _size{0};
    int zero = 0;

    Fila(int tamanho){
        aux = tamanho;
        fila = new int[aux];
    }
    ~Fila(){
        delete [] fila;
    }

    int *begin(){
        return fila;
    }

    int *end(){
        return &fila[_size];
    }

    int size(){
        return _size;
    }

    int &front(){
        static int dummy = 0;
        if(_size == 0){
            return dummy;
        }
        return fila[zero];
    }

    int &back(){
        static int dummy = 0;
        if(_size == 0){
            return dummy;
        }
        return fila[_size - 1];
    }

    bool push(int value){
        if(aux == _size - 1){
            aux_fila = fila;
            aux_tam = aux;
            aux = aux * 2;
            fila = new int[aux];

            fila[_size] = value;
            _size++;
        }

        fila[_size] = value;
        _size++;
        return true;
    }

    bool pop(){
        if(_size == 0){
            return false;
        }
        fila[zero] = 0;
        for(int i = 0; i <= (int) _size; i++){
            fila[i] = fila[i + 1];
        }
        _size--;

        return true;
    }
};

int main()
{
    Fila f(2);

    f.push(1);
    f.push(2);
    f.push(3);
    f.pop();

    cout << f.front() << endl;
    cout << f.back() << endl;

    return 0;
}

