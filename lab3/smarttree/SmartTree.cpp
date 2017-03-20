//
// Created by agnieszka on 18.03.17.
//

#include "SmartTree.h"
#include <iostream>
#include <sstream>
#include <regex>
namespace datastructures
{
    std::unique_ptr <SmartTree> CreateLeaf(int value)
    {
        std::unique_ptr <SmartTree> leaf=std::make_unique <SmartTree>();        //rezerwuje miejsce
        leaf->value=value;
        leaf->left=nullptr;                                                     //wskaźniki na synów
        leaf->right=nullptr;
        return leaf;
    }

    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree)
    {
       while(tree!= nullptr)
       {
           if(!tree->left)                                  //jak nie ma lewego syna, to left_subtree się nim staje
           {
               tree->left = std::move(left_subtree);        //move przypisuje wskaźnik do innego obiektu
               break;
           }
           else tree->left= std::move(tree);               //jak jest, to idziemy dalej po drzewie
           tree = std::move(left_subtree->tree);
       }
        return tree;
    }

    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree)
    {                                                   //jest to samo tylko dla prawego

        while(tree!= nullptr)
        {
            if(!tree->right)
            {
                tree->right = std::move(right_subtree);
                break;
            }
            else tree->right= std::move(tree);
            tree = std::move(right_subtree->tree);
        }
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) //wyświetla najpierw lewą gałęż od dołu
    {                                                                                      //aż do korzenia
        if(unique_ptr== nullptr)(*out) << "[none] ";                                       //a potem prawą gałąź
      if(unique_ptr!= nullptr)
        {

            PrintTreeInOrder(unique_ptr->left, out);
            (*out) << "[" <<unique_ptr->value <<"] ";
            PrintTreeInOrder(unique_ptr->right, out);
        }
    }

    void PrintTreePreOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) //wyświetla od korzenia
    {                                                                                       ///potem lewa
        if(unique_ptr!= nullptr)
        {
            (*out)<<" ["<<unique_ptr->value;
            PrintTreePreOrder(unique_ptr->left, out);
            if(unique_ptr->left== nullptr) (*out) << " [none]";                             //wyświetla none, jak nie ma lewego syna
            PrintTreePreOrder(unique_ptr->right, out);
            if(unique_ptr->right== nullptr) (*out) << " [none]";                            //a tu dla prawego
            (*out) << "]";
        }

    }
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree)
    {
        std::stringstream ss;
        PrintTreePreOrder(tree, &ss);
        std::string str;
        char wyciagam_ta_glupia_spacje;
        ss.get(wyciagam_ta_glupia_spacje);
        getline(ss, str);                                                                   //wsadza ze strumienia do stringa całe drzewo
        return str;
    }

    int StringtoInt(std::string text)
    {
        std::stringstream ss;
        int value;
        ss<<text;
        ss>>value;
        return value;

    }

    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree) {

//            std::regex pattern{R"(-{0,1}\d{1,})"};
//            std::smatch match;
//            std::regex_match(tree, match, pattern);

            std::unique_ptr<SmartTree> root = std::make_unique<SmartTree>();
            root->left = RestoreTree(tree);
            root->right = RestoreTree(tree);
            return root;

    }

}