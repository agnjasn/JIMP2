//
// Created by  on 25.04.2017.
//

#ifndef JIMP_EXERCISES_PESEL_H
#define JIMP_EXERCISES_PESEL_H

#include <string>
#include <iostream>
#include <exception>
namespace academia {
    class AcademiaDataValidationError: public std::runtime_error{
    public:
        AcademiaDataValidationError(const std::string &s ) : std::runtime_error::runtime_error(s){

        };
    };

    class InvalidPeselLength: public AcademiaDataValidationError{
    public:
        InvalidPeselLength(std::string s, int value);
    };

    class InvalidPeselCharacter: public AcademiaDataValidationError {
    public:
        InvalidPeselCharacter(std::string s);
    };

    class InvalidPeselChecksum: public AcademiaDataValidationError
    {
    public:
        InvalidPeselChecksum(std::string pesel, int check_sum);
    };

    class Pesel {
    public:
        Pesel(std::string s);
        virtual ~Pesel();
    private:
        std::string pes;
    };
}


#endif //JIMP_EXERCISES_PESEL_H
