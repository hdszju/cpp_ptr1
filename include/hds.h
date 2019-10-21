//
// Created by hds on 10/21/19.
//

#ifndef CPP_HDS_H
#define CPP_HDS_H

#include <iostream>
#include <memory>

namespace hds {
    void test(){
//        std::cout << "Hello, World!"<< std::endl;
        int a = 10;
        std::cout << "Hello, World!" << a << std::endl;
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


#endif //CPP_HDS_H
