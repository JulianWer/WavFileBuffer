
#include <string>
#include<iostream>
#include <fstream>

// Julian Wernz 2123602

using namespace std;

template<typename T>
class Container {
private:
    T *elements;
    int size;
public:
    Container(int size) { // constructor
        this->elements = new T[size];
        this->size = size;
    }


    T &operator[](int n) { // overload [] operator
        if (n >= this->length())
            getNewContainer(n);
        return this->elements[n];
    }


    int length() {
        return this->size; // get length
    }

    void getNewContainer(int index) {
        T *tempArray = new T[index + 1]; // init new temporary array
        for (int i = 0; i <= this->length(); i++) { // copy elements to the other array
            tempArray[i] = this->elements[i];
        }
        delete[] elements; // delete old array elements
        this->size = index + 1;
        this->elements = tempArray; // set the elements pointer to the nContainer array
    }


};


