#include <bits/stdc++.h>
using namespace std;

template<typename T>
class pq {
private:
    int size, height;
    struct Node {
        T value;
        Node *l, *r, *parent;
        Node(T val) : value(val), l(nullptr), r(nullptr), parent(nullptr) {}
    };
    Node* root;

public:
    pq() : root(nullptr), size(0), height(0) {}

    void insert(T value) {
        size++;
        if ((size & (size - 1)) == 0) height++;
        if (size == 1) {
            root = new Node(value);
            return;
        }

        Node* now = root;
        for (int i = height - 2; i >= 0; i--) {
            if (((1 << i) & size) == 0) {
                if (!now->l) now->l = new Node(0);
                now->l->parent = now;
                now = now->l;
            } else {
                if (!now->r) now->r = new Node(0);
                now->r->parent = now;
                now = now->r;
            }
        }
        now->value = value;

        while (now->parent && now->value < now->parent->value) {
            swap(now->value, now->parent->value);
            now = now->parent;
        }
    }

    void pop() {
        if (size == 0) return;
        Node* now = root;

        for (int i = height - 2; i >= 0; i--) {
            if (((1 << i) & size) == 0) {
                now = now->l;
            } else {
                now = now->r;
            }
        }

        if (size > 1) {
            swap(root->value, now->value);
        }

        if (now->parent) {
            if (now == now->parent->l) now->parent->l = nullptr;
            else now->parent->r = nullptr;
        }
        delete now;

        if ((size & (size - 1)) == 0) height--;
        size--;

        now = root;
        while (now && (now->l || now->r)) {
            Node* smallest = now;
            if (now->l && now->l->value < smallest->value) smallest = now->l;
            if (now->r && now->r->value < smallest->value) smallest = now->r;
            if (smallest == now) break;
            swap(now->value, smallest->value);
            now = smallest;
        }
    }

    T top() {
        return root->value;
    }

    bool empty() const{
        return size == 0;
    }
};
