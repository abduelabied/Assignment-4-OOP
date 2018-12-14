#include "Sequence.h"
/// here is the cpp of the Parent class Sequence that contains constructors and destructors
/// and also all the operator overloading as the child class will inherit from this Parent  class
template<class T>
/// here there the default constructor of the class sequence
Sequence<T>::Sequence()
{
    seq = NULL;
    length = 0;
}
template<class T>
/// here there the paramaterized  constructor of the class sequence
Sequence<T>::Sequence(T* seq, int length)
{
    this->seq = new T[length+1];
    this->length = length;
    for(int i = 0; i < length; ++i)
    {
        ///here there is an exception handle in which if the user enter any different letter from AGCT
        if(seq[i]!='A' && seq[i]!='G' && seq[i]!='C' && seq[i]!='T'){
            throw("The given sequence contains an unallowed character");
        }
        this->seq[i] = seq[i];
    }
    this->seq[length] = '\0';
}
template<class T>
///here another parametrized constructor that have a length only
Sequence<T>::Sequence(int length)
{
    this->length = length;
    seq = new T[length + 1];
}
template<class T>
///here is the copy constructor of the class sequence
Sequence<T>::Sequence(const Sequence& rhs)
{
    seq = new T[rhs.length + 1];
    T* rhsSequence = rhs.seq;
    for(int i = 0; i < rhs.length; ++i)
    {
        this->seq[i] = rhsSequence[i];
    }
}
template<class T>
///here is an getter to get the value of length of sequence
int Sequence<T>::getLength()
{
    return length;

}
template<class T>
///here also another getter to get the sequence it self
T* Sequence<T>::getSequance()
{
    return seq;
}
template<class T>
///here is the operator + that add two sequence with each other
Sequence<T> Sequence<T>::operator+(Sequence& s1)
{
    T* seq2 = new T[this->length + s1.length + 1];
    for(int i = 0; i < this->length; ++i)
    {
        seq2[i] =this->seq[i];
    }
    for(int i = 0; i < s1.getLength(); ++i)
    {
        seq2[i+this->length] = s1.seq[i];
    }
    seq2[this->length+s1.length] = '\0';
    Sequence<T> s(seq2, this->length + s1.length);
    delete[] seq2;
    return s;
}
template<class T>
///here is a boolean function that checks that the two sequences are equal
bool Sequence<T>::operator==(Sequence& s1)
{
    bool found = true;
    if(this->length == s1.getLength())
    {
        for(int i=0; i < this->length; i++ )
        {
            if(this->seq[i] != s1.seq[i]){
                found = false;
                break;
            }
        }
    }
    else if(this->length != s1.getLength())
    {
        found=false;
    }
    return found;
}
template<class T>
///here is a boolean function that checks that the two sequences are not equal
bool Sequence<T>::operator!=(Sequence& s1)
{
    bool found = false;
    if(this->length == s1.getLength())
    {
        for(int i=0; i < this->length; i++ )
        {
            if(this->seq[i] != s1.seq[i]){
                found = true;
                break;
            }
        }
    }
    else if(this->length != s1.getLength())
    {
        found=true;
    }
    return found;
}
template<class TM>
///here we overload the cin operator to insert an object from the classes
istream& operator>> (istream& in, Sequence<TM>& s1)
{
    int len;
    cout << "Enter Length: ";
    cin >> len;

    s1.length = len;
    s1.seq = new TM[len + 1];
    cout<<"Enter The Sequence : ";
    for(int i = 0; i < len; ++i){
        TM c;
        cin >> c;
        s1.seq[i] = c;
    }
    s1.seq[len] = '\0';
    return in;
}
template<class TMP>
///here we overload the cout operator that print an object from the classes
ostream& operator<< (ostream& out, const Sequence<TMP>& s1)
{
    for(int i = 0; i < s1.length; ++i){
        out << (char) s1.seq[i];
    }
    return out;
}
template<class T>
///here there is a destructor that deletes the pointer array
Sequence<T>:: ~Sequence()
{
    delete [] seq;
    seq = 0;
}
template<class T>
///here there is a function Void in order to print the sequence
void Sequence<T>::Print()
{
    cout << seq << endl;
}
template<class T>
/// friend function that will find the LCS (longest common
/// subsequence) between 2 sequences of any type, according to
/// polymorphism
char* Align(Sequence<T>* s1, Sequence<T>* s2){
    int**LCSarray = new int*[strlen(s1->seq)+1];
    for(int i=0; i<strlen(s1->seq)+1; ++i){
        LCSarray[i]=new int[strlen(s2->seq)+1];
        }
            for(int i=0; i<=strlen(s1->seq); ++i){

            for(int j=0; j<= strlen(s2->seq); ++j){
                    LCSarray[i][j]=0;
            }
    }
    for(int i=0; i<=strlen(s1->seq); ++i){
        for(int j=0; j<=strlen(s2->seq); ++j){
            if(i==0 || j==0){
                LCSarray[i][j]=0;
            }
            else if(s1->seq[i-1]==s2->seq[j-1]){
                LCSarray[i][j]= LCSarray[i-1][j-1]+1;
            }
            else{
                LCSarray[i][j]=max(LCSarray[i][j-1],LCSarray[i-1][j]);
            }
        }
    }
    int index=LCSarray[strlen(s1->seq)][strlen(s2->seq)];
    char*ResultString = new char[index +1];
    ResultString[index]='\0';
    int i=strlen(s1->seq),j=strlen(s2->seq);
    while(i>0 && j>0){
            if(s1->seq[i-1]==s2->seq[j-1]){
                ResultString[index-1]=s1->seq[i-1];
                i--;
                j--;
                index--;
            }
            else if(LCSarray[i-1][j]>LCSarray[i][j-1]){
                i--;
            }
            else
                j--;
    }
    delete[] LCSarray;
    return ResultString;
}
template class Sequence<int>;
template class Sequence<char>;
