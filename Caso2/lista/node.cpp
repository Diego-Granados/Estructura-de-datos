#ifndef NODE 

#define NODE 1

using namespace std;

template <class T>

class Node {
        
    
    public:
        T *data;
        Node *next;
        Node() {
            data = nullptr;
            next = nullptr;
        }

        Node(T *pData) {
            this->data = pData;
            next = nullptr;
        }

        T* getData() {
            return data;
        }

        Node* getNext() {
            return next;
        }

        void setNext(Node *pValue) {
            this->next = pValue;
        }
};

#endif