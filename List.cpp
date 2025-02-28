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

    bool empty(){ return size_ == 0 ;}

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
        if (empty()) {
            first_ = last_ = n;
        } else {
            last_->setNext(n);
            last_ = n;
        }
        size_++;
    }

    void pop_front(){
        if(empty()){ return ; }
        Node* temp = first_;
        first_ = first_->getNext();
        delete temp;
        size_--;

        if (size_ == 0) { last_ = nullptr ; }
    }

    void pop_back(){
        if(empty()){ return ; }
        if(first_ == last_){
            delete first_;
            first_ = last_ = nullptr;
        }else{
            Node* current = first_;
            while (current->getNext() != last_) {
                current = current->getNext();
            }
            delete last_;
            last_ = current;
            last_->setNext(nullptr);
        }
        size_--;
    }
};
