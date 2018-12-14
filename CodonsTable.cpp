#include "CodonsTable.h"
#include<fstream>
#include<iostream>
/// this child class which is CodonsTable that we get the amino acid from it generates that protein sequence
///here is the default constructor
CodonsTable::CodonsTable()
{
    for(int i=0; i<64; i++)
    {
        codons[i].value[0]=' ';
        codons[i].value[1]=' ';
        codons[i].value[2]=' ';
    }
//ctor
}
/// here is the destructor tha deletes the pointer array of Codons
CodonsTable::~CodonsTable()
{
    delete []codons; //dtor
}
/// function to load all codons from the given text file
void CodonsTable:: LoadCodonsFromFile(string codonsFileName)
{   ifstream file;
///here we get the file name character by character and we loop at the text file to get the amino acid for the protein
    file.open(codonsFileName.c_str(),ios::in);
    for(int i=0; i<64; i++)
    {
        for(int j=0; j<3; j++)
        {
            file>>codons[i].value[j];
            ///cout<<codons[i].value[j];
        }
        ///cout<<" ";
        file>>codons[i].AminoAcid;
        ///cout<<codons[i].AminoAcid;
        /// cout<<endl;
    }
}
///and the function that et the amino acid is this function
Codon CodonsTable:: getAminoAcid(char * value)
{
    int counter=0;
///here we make a while loop to check whether the right aminoacid for the protein which is put as a parameter for the function
/// a char array
    while(counter<64)
    {
        if(codons[counter].value[0]==value[0] && codons[counter].value[1]==value[1] && codons[counter].value[2]==value[2])
        {
            cout<<codons[counter].AminoAcid;
        }
        counter++;
    }
}
