//
// Created by Kinga on 23.05.2017.
//
#include "Sumator.h"
#include <iostream>
#include <vector>
int main (void)
{
  //  std::cout<<Sum<std::string>("sff","ddd");
    int p=3;
    int* ptr=&p;
    std::vector<double> vec {3.4,5.,8.8};
    std::cout<<Value(ptr)<<std::endl;
    std::vector<double>::iterator ptr2=vec.begin();
    std::cout<<Value(ptr2)<<std::endl;

    Room r(2, "8", Room::Type::COMPUTER_LAB);
    Repository<Room> repo;
    repo.repository_.push_back(r);
    std::cout<<repo[2]<<std::endl;
    std::cout<<repo.NextId(4)<<std::endl;
    std::cout<<Mean(vec);

    return 0;
}