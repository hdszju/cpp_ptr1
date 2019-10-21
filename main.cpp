#include <iostream>
#include <memory>

namespace hds {
    void test(){
//    std::cout << "Hello, World!" << std::endl;
        int a = 10;
        std::shared_ptr<int> ptra = std::make_shared<int>(a);
        std::shared_ptr<int> ptr2(ptra);
        std::cout << "ptra.use_count() = " << ptra.use_count() << std::endl;

        int b = 20;
        int *pb = nullptr;
        std::shared_ptr<int> ptrb = std::make_shared<int>(b);
        ptr2 = ptrb;
        pb = ptrb.get();


        std::cout << "ptra.use_count() = " << ptra.use_count() << std::endl;
        std::cout << "ptrb.use_count() = " << ptrb.use_count() << std::endl;

        //unique_ptr
        {
            std::unique_ptr<int> uptr(new int(10));
//    std::unique_ptr<int> uptr2(uptr);  cannot be copy
//    std::unique_ptr<int> uptr3 = uptr;  cannot be assign
            std::unique_ptr<int> uptr3 = std::move(uptr);  //only can be move
        }
        //超過uptr的作用域，內存釋放
// weak_ptr
        {
            std::shared_ptr<int> sh_ptr = std::make_shared<int>(10); //new int(10)
            std::cout << "sh_ptr.use_count() = " << sh_ptr.use_count() << std::endl;


            std::weak_ptr<int> w_ptr(sh_ptr);
            std::cout << "sh_ptr.use_count() = " << sh_ptr.use_count() << std::endl;

            if (!w_ptr.expired()){
//                std::shared_ptr<int>
                auto sh_ptr2 = w_ptr.lock(); //get a useable shared_ptr obj
                *sh_ptr = 100;

                std::cout << "w_ptr.use_count() = " << w_ptr.use_count() << std::endl;


            }


        }

    } //func test1



}// namespace hds

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

        delete p;

    }
}//namespace hds1

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


int main() {
    std::cout << "------------hds.test()-----------------" << std::endl;
    hds::test();
    std::cout << "------------hds1.test()-----------------" << std::endl;
    hds1::test();
    std::cout << "------------hds2.test()-----------------" << std::endl;
    hds2::test();
    return 0;
}
