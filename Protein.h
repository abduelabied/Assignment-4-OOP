#ifndef PROTEIN_H
#define PROTEIN_H
#include"Sequence.h"
enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};
template<class T>
class DNA;
template<class T>
class Protein : public Sequence<T>
{     private:
        Protein_Type type;
      public:
 	 	/// constructors and destructor
 	 	Protein();
 	 	Protein(T* seq, int length,Protein_Type atype);
 	 	/// return an array of DNA sequences that can possibly  generate that protein sequence
        DNA<T>* GetDNAStrandsEncodingMe(const DNA<T>& bigDNA);
};
#endif // PROTEIN_H
