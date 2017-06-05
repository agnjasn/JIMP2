//
// Created by agnieszka on 03.06.17.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include "Tree.h"
#include <set>

namespace tree
{

    template <class T>
    class InOrderTreeIterator
    {

    };

    template <class T>
    class InOrderTreeView
    {

    };

    template <class T>
    class PreOrderTreeIterator
    {
    public:
        PreOrderTreeIterator(){}
        PreOrderTreeIterator (Tree<T>* arg) : root_(arg){}
        T operator*() { return root_->Value();}
        Tree<T>*operator++()
        {
           // auto tmp=root_;
            if (root_->Parent()== nullptr && done.find(root_->Value())==done.end()) //jesli NIE MA korzenia w zbiorze
            {
                done.insert(root_->Value()); // dodaj do zbioru
            }
            if (root_->Left()!= nullptr && done.find(root_->Left()->Value())==done.end())
            {
                root_=root_->Left();
                done.insert(root_->Value());
                return root_;
            }
            if (root_->Right()!= nullptr && done.find(root_->Right()->Value())==done.end())
            {
                root_=root_->Right();
                done.insert(root_->Value());
                return root_;
            }
            if(root_->Parent()== nullptr && done.find(root_->Left()->Value())!=done.end() && done.find(root_->Right()->Value())!=done.end())
            {
                return root_;

            }
            root_=root_->Parent();
            return ++(*this);



        }
        bool operator!=(const PreOrderTreeIterator &it2) const
        {
            if(root_!=it2.root_) return true;
            else return false;
//            return false;
        }

    private:
        Tree<T>* root_;
        std::set<T> done;

    };



    template <class T>
    class PreOrderTreeView
    {
    public:
        PreOrderTreeView<T>( Tree<T>* tree) : tree_(tree){}
        PreOrderTreeIterator<T> begin() {return PreOrderTreeIterator<T>{tree_};}
        PreOrderTreeIterator<T> end() {return PreOrderTreeIterator<T>();}

    private:
         Tree<T>* tree_;

    };


    template <class T>
    PreOrderTreeView<T> PreOrder( Tree<T>* tree)
    {
        return PreOrderTreeView<T>(tree);
    }

}


#endif //JIMP_EXERCISES_TREEITERATORS_H
