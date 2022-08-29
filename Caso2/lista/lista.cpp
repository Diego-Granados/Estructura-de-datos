#include "node.cpp"
#include <string>
#include <iostream>

using namespace std;

#ifndef LIST 

#define LIST 1

template <class T>
class List {
        

    public:
        Node<T> *first;
        Node<T> *last;
        int quantity;
        bool empty;

        List() {
            first = nullptr;
            last = nullptr;
            quantity = 0;
            empty = true;
        }

        void add(T *pData) {
            Node<T> *newNode = new Node<T>(pData);

            if (quantity>0) {
                this->last->setNext(newNode);
                this->last = newNode;
            } else {
                this->first = newNode;
                this->last = newNode;
            }

            empty = false;
            quantity++;
        }

        Node<T>* getFirst() {
            return this->first;
        }

        int getQuantity() {
            return quantity;
        }

        T* find(string pData){
            Node<T> * searchPtr = this->first;
            while (searchPtr != nullptr && searchPtr->getData()->name != pData){
                searchPtr = searchPtr->next;
            }
            if (searchPtr == nullptr){
                cout << "Se terminó la lista" << endl;
            }
            return (searchPtr->data);
        }

        void PrintList(){
            Node<T> * printPtr = this->first;
            while(printPtr != nullptr){
                cout << printPtr->data->name << endl;
                printPtr = printPtr-> next;
            }
        }
};
#endif