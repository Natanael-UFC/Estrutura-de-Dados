#include <iostream>

using namespace std;

struct vetor{

    int *data;
    int *aux;
    int _max;
    int aux_max;
    int _size {0};
    int zero = 0;

    vetor(int max){
        _max = max;
        data = new int[_max];
    }

    ~vetor(){
        delete [] data;
    }

    int &front(){
        static int dummy = 0;
        if(_size == 0)
            return dummy;

        return data[zero];
    }

    int &back(){
        static int dummy = 0;
        if(_size == 0)
            return dummy;

        return data[_size - 1];
    }

    int *begin(){
        return data;
    }

    int *end(){
        return &data[_size];
    }

    void push_back(int value){
        data[_size] = value;
        _size++;
    }

    void pop_back(){
        data[_size - 1] = 0;
        _size--;
    }

    int &get(int indice){
        return data[indice];
    }

    int size(){
        return _size;
    }

    void insert(int value, int pos){
        if(pos > _size)
            return;

         aux = data;
         aux_max = _max;
         _max = _max + 1;
         data = new int[_max];

        for(int i = 0; i < pos; i++){
            data[i] = aux[i];
        }

        data[pos] = value;

        for(int i = (pos + 1); i <= aux_max; i++){
            data[i] = aux[i - 1];
        }
        _size++;

        delete [] aux;

    }

    void remove(int pos){
        aux = data;
        data[pos] = 0;
        aux_max = _max;
        _max = _max - 1;
        data = new int[_max];

        if(pos == 0){
            for(int i = 0; i < (pos + 1); i++){
                data[i] = aux[i + 1];
            }
            int cont = aux_max - 2;

            for(int i = (pos + 1); i <= cont; i++){
                data[i] = aux[i + 1];
            }
            _size--;

            delete [] aux;
        }
        else if(pos != 0){

            for(int i = 0; i < pos; i++){
                data[i] = aux[i];
            }
            int cont = aux_max - pos;

            for(int i = pos; i <= (cont + 1); i++){
                data[i] = aux[i + 1];
            }

            _size--;

            delete [] aux;
        }
    }
};

int main()
{
    vetor v(6);

   v.push_back(1);
   v.push_back(2);
   v.push_back(3);
   v.push_back(4);
   v.push_back(2);
   v.push_back(6);

   for(int i = 0; i < v.size(); i++)
    cout << v.get(i) << endl;

   cout << "size: " << v.size() << endl;

   cout << endl;

   for(auto it = v.begin(); it != v.end(); it++){
       cout << *it << endl;
   }

   cout << endl;


    return 0;
}

