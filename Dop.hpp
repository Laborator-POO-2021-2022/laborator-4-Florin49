#ifndef DOP_HPP
#define DOP_HPP

#include <iostream>
#include <cstring>
using namespace std;

class Dop
{
protected:
      int diametru;
      char *tip;
public:

   Dop();
   Dop(int,const char*);
   Dop(const Dop&);
   ~Dop();
    
   Dop& operator=(const Dop&);
   friend std::ostream& operator<<(std::ostream&, const Dop&);
   friend std::istream& operator>>(std::istream&,Dop&);
   int getDiametru() const;
};

#endif