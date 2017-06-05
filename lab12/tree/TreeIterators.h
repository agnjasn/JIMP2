//
// Created by agnieszka on 03.06.17.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include "Tree.h"

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
            return root_;
        }
        bool operator!=(const PreOrderTreeIterator &it2) const
        {
            if(root_->Value()!=it2.root_->Value()) return true;
            else return false;
        }

    private:
        Tree<T>* root_;
        
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
        return PreOrderTreeView<T>{tree};
    }

}


#endif //JIMP_EXERCISES_TREEITERATORS_H
