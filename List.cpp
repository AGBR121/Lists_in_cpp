#include<iostream>
#include<cassert>

using namespace std;

template<typename T>

class List
{
private:
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
    Node* first_;
    Node* last_;
    unsigned int size_;
public:
    //Constructor
    List(){
        first_ = nullptr ;
        size_ = 0;
    }
    unsigned int size() const { return size_ ;}
    bool empty(){ return first_ == nullptr ;}
};
