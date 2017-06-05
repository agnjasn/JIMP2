//
// Created by kb on 30.05.17.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <iostream>
#include <memory>
#include <initializer_list>
namespace tree
{
    template<class T>
    class Tree{
    public:
        Tree(const T &el) : value(el){left=nullptr;
        right=nullptr;}
        Tree(){}
        ~Tree(){}
        void Insert(const T &e);
        bool Find(const T &e);
        T Value();
        size_t Depth();
        size_t Size();
        Tree<T>* Root(){return this;}
        bool operator<(const Tree<T> &value)
        {
            if(this->value<value) return true;
                    else return false;
        }
    private:
        //std::unique_ptr<T> root;
        std::unique_ptr<Tree<T>> left;
        std::unique_ptr<Tree<T>> right;
        T value;
        size_t size=1;
    };

    template<class T>
    void Tree<T>::Insert(const T &e){
            Tree<T>* r_ptr=this;
        while (true)
        {
            if(r_ptr->Value()<e && r_ptr->right== nullptr)
            {
                r_ptr->right=std::make_unique<Tree<T>>(e);
                break;

            }

            else if (!(r_ptr->Value()<e) && r_ptr->left== nullptr)
            {
                r_ptr->left=std::make_unique<Tree<T>>(e);
                break;

            }


            if(r_ptr->Value()<e) r_ptr=r_ptr->right.get();
            else r_ptr=r_ptr->left.get();
        }

        size++;
    }

    template<class T>
    bool Tree<T>::Find(const T &e) {
        return false;
    }
    template<class T>
    size_t Tree<T>::Depth() {
        if(left!= nullptr && right!=nullptr) return 1+std::max(left->Depth(), right->Depth());
        else {
            if(left)
            {
                return 1+left->Depth();
            }
            if(right)
            {
                return 1+right->Depth();
            }
            return 1;
        }

    }
    template<class T>
    size_t Tree<T>::Size() {
        return size;
    }
    template<class T>
    T Tree<T>::Value(){
        return value;
    }
}

#endif //JIMP_EXERCISES_TREE_H
