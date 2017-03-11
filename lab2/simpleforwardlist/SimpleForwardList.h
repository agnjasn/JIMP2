//
// Created by bienking on 07.03.17.
//

#ifndef JIMP_EXERCISES_SIMPLEFORWARDLIST_H
#define JIMP_EXERCISES_SIMPLEFORWARDLIST_H

#include <iostream>



struct ForwardList
{
    int value = 0;
    ForwardList *next= nullptr;
};



ForwardList *CreateNode(int value);
void DestroyList(ForwardList *list);



#endif //JIMP_EXERCISES_SIMPLEFORWARDLIST_H
