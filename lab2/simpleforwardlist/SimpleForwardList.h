//
// Created by bienking on 07.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H

#include <iostream>

struct ForwardList{};

struct Node
{
int Value = 0;
struct Node *next = nullptr;
};

ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);



#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
