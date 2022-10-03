#ifndef GODSTRING
#define GODSTRING

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<vector>
using std::vector;

class GodString {
private:

    void aux(vector<char>& s);

    int  auxLen(char c[]);

    int  auxLen(const char* c);

    void clearBuffer();

public:

    vector<char> str;

    GodString();

    GodString(char c[]);

    GodString(const char *c);

    GodString(const GodString & s);

    ~GodString();

    //metodos
    int godLen();

    void godGetWord();

    void godOut();

    void godGetLine();

    bool godCompair(GodString comp);
    bool godCompair(const char* comp);
    bool godCompair(char comp[]);
   
    void godTrim();

    void godUpper();
    void godLower();
    
    bool godPreSuf(bool opc, GodString str);
    bool godPreSuf(bool opc, const char* str);
    bool godPreSuf(bool opc, char str[]);

    bool godInsertion(char c, int p);

    bool godRemoval(int p);
    bool godRemoval(char c);

    bool godExist(char c);

    int godFindChar(char c);

    void godReplace(char a, char b);

    void godConcat(char c[]);
    void godConcat(const char* c);
    void godConcat(GodString c);

    vector<vector<char>> godSplit(char c[]);
    vector<vector<char>> godSplit(const char* c);
    vector<vector<char>> godSplit(GodString c);
};

#endif