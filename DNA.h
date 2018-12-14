#ifndef DNA_H_INCLUDED
#define DNA_H_INCLUDED
#include"Sequence.h"
using namespace std;
enum DNA_Type{promoter, motif, tail, noncoding};
template<class T>
class RNA;
template<class T>
class DNA : public Sequence<T>{
  	private:
        DNA_Type type;
        DNA* complementary_strand;
        int startIndex;
        int endIndex;
    public:
 	 	// constructors and destructor
        DNA();
        DNA(T* seq, int length, DNA_Type atype);
        DNA(DNA& rhs);
 	 	/// function printing DNA sequence information to user
        void Print();
        /// function to convert the DNA sequence to RNA sequence
        /// It starts by building the complementary_strand of the current
        /// DNA sequence (starting from the startIndex to the endIndex), then,
        /// it builds the RNA corresponding to that complementary_strand.
        RNA<T> ConvertToRNA();
 	 	/// function to build the second strand/pair of DNA sequence
	    /// To build a complementary_strand (starting from the startIndex to
        /// the endIndex), convert each A to T, each T to A, each C to G, and
        /// each G to C. Then reverse the resulting sequence.
        void BuildComplementaryStrand();
        void SaveSequenceToFile(T* data,string filename);
        DNA getComplementaryStrand();
};
#endif // DNA_H_INCLUDED
