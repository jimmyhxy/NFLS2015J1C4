//This file has no copyright
//written by nicklcy on December 4th 2015

#include <cstdlib>
using namespace std;

template<typename T>
struct vector{
    struct Node{
        T num;
        Node* left,right;
    };
    Node *front,*end;int sz;
    void clear(){
        front=NULL;end=NULL;sz=0;
    }
    vector(){
        clear();
    }
    vector operator+(const vector n){
        end->right=n.front;end=n.end;sz+=n.sz;
        return *this;
    }
    vector operator+=(const vector n){
        return *this+n;
    }
    void push_back(T n){
        Node* t=new Node;
        t->num=n;t->left=end;t->right=NULL;if(end!=NULL)end->right=t;end=t;
        sz++;
        if(sz==1) front=t;
    }
    void pop_back(){
    	Node *t=end;
    	end=t->left;
        free(t);
        sz--;
    }
    int size(){
        return sz;
    }
    T operator[](const int n)const{
        if(n>sz/2){
            Node *t=end;
            for(int i=sz-1;i>n;i--) t=t->left;
            return t->num;
        }else{
            Node *t=front;
            for(int i=0;i<n;i++) t=t->right;
            return t->num;
        }
    }
};
