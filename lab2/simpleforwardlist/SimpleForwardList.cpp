//
// Created by bienking on 07.03.17.
//

#include "SimpleForwardList.h"

ForwardList *CreateNode(int value)
{
    ForwardList *List = new ForwardList();

    List -> value = value;

    List -> next = nullptr;

    return List;
}

void DestroyList(ForwardList *list)
{
    delete(list);


}
