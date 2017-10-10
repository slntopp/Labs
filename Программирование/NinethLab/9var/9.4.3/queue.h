#pragma once

struct Node {
    char* name;
    char* surname;
    int age;
    bool sex;
    int course;
    float midmark;
    Node *next;
    Node(char* _name, char* _surname, int _age, bool _sex, int _course, int _midmark): name(_name), surname(_surname), age(_age), sex(_sex), course(_course), midmark(_midmark), next(NULL) {};
    Node(){
        name = new char[16];
        surname = new char[16];
        for(int i = 0; i < 16; ++i) name[i] = surname[i] = '\0';    
    };
    void operator= (Node obj){
        name = obj.name;
        surname = obj.surname;
        age = obj.age;
        sex = obj.sex;
        course = obj.course;
        midmark = obj.midmark;
        next = NULL;
    }
};

std::ostream& operator<< (std::ostream& out, Node obj){
    out << obj.name << " " << obj.surname << ". " << obj.age << " лет, " << (obj.sex ? "М., " : "Ж., ") << obj.course << " курс. Средний балл: " << obj.midmark;
    return out;
}

std::ifstream& operator>> (std::ifstream& in, Node &obj){
    int i = 0;
    char ch;
    while((ch = in.get()) != ' ') obj.name[i++] = ch;
    i = 0;
    while((ch = in.get()) != ' ') obj.surname[i++] = ch;
    in >> obj.age >> obj.sex >> obj.course >> obj.midmark;
    return in;
}

std::istream& operator>> (std::istream& in, Node &obj){
    int i = 0;
    char ch;
    while((ch = in.get()) != ' ') obj.name[i++] = ch;
    i = 0;
    while((ch = in.get()) != ' ') obj.surname[i++] = ch;
    in >> obj.age >> obj.sex >> obj.course >> obj.midmark;
    return in;
}

class Queue {
    private:
        Node *head;
        int size;
    public:
        Queue(): head(NULL), size(0) {};
        ~Queue();
        void Push(Node item);
        Node Pop();
        Node Read();
        Node ReadLast();  
        int Size(){ return size; }      
        int ExcP();
};

Queue::~Queue(){
    Node *current = head;
    while(head){
        current = head;
        head = head -> next;
        delete current;
    }
}

void Queue::Push(Node item){
    Node *current = head;
    Node *previous = NULL;
    Node *buff;

    while(current){
        previous = current;
        current = current -> next;
    }

    buff = new Node;
    *buff = item;

    if(previous){
        buff -> next = previous -> next;
        previous -> next = buff;
    } else {
        head = buff;
        head -> next = NULL;
    }
    ++size;
}

Node Queue::Read(){
    Node buff;
    if(head){
        buff = *head;
    } else {
        std::cout << "Ошибочное обращение!" << std::endl;
    }
    return buff;
}

Node Queue::Pop(){
    Node buff;
    Node *old = head;
    if(head){
        buff = *old;
        head = head -> next;
        delete old;
    }
    --size;
    return buff;
}

Node Queue::ReadLast(){
    Node buff;
    Node *current, *previous = NULL;
    if(head){
        current = head;
        while(current){
            previous = current;
            current = current -> next;
        }
        buff = *previous;
    } else {
        std::cout << "Ошибочное обращение!" << std::endl;
    }
    return buff;
}

int Queue::ExcP(){
    int result = 0; 
    Node *current, *previous = NULL;
    if(head){
        current = head;
        while(current){
            if(current -> midmark >= 9){
                ++result;
            }
            previous = current;
            current = current -> next;
        }
    } else {
        std::cout << "Ошибочное обращение!" << std::endl;
    }
    return result;
}