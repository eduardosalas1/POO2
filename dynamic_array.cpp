#include "test_case.cpp"
using namespace std;

template <class T, unsigned int BUFFER_SIZE>

class DynamicArray{
private:
    unsigned int const CAPACITY = BUFFER_SIZE;
    unsigned int size;
    unsigned int reserved;
    T *  items;
    void reserve(){
        reserved += CAPACITY;
        T * temp = new T[reserved];
        for(auto i = 0; i<size ; i++){
            temp[i] = items[i];
        }
        delete[] items;
        items = temp;
    };
public:
    DynamicArray(){
        size = 0;
        reserved = 5;
        items = new T[CAPACITY];
    }
    void pushBack(T item){
        if (size == reserved){
            reserve();
        }
        items[size] = item;
        size++;

    }

    unsigned int getSize() {
        return size;
    }
    T getItem(unsigned int index){
        return items[index];
    }
    void removeItem(unsigned int index){
        for(auto i = index ; i < CAPACITY ; i++){
            items [ i ] = items[ i + 1 ];
        }
        reserved -= 1;
        reserve();

    };
    void insertItem(unsigned int index, T item){


    };


};
