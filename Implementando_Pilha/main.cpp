#include <iostream>

using namespace std;

struct Pilha{

    int * _data;
    int * _aux;
    int _size {0};
    int _max;
    int _aux_max;

    Pilha(int max){
        _max = max;
        _data = new int[_max];
    }

    ~Pilha(){
        delete [] _data;
    }

    int top(){
        if(_size == 0){
            return 0;
        }
        return _data[_size - 1];
    }

    int size(){
        return _size;
    }

  bool push(int value){
        if(_size == _max){
            _aux = _data;
            _aux_max = _max;
            _max = _max * 2;
            _data = new int[_max];

            for(int i = 0; i < _aux_max; i++){
                _data[i] = _aux[i];
            }

            delete [] _aux;
        }

        _data[_size] = value;
        _size++;
        return true;
    }

    bool pop(){
        if(_size > 0){
            _size--;
            _data[_size] = 0;
            return true;
        }
        return false;
    }
};

int main(){

    Pilha pilha(2);
    pilha.push(1);
    pilha.push(2);
    pilha.push(3);

    pilha.push(9);
    pilha.push(5);

    for(int i = 0; i < 5; i++){
        cout << pilha.top() << endl;
        pilha.pop();
    }



    return 0;
}

