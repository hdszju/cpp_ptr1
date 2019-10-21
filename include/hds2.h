//
// Created by hds on 10/21/19.
//

#ifndef CPP_HDS2_H
#define CPP_HDS2_H

#include <iostream>
#include <memory>



namespace hds2 {


    class Parent;
    class Child;

    class Parent {
    private:
//        Child* myChild;
        std::shared_ptr<Child> myChild;
    public:
        void setChild(std::shared_ptr<Child> ch){
            this->myChild = ch;
        }
        void doSomething(){

        }

        ~Parent(){
            std::cout << "shared ptr delete parent" << std::endl;
            std::cout << "this->myChild.use_count() = " << this->myChild.use_count() << std::endl;
//            delete myChild;
        }
    };

    class Child {
    private:
//        Parent* myParent;
        std::shared_ptr<Parent> myParent;
    public:
        void setParent(std::shared_ptr<Parent> p){
            this->myParent = p;
        }

        void doSomething(){

        }

        ~Child(){
            std::cout << "shared ptr delete child" << std::endl;
            std::cout << "this->myParent.use_count() = " << this->myParent.use_count() << std::endl;
//            delete myParent;
        }
    };

    void test() {
        {
            std::shared_ptr<Parent> p(new Parent);
            std::shared_ptr<Child> c(new Child);
            p->setChild(c);
            c->setParent(p);
        }

    }
}//namespace hds2

#endif //CPP_HDS2_H
