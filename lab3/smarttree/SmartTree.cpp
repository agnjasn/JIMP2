//
// Created by agnieszka on 18.03.17.
//

#include "SmartTree.h"
#include <iostream>
#include <sstream>

namespace datastructures
{
    std::unique_ptr <SmartTree> CreateLeaf(int value)
    {
        std::unique_ptr <SmartTree> leaf=std::make_unique <SmartTree>();        //rezerwuje miejsce
        leaf->value=value;
        leaf->left=nullptr;      //wskaźniki na synów
        leaf->right=nullptr;
        return leaf;
    }

    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree)
    {
       while(tree!= nullptr)
       {
           if(!tree->left)    //jak nie ma lewego syna, to left_subtree się nim staje
           {
               tree->left = std::move(left_subtree);     //move przypisuje wskaźnik do innego obiektu
               break;
           }
           else tree->left= std::move(tree);         //jak jest, to idziemy dalej po drzewie
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
            if(unique_ptr->left== nullptr) (*out) << " [none]";      //wyświetla none, jak nie ma lewego syna
            PrintTreePreOrder(unique_ptr->right, out);
            if(unique_ptr->right== nullptr) (*out) << " [none]";    //a tu dla prawego
            (*out) << "]";
        }

    }
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree)
    {
        std::stringstream ss;
        PrintTreePreOrder(tree, &ss);
        std::string str;
        char wyciagam_ta_glupia_spacje;
        ss.get(wyciagam_ta_glupia_spacje); //wyciagam ze strumienia jednego chara
        getline(ss, str);        //wsadza ze strumienia do stringa całe drzewo
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

    std::string DoString(std::string &tree) //robi z tego brzydkiego ciagu taki z #
    {
        std::string tmp="";
        for(int i=0; i<tree.length(); i++)
        {
            if(tree[i]>='0' && tree[i]<='9' || tree[i]=='-' || tree[i]==' ')  //dodałam - żeby nie zgubiło ujemnej liczby
            {
                tmp+=tree[i];
            }
            else if(tree[i]=='n')
            {
                tmp+="#";
                i+=4;
            }
        }
        return tmp;
    }

    std::unique_ptr <SmartTree> HelpWithRestore(std::istringstream &iss)  //tu sie dzieje magia
    {
        std::string value;
        iss >> value;  //wpisuje do stringa wartosci
        if (value == "#") return nullptr; //zwracam nullptr, czyli oznaczenie liścia
        std::unique_ptr<SmartTree> root = CreateLeaf(StringtoInt(value));  //tworze liść od wartości skonwertowanej na int
        root->left = HelpWithRestore(iss);  //wywołuje ta funkcje dla synów
        root->right = HelpWithRestore(iss);
        return root;
    }
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree) { //tutaj sie tylko wywołuje funkcje
        std::string str=tree;
        std::string tmp=DoString(str);   //zmienia mi na ten ładny ciąg z #
        std::istringstream iss(tmp);      //wpisuje stringa do strumienia
        return HelpWithRestore(iss);      //i wysyłam go do innej funkcji, którą zwróce do wskaźnika

    }
        // http://media.tumblr.com/tumblr_md3n9xgTiA1qhnsxb.gif
}