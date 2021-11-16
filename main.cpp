#include "Sticla.hpp"

int main()
{ 
    Sticla *S;
    S=new Sticla[6];
    int i,j;
    for(i=0;i<6;i++)
        cin>>S[i];
    for(i=0;i<6;i++)
        cout<<endl<<"Sticla "<<i<<":"<<endl<<endl<<S[i];
    cout<<"Se ordoneaza sticlele crecator dupa pret: "<<endl<<endl;
    for(i=0;i<5;i++)
         for(j=i+1;j<6;j++)
             if( S[i].getPret() > S[j].getPret() )
                 Switch(S[i],S[j]);
    for(i=0;i<6;i++)
        cout<<endl<<"Sticla "<<i<<":"<<endl<<endl<<S[i];
    cout<<"Sticlele al caror dop au diametrul mare decat 5: "<<endl<<endl;
    for(i=0;i<6;i++)
       if(S[i].getDiametru()>5)
           cout<<S[i];
    delete[] S;

    return 0;
}