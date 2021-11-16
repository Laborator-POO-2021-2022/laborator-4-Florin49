#include "Sticla.hpp"


Sticla::Sticla():Dop(),pret(0),marca(NULL)
{
    
}
Sticla::Sticla(int diametru,int pret, const char* tip,const char* marca): Dop(diametru,tip),pret(pret)
{
    this->marca=new char[strlen(marca)+1];
    strcpy(this->marca,marca);
}
Sticla::Sticla(const Sticla& S):Dop(S)
{
   this->pret=S.pret;
   this->marca=new char[strlen(S.marca)+1];
   strcpy(this->marca,S.marca);
}
Sticla::~Sticla()
{
    delete[] marca;
}
std::ostream& operator<<(std::ostream& o, const Sticla& St)
{
    
    o<<(Dop&)St;
    o<<"Marca sticlei este: "<<St.marca<<std::endl;
    o<<"Sticla are un pret de " <<St.pret<<" lei"<<std::endl<<endl;
   
}
istream& operator>>(istream& i,Sticla& St)
{
    cout<<"Se citesc datele sticlei:\n";
    i>>(Dop&)St;
    cout<<"Cititi pretul sticlei: ";
    i>>St.pret;
    char buf[20];
    cout<<"De asemenea, cititi si marca acesteia: ";
    i>>buf;
    if(St.marca!=NULL)
       delete[] St.marca;
    St.marca=new char[strlen(buf)+1];
    strcpy(St.marca,buf);
    delete[] buf;
    return i;
}
Sticla& Sticla::operator=(const Sticla& s)
{
    (Dop&)(*this)=s;
    if(this!=&s)
    {
        if(marca!=NULL)
            delete[] marca;
        if(s.marca==NULL)
            marca=NULL;
        else
        {
            this->marca=new char[strlen(s.marca)+1];
            strcpy(this->marca,s.marca);
        }
        pret=s.pret;
    }
    return *this;
}
void Switch(Sticla& X, Sticla& Y)
{
     Sticla Z(X);

     if(X.tip !=NULL)
          delete[] X.tip;
     X.tip=new char[strlen(Y.tip)+1];
     strcpy(X.tip,Y.tip);
      
    if(X.marca !=NULL)
          delete[] X.marca;
     X.marca=new char[strlen(Y.marca)+1];
     strcpy(X.marca,Y.marca);

     if(Y.tip !=NULL)
          delete[] Y.tip;
     Y.tip=new char[strlen(Z.tip)+1];
     strcpy(Y.tip,Z.tip);

     if(Y.marca !=NULL)
          delete[] Y.marca;
     Y.marca=new char[strlen(Z.marca)+1];
     strcpy(Y.marca,Z.marca);
    
    X.pret=Y.pret;
    Y.pret=Z.pret;

    X.diametru=Y.diametru;
    Y.diametru=Z.diametru;

}
int Sticla::getPret() const
{
    return this->pret;
}