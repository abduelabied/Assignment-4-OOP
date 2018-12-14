#ifndef RNA_H
#define RNA_H
#include"Sequence.h"
#include"DNA.h"
class CodonsTable;
template<class T>
class Protein;
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};
template<class T>
class RNA : public Sequence<T>
{   private:
        RNA_Type type;
  	public:
 	 	/// constructors and destructor
        RNA();
        RNA(T * seq,int length, RNA_Type atype);
        DNA<T> ConvertToDNA();
 	 	/// function to be overridden to print all the RNA information
        void Print();
 	 	/// function to convert the RNA sequence into protein sequence using the codonsTable object
        Protein<T> ConvertToProtein();
 	 	/// function to convert the RNA sequence back to DNA
};
#endif // RNA_H
