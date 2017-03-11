//
// Created by bienking on 07.03.17.
//

#include "SimpleForwardList.h"

ForwardList *CreateNode(int value)
{
    ForwardList *List = new ForwardList();
    List -> value = value;

    // List -> next = nullptr; // generalnie to jest niekonieczne, ale tak dla jasnosci

    return List;
}

ForwardList *PushFront(ForwardList *list, int value)
{
    if (list== nullptr)
    {
        return nullptr;
    }
    ForwardList *node = new ForwardList();
    node -> value = value;
    node -> next = list;

    return node;
}


void Append(ForwardList *list, ForwardList *tail)
{

}

void DestroyList(ForwardList *list)
{
    if (list!= nullptr)
    {
        ForwardList *p1 = list;
        ForwardList *p2 = list->next;
        while (p2!= nullptr)
        {
            delete p1;
            p1=p2;
            p2=p2->next;
        }
        delete p1;

        list = nullptr;
        //delete(list);
    }


}
