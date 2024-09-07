template<typename T>
class Deque{
    class Node{
    public:
        T value;
        Node* nxt;
        Node(T value): value(value) {}
        ~Node(){

        }
    };
    Node* fr;
    Node* ed;
    int sz;
public:
    Queue(): sz(0) {fr = nullptr; ed = nullptr;}
    void push(T value){
        Node* p = new Node(value);
        if (!sz){
            fr = p; ed = p;
        }
        else{
            ed->nxt = p; ed = ed->nxt;
        }
        sz++;
    }
    void pop(){
        if (sz){Node* p = fr; fr = fr->nxt; delete(p);}
        else{return;}
        sz--;
    }
    int size() {return sz;}
    int empty() {return ((sz == 0) ? 1 : 0);}
    int front() {return fr->value;}
    int back()   {return ed->value;}
};
