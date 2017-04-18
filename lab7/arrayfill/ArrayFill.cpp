//
// Created by Kinga on 11.04.2017.
//

#include "ArrayFill.h"

namespace arrays
{
    void FillArray(size_t size, const ArrayFill &filler, std::vector<int> *v) {
        v->clear();
        v->reserve(size);
        for (size_t i = 0; i < size; i++) {
            v->emplace_back(filler.Value(i));
        }
    }

    int UniformFill::Value(int index) const {
        return value_;
    }

    int IncrementalFill::Value(int index) const {
        return step_*index+value_;
    }

    int SquaredFill::Value(int index) const {
        return step_*index*index+value_;
    }

    int RandomFill::Value(int index) const {
        return (*distribution_)(*generate_);
    }
}