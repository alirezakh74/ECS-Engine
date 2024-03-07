#ifndef CNAME_H
#define CNAME_H

#include <string>

class CName
{
public:
    std::string name = "";
    CName() {};
    CName(const std::string& n) : name(n) {}
};


#endif