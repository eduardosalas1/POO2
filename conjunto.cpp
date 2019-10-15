#include <vector>
using namespace std;

template<class T>
class Conjunto{
private:
    vector<T>* elementos;
public:
    Conjunto(vector<T>* elementos){
        this->elementos=elementos;
    }
    Conjunto(){
        elementos=new vector<T>;
    }
    vector<T> *getElementos()const{
        return elementos;
    }
    void setElementos(vector<T> *elementos){
        Conjunto::elementos = elementos;
    }
    bool existeElemento(T e){
        for(T elemento: *elementos)
            if(elemento==e)
                return true;
        return false;
    }
    void adicionarElementos(vector<T> *elementos2){
        for(T e: *elementos2)
            if(!existeElemento(e))
               elementos->push_back(e);
    }

    Conjunto <T> * realizarUnion(Conjunto* c){
        Conjunto<T>* nuevoConjunto= new Conjunto();
        nuevoConjunto->adicionarElementos(elementos);
        nuevoConjunto->adicionarElementos(c->getElementos());
        return nuevoConjunto;

    }
    Conjunto<T> * realizarInterseccion(Conjunto* c){
        Conjunto<T>* nuevoConjunto= new Conjunto();



    }
};
