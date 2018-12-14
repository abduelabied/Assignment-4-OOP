#include <iostream>
#include <cstring>
#include "Sequence.cpp"
#include "DNA.h"
#include"RNA.h"
#include<fstream>
using namespace std;
template<class T>
///here there the default constructor of the class DNA
DNA<T>::DNA(){
    type = motif;
    complementary_strand = NULL;
    startIndex = 0;
    endIndex = 0 ;
}
template<class T>
///here there the paramaterized  constructor of the class DNA
DNA<T>::DNA(T* seq, int length, DNA_Type atype){
    for(int i = 0; i < length; ++i)
    {
         ///here there is an exception handle in which if the user enter any different letter from AGCT
        if(seq[i]!='A' && seq[i]!='G' && seq[i]!='C' && seq[i]!='T'){
            throw("The given sequence contains an unallowed character");
        }
    }
    this->seq = new T[length + 1];
    this->length = length;
    for(int i = 0; i<this->length; ++i){
        this->seq[i]=seq[i];
    }
    this->seq[length] = '\0';
    type = atype;
}
template <class T>
///here is the copy constructor of the class sequence
DNA<T>::DNA(DNA<T>& rhs){
    type = rhs.type;
    startIndex = rhs.startIndex;
    endIndex = rhs.endIndex;
    this->length = rhs.length;
    this->seq = new T[rhs.length + 1];
    for(int i = 0; i<this->length; ++i){
        this->seq[i] = rhs.seq[i];
    }
    this->seq[rhs.length] = '\0';
}
 template<class T>
 ///function void that print the sequence of DNA to the user
 void DNA<T>::Print(){
     //TODO Print Type
     cout << this->seq << endl;
 }
template<class T>
	/// function to build the second strand/pair of DNA sequence  To build a complementary_strand (starting from the startIndex to
    /// the endIndex), convert each A to T, each T to A, each C to G, and each G to C. Then reverse the resulting sequence.
void DNA<T>::BuildComplementaryStrand(){
    this->complementary_strand= new DNA;
    this->complementary_strand->type = this->type;
    this->complementary_strand->length = this->length;
    this->complementary_strand->seq = new T[this->length + 1];
    for(int i = 0; i < this->length; ++i){
        if((char) this->seq[i] == 'A'){
            this->complementary_strand->seq[i] = (T) 'T';
        }else if((char) this->seq[i] == 'T'){
            this->complementary_strand->seq[i] = (T) 'A';
        }else if((char) this->seq[i] == 'C'){
            this->complementary_strand->seq[i] = (T) 'G';
        }else if((char) this->seq[i] == 'G'){
            this->complementary_strand->seq[i] = (T) 'C';
        }
    }
    this->complementary_strand->seq[this->length] = '\0';
    for(int i = 0; i < this->length/2; ++i){
        T temp = this->complementary_strand->seq[i];
        this->complementary_strand->seq[i] = this->complementary_strand->seq[this->length - i - 1];
        this->complementary_strand->seq[this->length - i - 1] = temp;
    }

}
template<class T>
///here is a getter function in order to get the complemantry
DNA<T> DNA<T>::getComplementaryStrand(){
    return *(this->complementary_strand);
}
template<class T>
      /// function to convert the DNA sequence to RNA sequence
        /// It starts by building the complementary_strand of the current
        /// DNA sequence (starting from the startIndex to the endIndex), then,
        /// it builds the RNA corresponding to that complementary_strand.
RNA<T> DNA<T>::ConvertToRNA(){
    T* ss = new T[this->length];
    for(int i = 0; i < this->length; ++i){
            ///here it changes every T in the DNA sequence in to U to convert to RNA
        if(this->seq[i] == 'T'){
            ss[i] = 'U';
        }else{
            ss[i] = this->seq[i];
        }
    }
    RNA<T> r(ss, this->length,mRNA);
    delete[] ss;
    return r;
}
template class DNA<int>;
template class DNA<char>;
