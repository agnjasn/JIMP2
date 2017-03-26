//
// Created by agnieszka on 26.03.17.
//

#ifndef JIMP_EXERCISES_VIEW_H
#define JIMP_EXERCISES_VIEW_H
#include <experimental/optional>
#include <string>
#include "SimpleJson.h"
namespace nets
{
    class View
    {
        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;
    };
}

#endif //JIMP_EXERCISES_VIEW_H
