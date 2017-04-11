//
// Created by Kinga on 11.04.2017.
//

#ifndef JIMP_EXERCISES_ARRAYFILL_H
#define JIMP_EXERCISES_ARRAYFILL_H

#include <iostream>
#include <vector>
#include <memory>
#include <random>
namespace arrays
{
    class ArrayFill {
    public:
        virtual int Value(int index) const =0;
    };

    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v);

    class UniformFill : public ArrayFill {
    public:
        UniformFill(int value = 0) : value_{value} {}
        virtual int Value(int index) const override;
    private:
        int value_;
    };

    class IncrementalFill: public ArrayFill {
    public:
        IncrementalFill(int value = 0, int step= 1) : value_{value}, step_{step} {}
        virtual int Value(int index) const override;
    private:
        int value_;
        int step_;
    };

    class SquaredFill: public ArrayFill {
    public:
        SquaredFill(int step = 1, int value = 0) : value_{value}, step_{step} {}
        virtual int Value(int index) const override;
    private:
        int value_;
        int step_;
    };

    class RandomFill: public ArrayFill {
    public:
        RandomFill(std::unique_ptr<std::default_random_engine> generate,
                   std::unique_ptr<std::uniform_int_distribution<int>> distribution) :
                generate_{move(generate)}, distribution_{move(distribution)} {}
        virtual int Value(int index) const override;
    private:
        int value_;
        std::unique_ptr<std::default_random_engine> generate_;
        std::unique_ptr<std::uniform_int_distribution<int>> distribution_;
    };

}


#endif //JIMP_EXERCISES_ARRAYFILL_H
