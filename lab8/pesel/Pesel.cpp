//
// Created by  on 25.04.2017.
//

#include "Pesel.h"
#include <string>

namespace academia
{
    Pesel::Pesel(std::string s) {
        if(s.length()!=11) throw InvalidPeselLength(s, s.length());
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]<'0' || s[i]>'9') throw InvalidPeselCharacter(s);
        }
        int sum= 9*(s[0]-'0') + 7*(s[1]-'0') + 3*(s[2]-'0') + 1*(s[3]-'0') + 9*(s[4]-'0') + 7*(s[5]-'0') + 3*(s[6]-'0') + 1*(s[7]-'0') + 9*(s[8]-'0') + 7*(s[9]-'0');
        if(sum%10!=s[10]-'0') throw InvalidPeselChecksum(s, sum);

    }

    Pesel::~Pesel() {

    }

    InvalidPeselLength::InvalidPeselLength(std::string s, int value) : AcademiaDataValidationError("Invalid PESEL("+s+") length: "+ std::to_string(value))  {

    }

    InvalidPeselCharacter::InvalidPeselCharacter(std::string s) : AcademiaDataValidationError("Invalid PESEL("+s+") character set") {}

    InvalidPeselChecksum::InvalidPeselChecksum(std::string s, int value) : AcademiaDataValidationError("Invalid PESEL("+s+") checksum: "+std::to_string(value)) {

    }

//    AcademiaDataValidationError::AcademiaDataValidationError(const std::string &s) : std::runtime_error::runtime_error(s) {
//
//    }
}

