#pragma once

template <class UT>
struct Node {
    UT data;
    Node<UT> *next = NULL;
};

class Values {
    private:
        char *keys;
        double *values;
        int size;
    public:
        Values(){
            keys = new char[28];
            values = new double[28];
            size = 0;
        }
        void Push(char key){
            keys[size++] = key;
        }
        void Push(char key, double value){
            int i = 0;
            while(i < 28 && keys[i++] != key);
            if(i == 28){ keys[size] = key; values[size++] = value; }
        }
        double operator[](char key){
            int i = 0;
            while(keys[i++] != key);
            return values[i];
        }
        int GetSize() const { return size; }
        ~Values(){ delete[] keys; delete[] values; }
};

template <class UT>
class Stack {
    private:
        Node<UT> *head;
        int length;
    public:
        Stack(){
            head = new Node<UT>;
            length = 0;
        }
        UT Push(UT item){
            // std::cout << "pushed " << item << " stack num" << i << std::endl; 
            Node<UT> *current = new Node<UT>;
            current -> data = item;
            current -> next = head;
            head = current;
            ++length;
            return item;
        }
        UT Pop(){
            Node<UT> *pop = head;
            head = head -> next;
            UT result = pop -> data;
            --length;
            delete pop;
            return result;
        }
        bool UnEmpty(){
            if(head == NULL) return false;
            return true;
        }
        bool Iterator(){
            if(head -> next == NULL) return false;
            return true;
        }
        UT Read(){
            return head -> data;
        }
        int Length() const { return length; }
};

class Dict {
    private:
        char* keys;
        double* values;
        int size;
    public:
        Dict(){
            size = 0;
            keys = new char[28];
            values = new double[28];
        }
        void Push(char key, double value){
            keys[size] = key;
            values[size++] = value;
        }
        double& operator[](char key){
            for(int i = 0; i < 28; ++i) if(key == keys[i]) return values[i];
        }
        ~Dict(){
            delete[] keys;
            delete[] values;
        }
};