#include "Protein.h"
#include"DNA.h"
#include<vector>
#include"CodonsTable.h"
#include"RNA.h"
///also this child class inherit from parent class sequence and have constructors and destructors
/// and have its print function
/// here in this child class we return an array of DNA sequences that can possibly
/// generate that protein sequence
template<class T>
///here is a default constructor
Protein<T>::Protein()
{
    //seq=0;
    type=Cellular_Function;
    //ctor
}
///here is a parameterized constructor
template<class T>
Protein<T>::Protein(T * seq,int length,Protein_Type atype)
{
    this->length=length;
    this->seq=new T[length+1];
    for(int i=0; i<length; i++)
    {
        this->seq[i]=seq[i];
    }
    this->seq[length]='\0';
    type=atype;
}
template<class T>
/// here in this child class we return an array of DNA sequences that can possibly
/// generate that protein sequence
DNA<T>* GetDNAStrandsEncodingMe(const DNA<T> & bigDNA)
{}
template class Protein<int>;
template class Protein<char>;
