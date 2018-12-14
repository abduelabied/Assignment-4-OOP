#include "RNA.h"
#include"CodonsTable.h"
#include"Protein.h"
/// here in this child class which is RNA we convert the sequence of RNA back to DNA and also we convert the sequence oF RNA to Protein
/// also this child class inherit from parent class sequence and have constructors and destructors
/// and have its print function to the sequence of RNA
template<class T>
///here a default constructor in class RNA
RNA<T>::RNA()
{
type=mRNA;   //ctor
}
template<class T>
RNA<T>::RNA(T * seq,int length, RNA_Type atype){
    for(int i=0; i<length; ++i){
    if(seq[i]!='A' && seq[i]!='G' && seq[i]!='C' && seq[i]!='U'){
            throw("The given sequence contains an unallowed character");
        }}
    this->seq = new T[length + 1];
    this->length = length;
    for(int i = 0; i<this->length; ++i){
        this->seq[i]=seq[i];
    }
    this->seq[length] = '\0';
    type = atype;
}
template<class T>
/// function to convert the RNA sequence into DNA sequence
///it converts every U to T in the RNA sequence in order to convert to DNA
DNA<T> RNA<T>::ConvertToDNA(){
    T* ss = new T[this->length];
    for(int i = 0; i < this->length; ++i){
        if(this->seq[i] == 'U'){
            ss[i] = 'T';
        }else{
            ss[i] = this->seq[i];
        }
    }
    DNA<T> r(ss, this->length,motif);
    delete[] ss;
    return r;
}
template<class T>
 void RNA <T>::Print(){
 cout<<this->seq;
 }
template<class T>
/// function to convert the RNA sequence into protein sequence
/// using the codonsTable object
Protein<T> RNA<T>:: ConvertToProtein(){
    ///here we make an exception handeling in order to check that the length is modules 3
   if(this->length%3 != 0){
        throw("invalid size");
   }
   T* arrayofamino=new T[this->length/3];
   int counter=0;     /// counter is the index of the amino acid for its iteration.
    CodonsTable codon; /// we make an object from class codons table
    /// in order to have the access on amino acid and the array of value
    codon.LoadCodonsFromFile("RNA_codon_table.txt"); ///we load the file in order to get the amino acid the user want
    for(int i=0 ; i<this->length ; i+=3){
        for(int j=0 ; j<64 ; j++){
            if((codon.codons[j].value[0] == this->seq[i]) && (codon.codons[j].value[1] == this->seq[i+1]) && (codon.codons[j].value[2] == this->seq[i+2]) ){
                arrayofamino[counter]=codon.codons[j].AminoAcid;
                break;
               }
        }
        counter++;
    }
    Protein<T> p1(arrayofamino , this->length/3 , Cellular_Function);
    return p1;
}
template class RNA<int>;
template class RNA<char>;
