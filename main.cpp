// Course:  CS213 - Programming II  - 2018
// Title:   Assignment 4
// Version: 2.0
// Date:    14 D 2018
// Program: Biology FCI program
// Purpose: .....
/// Welcome to Our Biology FCI program
/// our program have been built in order to help the biologist to convert all the sequences they want
/// and this program help to get the alignment of two sequences of any type
/// also we use in our code templates and exception handling and all the concepts of oop
/// also they can save any type of sequence in our program in order to use it in the future and make on
/// the saving sequence any modulation or function on the sequence
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Author 1 :  Salah Mostafa Abbas                 ID:20170131 , G5
/// Author 2 :  Abdelrahman Hussein Ali             ID:20170163 , G6
/// Author 3 :  Abdelrahman Mohamed Ahmed Mahmoud   ID:20170148 , G6
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "DNA.cpp"
#include "RNA.cpp"
#include"CodonsTable.h"
#include"Protein.h"
#include<vector>
using namespace std;
/// here there is a simple menu to show it to the user in order to choose which function he would choose
void DisplyMenu(){
    cout<<endl;
    cout<<"--------- Welcome To Our Biology Program --------------"<<endl;
    cout<<endl;
    cout<<"**************************************************** "<<endl;
    cout<<" Here Our Menu Choose what you Need "<<endl;
    cout<<endl;
    cout<<"**************************************************** "<<endl;
    cout<<" 1- Build A Comlemantry Strand Of DNA "<<endl;
    cout<<" 2- Convert DNA sequence to RNA sequence"<<endl;
    cout<<" 3- Convert RNA sequence to Protein sequence"<<endl;
    cout<<" 4- Convert RNA sequence to DNA sequence"<<endl;
    cout<<" 5- Get The Alignment Sequence"<<endl;
    cout<<" 6- Get DNA strand sequence that can generate protein"<<endl;
    cout<<" 7- Save the sequence in an external file "<<endl;
    cout<<" 8- Add two DNA sequence "<<endl;
    cout<<" 9- Add two RNA sequence "<<endl;
    cout<<"10- Check that the two DNA sequence are equal "<<endl;
    cout<<"11- Check that the  two RNA sequence are equal "<<endl;
}
template<class T>
///here is a function that save the sequence in an external ile in order to use it in the future
void SaveSequenceToFile(T * data,string filename)
{
    filename += ".txt";
    ofstream outfile;
    outfile.open(filename.c_str());
    outfile << data;
    outfile.close();
}
int main()
{   DisplyMenu();
    int choose;
    cin>>choose;
    try{
        switch(choose){
            case 1:{
    DNA<char> d3;
    cin>>d3;
    d3.BuildComplementaryStrand();
    cout<<"The Complemantry Strand of DNA Sequence is : "<<d3.getComplementaryStrand()<<endl;
            break;
                }
        case 2:{
            DNA<char>d1;
            cin>>d1;
            cout<<d1.ConvertToRNA()<<endl;
            break;
            }
        case 3:{
            RNA<char>R1;
            cin>>R1;
            cout<<R1.ConvertToProtein()<<endl;
            break;
        }
        case 4:{
            RNA<char>R2;
            cin>>R2;
            cout<<R2.ConvertToDNA();
            break;
        }
        case 5:{
            int len1=0,len2;
            char* arr=new char[20],*arr2=new char[20];
            cout<<"Enter The length of first Sequence : ";
            cin>>len1;
            cout<<"Enter The First Sequence : ";
            cin>>arr;
            cout<<"Enter The length of Second Sequence : ";
            cin>>len2;
            cout<<"Enter The Second Sequence : ";
            cin>>arr2;
            Sequence<char>* d = new Sequence<char>(arr, len1);
            Sequence<char>* d2 = new Sequence<char>(arr2, len2);
            cout << Align(d, d2) << endl;
            break;
        }
        case 6:{
            Protein<char>P1;
            cin>>P1;
//            cout<<P1.GetDNAStrandsEncodingMe();
            break;
        }
        case 7:{
            string f;
            cout<<"Enter The File Name Do You Want To Save in : ";
            cin>>f;
            char * seq;
            cout<<"Enter the sequence that you want to Save : ";
            cin>>seq;
           SaveSequenceToFile(seq,f);
           cout<<endl;
           cout<<"The Sequence  is Saved Successfuly in the file " ;
           cout <<endl;
           break;
        }
        case 8:{

            DNA<char> d3;
            DNA<char> d4;
            cin>>d3>>d4;
            cout<<(d3+d4)<<endl;
            break;
        }
          case 9:{
            RNA<char> d3;
            RNA<char> d4;
            cin>>d3>>d4;
            cout<<(d3+d4)<<endl;
            break;
        }
           case 10:{
            DNA<char> d3;
            DNA<char> d4;
            cin>>d3,d4;
            if(d3==d4){
                cout<<"The Twa DNA Sequences Are Equal " <<endl;;
            }
            else{
            cout<<"They are not Equal"<<endl;
            }
            break;
        }
           case 11:{

            RNA<char> d3;
            RNA<char> d4;
            cin>>d3>>d4;
            if(d3==d4){
                cout<<"The Two RNA Sequences Are Equal " <<endl;;
            }
            else{

            cout<<"They are not Equal"<<endl;
            }
            break;
        }
        }
    }
    catch(const char* errormsg)
    {
        cout << errormsg;
    }
    return 0;
}
