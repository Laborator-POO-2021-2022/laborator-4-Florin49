#ifndef STICLA_HPP
#define STICLA_HPP

#include "Dop.hpp"

class Sticla: public Dop 
{
    int pret;
    char *marca;
public:
    Sticla();
    Sticla(int, int, const char*, const char*);
    Sticla(const Sticla&);
    ~Sticla();

    friend std::ostream& operator<<(std::ostream&, const Sticla&);
    friend std::istream& operator>>(istream&, Sticla&);
    friend void Switch(Sticla&, Sticla&);
    Sticla& operator=(const Sticla&);
    int getPret() const;
};

#endif