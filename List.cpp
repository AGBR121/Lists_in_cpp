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
        void setNext(Node* next){
            next_ = next;
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

    bool empty(){ return !size_ ;}

    void push_front(const T& element){
        Node* n = new Node(element);
        n->setNext(first_);
        first_ = n;
        if(empty()){
            last_ = n;
        }
        size++;
    }

    void push_back(const T& element){
        Node* n = new Node(element);
        last_->setNext(n);
        last_ = n;
        if(empty()){
            first_ = n;
        }
        size_++;
    }
};
