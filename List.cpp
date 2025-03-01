#include<iostream>
#include<cassert>

using namespace std;

template<typename T>

class List
{
private:
    //Clase nodo que tendrá el dato y el puntero al siguiente dato
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
        //Cambia el puntero del siguiente elemento
        void setNext(Node* next){
            next_ = next;
        }
        // Devuelve el puntero del siguiente elemento
        Node* getNext() { return next_; }
        // Devuelve el dato
        T getData() { return data_; }
    };
    Node* first_; //Primer elemento
    Node* last_; //Ultimo elemento
    unsigned int size_;
public:
    //Constructor
    List(){
        first_ = nullptr ;
        size_ = 0;
    }

    //Tamano de la lista
    unsigned int size() const { return size_ ;}

    //devuelve si es verdad que la lista esta vacia o no
    bool empty(){ return size_ == 0 ;}

    //Agregar elemento al inicio
    void push_front(const T& element){
        Node* n = new Node(element);
        n->setNext(first_);
        first_ = n;
        if(empty()){
            last_ = n;
        }
        size++;
    }

    //Agregar elemento al final de la lista
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

    //Eliminar primer elemento de la lista
    void pop_front(){
        if(empty()){ return ; }
        Node* temp = first_;
        first_ = first_->getNext();
        delete temp;
        size_--;

        if (size_ == 0) { last_ = nullptr ; }
    }

    //Eliminar ultimo elemento de la lista
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
    T& at(unsigned int pos){
        assert(pos < size_ && pos>=0);
        Node* current = first_;
        for (unsigned int i = 0; i < index; i++) {
            current = current->getNext();
        }
        return current->getData();
    }
    const T& at(unsigned int pos) const{
        assert(pos < size_ && pos>=0);
        Node* current = first_;
        for (unsigned int i = 0; i < index; i++) {
            current = current->getNext();
        }
        return current->getData();
    }
    void insert(unsigned int index, const T& element) {
        assert(index < 0 || index > size_);
    
        if (index == 0) { 
            push_front(element);
            return;
        }
    
        if (index == size_) { 
            push_back(element);
            return;
        }

        Node* current = first_;
        for (unsigned int i = 0; i < index - 1; i++) {
            current = current->getNext();
        }
    
        Node* newNode = new Node(element);
        newNode->setNext(current->getNext());
        current->setNext(newNode);
        
        size_++;
    }
    void remove(unsigned int index){
        assert(index < 0 || index > size_);
    
        if (index == 0) { 
            pop_front();
            return;
        }
    
        if (index == size_) { 
            pop_back();
            return;
        }

        Node* temp = first_;
        for (unsigned int i = 0; i < index - 1; i++) {
            temp = temp->getNext();
        }

        Node* toDelete = temp->getNext();
        temp->setNext(toDelete->getNext());
    
        delete toDelete;
        
        size_--;
    }
    int find(const T& element) const {
        Node* temp = first_;
        int index = 0;
    
        while (temp != nullptr) {
            if (current->getData() == element) {
                return index; 
            }
            temp = temp->getNext();
            index++;
        }
        
        return -1; 
    }

    Node* MergeSort(Node* firstElement){
        if (!firstElement || !firstElement->getNext()){ return firstElement; }

        Node* middle = getMiddle(firstElement);
        Node* secondMiddle = middle->getNext();
        middle->setNext(nullptr);

        return Merge(MergeSort(middle), MergeSort(secondMiddle)) ;
    }

    Node* getMiddle(Node* firstElement){
        if(!firstElement){ return firstElement ;}
        Node* devolver = firstElement , *complement = firstElement->getNext();
        while(complement && complement->getNext()){
            devolver->getNext();
            complement->getNext();
            complement->getNext();
        }
        return devolver;
    }

    Node* Merge(Node* left, Node* right){
        if(!left){ return right;}
        if(!right){ return left;}

        if (left->getData() < right->getData()) {
            left->setNext(merge(left->getNext(), right));
            return left;
        } else {
            right->setNext(merge(left, right->getNext()));
            return right;
        }
    }

    void sort(){
        first_ = MergeSort(first_);
    }

};
