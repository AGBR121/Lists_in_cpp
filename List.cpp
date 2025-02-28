#include<iostream>
#include<cassert>

using namespace std;

template<typename T>

class List
{
private:
    T* first;
    class Node{
        private:
        T data_;
        Node* next_;
        public:
        Node(){
            data_ = T();
            next_ = nullptr;
        }
        Node(const T& element){
            data_ = element;
            next_ = nullptr;
        }
    };
    T* last;
    unsigned int size;
public:
    
};
