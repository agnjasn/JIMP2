//
// Created by agnieszka on 03.06.17.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include "Tree.h"
#include <set>
#include <vector>
#include <algorithm>

namespace tree
{

    template <class T>
    class InOrderTreeIterator
    {
    public:
        InOrderTreeIterator(){}
        InOrderTreeIterator (Tree<T>* arg) : root_(arg)
                {
                        InsertValues(root_);
                std::reverse(values_.begin(), values_.end());
                }
        void InsertValues(Tree<T> *tree)
        {
            if(tree->Left()!= nullptr) InsertValues(tree->Left());
            values_.push_back(tree->Value());
            if(tree->Right()!= nullptr) InsertValues(tree->Right());

        }

        T operator*() { return values_.back();}

        void operator++()
        {
            values_.pop_back();
        }
        bool operator!=(const InOrderTreeIterator &it2) const
        {
            return values_!=it2.values_;
        }

    private:
        Tree<T>* root_;
        std::vector<T> values_;

    };

    template <class T>
    class InOrderTreeView
    {
    public:
        InOrderTreeView<T>( Tree<T>* tree) : tree_(tree){}
        InOrderTreeIterator<T> begin() {return InOrderTreeIterator<T>{tree_};}
        InOrderTreeIterator<T> end() {return InOrderTreeIterator<T>();}

    private:
        Tree<T>* tree_;

    };

    template <class T>
    class PreOrderTreeIterator
    {
    public:
        PreOrderTreeIterator(){}
        PreOrderTreeIterator (Tree<T>* arg) : root_(arg)
        {
            InsertValues(root_);
            std::reverse(values_.begin(), values_.end());
        }
        void InsertValues(Tree<T> *tree)
        {
            values_.push_back(tree->Value());
            if(tree->Left()!= nullptr) InsertValues(tree->Left());
            if(tree->Right()!= nullptr) InsertValues(tree->Right());

        }

        T operator*() { return values_.back();}

        void operator++()
        {
            values_.pop_back();
        }
        bool operator!=(const PreOrderTreeIterator &it2) const
        {
            return values_!=it2.values_;
        }

    private:
        Tree<T>* root_;
        std::vector<T> values_;

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
    class PostOrderTreeIterator
    {
    public:
        PostOrderTreeIterator(){}
        PostOrderTreeIterator (Tree<T>* arg) : root_(arg)
        {
            InsertValues(root_);
            std::reverse(values_.begin(), values_.end());
        }
        void InsertValues(Tree<T> *tree)
        {
            if(tree->Left()!= nullptr) InsertValues(tree->Left());
            if(tree->Right()!= nullptr) InsertValues(tree->Right());
            values_.push_back(tree->Value());
        }

        T operator*() { return values_.back();}

        void operator++()
        {
            values_.pop_back();
        }
        bool operator!=(const PostOrderTreeIterator &it2) const
        {
            return values_!=it2.values_;
        }

    private:
        Tree<T>* root_;
        std::vector<T> values_;

    };

    template <class T>
    class PostOrderTreeView
    {
    public:
        PostOrderTreeView<T>( Tree<T>* tree) : tree_(tree){}
        PostOrderTreeIterator<T> begin() {return PostOrderTreeIterator<T>{tree_};}
        PostOrderTreeIterator<T> end() {return PostOrderTreeIterator<T>();}

    private:
        Tree<T>* tree_;

    };



    template <class T>
    PreOrderTreeView<T> PreOrder( Tree<T>* tree)
    {
        return PreOrderTreeView<T>(tree);
    }

    template <class T>
    InOrderTreeView<T> InOrder( Tree<T>* tree)
    {
        return InOrderTreeView<T>(tree);
    }

    template <class T>
    PostOrderTreeView<T> PostOrder( Tree<T>* tree)
    {
        return PostOrderTreeView<T>(tree);
    }

}


#endif //JIMP_EXERCISES_TREEITERATORS_H
