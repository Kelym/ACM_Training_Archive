// Source: http://sunmoon-template.blogspot.com/2015/01/avl-tree-avl.html

template<typename T>
class avl_tree{
private:
    struct node{
        node *ch[2];
        int size, h;
        T data;
        inline void up(){h=ch[ ch[0]->h < ch[1]->h ]->h+1;}
        node(const T&d):size(1),h(1),data(d){}
        node():size(0),h(0){ch[0]=ch[1]=this;}
    }*nil,*root;

    inline void rotate(node *&a,bool d){
        node *b=a;
        a=a->ch[!d];
        b->ch[!d]=a->ch[d];
        a->ch[d]=b;
        a->size=b->size;
        b->size=b->ch[0]->size + b->ch[1]->size + 1;
        b->up(),a->up();
    }
    inline void balanced(node *&o,bool d){
        if(o->ch[d]->h-o->ch[!d]->h>1){
            node *&t=o->ch[d];
            if(t->ch[d]->h > t->ch[!d]->h) rotate(o,!d);
            else rotate(o->ch[d],d),rotate(o,!d);
        }else o->up();
    }
    void insert(node *&o,const T &data){
        if(!o->size){
            o=new node(data);
            o->ch[0]=o->ch[1]=nil;
        }else{
            o->size++;
            bool d=o->data<data;
            insert(o->ch[d],data);
            balanced(o,d);
        }
    }
    bool erase(node *&o,const T &data){
        if(!o->size)return 0;
        if(o->data==data){
            if(!o->ch[0]->size||!o->ch[1]->size){
                node *t=o;
                o=o->ch[0]->size?o->ch[0]:o->ch[1];
                delete t;
            }else{
                o->size--;
                node *tmd=o->ch[1];
                while(tmd->ch[0]->size)tmd=tmd->ch[0];
                o->data=tmd->data;
                erase(o->ch[1],tmd->data);
                balanced(o,0);
            }return 1;
        }
        bool d=o->data<data;
        if(erase(o->ch[d],data)){
            o->size--,balanced(o,!d);
            return 1;
        }else return 0;
    }
    void clear(node *&o){
        if(o->size)clear(o->ch[0]),clear(o->ch[1]),delete(o);
    }

public:
    avl_tree():nil(new node),root(nil){}
    ~avl_tree(){clear(root),delete nil;}
    inline void clear() {clear(root),root=nil;}
    inline void insert(const T &data) {insert(root,data);}
    inline bool erase(const T &data) {return erase(root,data);}
    inline bool find(const T&data){
        node *o=root;
        while(o->size && o->data!=data) o=o->ch[o->data<data];
        return o->size;
    }
    inline int rank(const T&data){
        int cnt=0;
        for(node *o=root;o->size;)
            if(o->data<data)cnt+=o->ch[0]->size+1,o=o->ch[1];
            else o=o->ch[0];
        return cnt;
    }
    inline const T&kth(int k){
        for(node *o=root;;)
            if(k<=o->ch[0]->size)o=o->ch[0];
            else if(k==o->ch[0]->size+1)return o->data;
            else k-=o->ch[0]->size+1,o=o->ch[1];
    }
    inline const T&operator[](int k){
        return kth(k);
    }
    inline const T&preorder(const T&data){
        node *x=root,*y=0;
        while(x->size)
            if(x->data<data)y=x,x=x->ch[1];
            else x=x->ch[0];
        if(y)return y->data;
        return data;
    }
    inline const T&successor(const T&data){
        node *x=root,*y=0;
        while(x->size)
            if(data<x->data)y=x,x=x->ch[0];
            else x=x->ch[1];
        if(y)return y->data;
        return data;
    }
    inline int size(){return root->size;}
    inline int height(){return root->h;}
};