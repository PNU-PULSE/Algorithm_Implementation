template<typename T>
class Stack{
    class Node{
    public:
        T value;
        Node* prev;
        Node(T value): value(value), prev(nullptr) {}
        ~Node(){}
        T getValue() {return value;}
        Node* getPrev() {return prev;}
    };
    Node* tp;
    int cnt;

public:
    Stack(): tp(nullptr), cnt(0) {}

    void push(T value){
        Node* x = new Node(value);
        x->prev = tp; tp = x; cnt++;
    }
    void pop(){
        Node* p = tp; tp = tp->prev; delete(p); cnt--;
    }
    T top(){
        return tp->getValue();
    }
    int empty(){
        return cnt == 0;
    }
    int size(){
        return cnt;
    }
};
