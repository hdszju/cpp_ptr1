//
// Created by hds on 10/21/19.
//

#ifndef CPP_HDS1_H
#define CPP_HDS1_H

#include <iostream>
#include <memory>

namespace hds1 {


    class Parent;
    class Child;

    class Parent {
    private:
        Child* myChild;
    public:
        void setChild(Child * ch){
            this->myChild = ch;
        }
        void doSomething(){

        }

        ~Parent(){
            std::cout << "delete parent" << std::endl;
            delete myChild;
        }
    };

    class Child {
    private:
        Parent* myParent;
    public:
        void setParent(Parent * p){
            this->myParent = p;
        }

        void doSomething(){

        }

        ~Child(){
            std::cout << "delete child" << std::endl;
            delete myParent;
        }
    };

    void test(){
        Parent* p = new Parent;
        Child* c = new Child;
        p->setChild(c);
        c->setParent(p);
//        this id wired        delete p or c the output different
        delete c;
//        delete p;

    }
}//namespace hds1

#endif //CPP_HDS1_H
