#ifndef SEQUENCE_H_INCLUDED
#define SEQUENCE_H_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;
template<class T>
class Sequence
{   protected:
        T * seq;
        int length;
    public:
 	 	/// constructors and destructor
        Sequence();
        Sequence(T* seq, int length);
        Sequence(int length);
        Sequence(const Sequence& rhs);
        virtual ~Sequence();//----------
 	 	/// pure virtual function that should be overridden because every
        /// type of sequence has its own details to be printed
        virtual void Print();
        int getLength();
        T* getSequance();
        Sequence operator+( Sequence& s1);
        bool operator ==(Sequence& s1);
        bool operator !=(Sequence& s1);
        template<class TM>
        friend istream& operator>> (istream& in, Sequence<TM>& s1);
        template<class TMP>
        friend ostream& operator<< (ostream& out,const Sequence<TMP>& s1);
 	 	/// friend function that will find the LCS (longest common
        /// subsequence) between 2 sequences of any type, according to polymorphism
        template<class TMPL>
        friend T* Align(Sequence<TMPL>* s1, Sequence<TMPL>* s2);
};
#endif // SEQUENCE_H_INCLUDED
