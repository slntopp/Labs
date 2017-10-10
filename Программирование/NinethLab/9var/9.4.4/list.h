#include "cmd.h"

template <typename UT = int>
struct Node {
    Node *next = NULL;
    UT data;
    int number;
};

template <typename UT=int>
class List {
    private:
        Node<UT> *head;
        int size;
    public:
        List(){
            head = new Node<UT>;
            size = 0;
            head -> number = 0;            
        }
        List(UT _data){
            head = new Node<UT>;            
            size = 1;
            head -> number = 0;
            head -> data = _data;
        }
        void Push(UT _data){
            Node<UT> *current = head, *previous = NULL, *buff;
            while(current){
                previous = current;
                current = current -> next;
            }
            buff = new Node<UT>;
            buff -> data = _data;
            buff -> number = size++;
            if(previous && size != 1){
                buff -> next = previous -> next;
                previous -> next = buff;
            } else {
                head = buff;
                head -> next = NULL;
            }
        }
        UT operator[] (int index){
            Node<UT> *iter = head;
            if(index >= size) throw 1;
            for(int i = 0; i < index; ++i){
                iter = iter -> next;
            }
            return iter -> data;
        }
        Node<UT> GetNode(int index){
            Node<UT> *iter = head;
            if(index >= size) throw 1;
            for(int i = 0; i < index; ++i){
                iter = iter -> next;
            }
            return *iter;
        }
        void AfterPop(){
            Node<UT> *current = head, *previous;            
            int count = 0;
            while(current){
                current -> number = count++;
                previous = current;
                current = current -> next;
            }
            size = count;
        };
        void Pop(int index){
            if(index >= size) throw 1;
            if(index == 0){
                head = head -> next;
                return;
            }
            Node<UT> *current = head, *previous;
            for(int i = 0; i < index; ++i){
                previous = current;
                current = current -> next;
            }
            previous -> next = current -> next;
            AfterPop();
        }

        void Pop_S(int index){
            if(index >= size) throw 1;
            if(index == head -> number){
                head = head -> next;
                return;
            }
            Node<UT> *current = head, *previous;
            while(current -> number != index){
                previous = current;
                current = current -> next;
            }
            previous -> next = current -> next;
        }
        
        Node<UT>* GetHead() const { return head; }
        int GetSize() const { return size; }
};

template <typename UT>
std::ostream& operator<< (std::ostream& out, const List<UT> &obj){
    Node<UT> *iter = obj.GetHead();
    out << "{ \n";
    for(int i = 0; i < obj.GetSize(); ++i){
        SetColor(Red, Black);
        out << (iter -> number);
        SetColor(White, Black);
        out << ": ";
        SetColor(Green, Black);
        out << (iter -> data);
        SetColor(White, Black);
        out << ", ";
        iter = iter -> next;
    }
    out << "\n}";
    return out;
}

template <typename UT>
void RmSubList(List<UT> &obj0, List<UT> &obj1){
    if(obj0.GetSize() <= obj1.GetSize()) throw 1;
    bool eq;
    int pos;
    for(int i = 0; i < obj0.GetSize() - obj1.GetSize(); ++i){
        eq = false;
        if(obj0[i] == obj1[0]){
            eq = true;
            for(int j = i; j < i + obj1.GetSize(); ++j){
                eq = eq && (obj0[j] == obj1[j - i]);
            }
            pos = i;
        }
        if(eq){
            for(int i = pos; i < pos + obj1.GetSize(); ++i){
                obj0.Pop_S(i);
            }
            obj0.AfterPop();        
            i = 0;
        }
    }
}