#include "Dop.hpp"

Dop::Dop():diametru(0),tip(NULL)
{
    
}
Dop::Dop(int dm, const char* t):diametru(dm)
{
     this->tip=new char[strlen(t)+1];
     strcpy(this->tip,t);
}
Dop::Dop(const Dop& dop)
{ 
    
    tip=NULL;
    *this=dop;
}
Dop::~Dop()
{
    delete[] tip;
}
Dop& Dop::operator= (const Dop& D)
{
    if(this!=&D)
    {  
         if(this->tip!=NULL)
             delete[] this->tip;
         if(D.tip==NULL)
             this->tip=NULL;
         else
             {
              this->tip = new char[strlen(D.tip) + 1];
			   strcpy(this->tip,D.tip);
		     }
         this->diametru=D.diametru;
     }
     return *this;
}
ostream& operator<<(ostream& o, const Dop& dOp)
{
     o<< "Diametru: "<< dOp.diametru<<endl;
     o<< "Tip: "<< dOp.tip<<endl;
     
     return o; 
}
istream& operator>>(istream& i,Dop& dOp)
{
    cout<<"Citti valoarea diametrului dopului: ";
    i>>dOp.diametru;
	char buffer[20];
    cout<<"Tipul dopului? ";
	i>>buffer;
    if(dOp.tip!=NULL)
          delete[] dOp.tip;
    dOp.tip=new char[strlen(buffer)+1];
    strcpy(dOp.tip,buffer);
    delete[] buffer;
	return i;
}
int Dop::getDiametru() const
{
    return this->diametru;
}