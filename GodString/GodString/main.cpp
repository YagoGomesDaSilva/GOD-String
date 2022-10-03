#include "GodString.h"


int main() {

    //teste atribuicoes
    GodString str1 = "teste";
    GodString str2 ("teste");

    char teste1[] = "teste";
    GodString str3(teste1);
    GodString str4 = teste1;
    GodString str5 = str4;
    GodString str6(str5);

   //teste print e len
    for (int i = 0; i < str1.godLen(); i++) {

        cout << str1.str[i];
    }
    cout << endl;

    //teste print
    str6.godOut();
    cout << endl;

    /*
    // teste getWord
    GodString str7;
    str7.godGetWord();
    str7.godOut();
    cout << endl;

  
    // teste getLine
    GodString str8;
    str8.godGetLine();
    str8.godOut();
    cout << endl;
    */

    //teste godCompair
    cout << str1.godCompair(str2);
    cout << str1.godCompair(teste1);
    cout << str1.godCompair("teste");
    cout << endl;

    //teste godTrim
    GodString str9;
    str9 = "   Yago Gomes Da Silva   ";
    str9.godTrim();
    str9.godOut();
    cout << endl;

    //teste upper/lower
    str9.godUpper();
    str9.godOut();
    cout << endl;
    str9.godLower();
    str9.godOut();
    cout << endl;

    //teste PreSuf

    GodString str10("Yago Gomes Da Silva");

    GodString str11("Yago Gomes");
    GodString str12("Da Silva");
    GodString str13("yago gomes");
    GodString str14("da silva");

    char testePre1[] = "Yago";
    char testeSuf1[] = "Silva";

    cout << str10.godPreSuf(1, testePre1) << endl;
    cout << str10.godPreSuf(0, testeSuf1) << endl;
    cout << str10.godPreSuf(1, "Yago") << endl;
    cout << str10.godPreSuf(0, "Silva") << endl;
    cout << str10.godPreSuf(1, "Ygs") << endl;
    cout << str10.godPreSuf(0, "Silvis") << endl;

    cout << str10.godPreSuf(1, str11) << endl;
    cout << str10.godPreSuf(0, str12) << endl;
    cout << str10.godPreSuf(1, str13) << endl;
    cout << str10.godPreSuf(0, str14) << endl;
    cout << endl;

    //teste Insertion
    cout << str10.godInsertion('T', 0) << endl;

    //teste Removal
     str10.godRemoval('Y') ;
     str10.godRemoval('G') ;
     str10.godRemoval(11) ;

    //teste Exist
    cout << str10.godExist('D') << endl;

    //teste FindChar
    cout << str10.godFindChar('m') << endl;

    //teste Replace
    str10.godReplace(' ', '-');
    str10.godOut();
    cout << endl;

    //teste Concat
    GodString str15("Yago");
    GodString str16(" e o YAGOD");
    char teste2[] = " Gomes";
    str15.godConcat(teste2);
    str15.godConcat(" da Silva");
    str15.godConcat(str16);
    str15.godOut();
    cout << endl;

    //teste Split

    GodString str17("Yago Gomes Da Silva");

    char teste[] = " ";
    std::vector<std::vector<char> > saida;

    saida = str17.godSplit(teste);
   
    cout << "[";
    for (int i = 0; i < saida.size(); i++) {
        for (int j = 0; j < saida[i].size(); j++) {
            cout << saida[i][j];
        }
        if (i == saida.size() - 1) {
            cout << "]";
        }
        else {
            cout << ",";
        }
    }
    cout << endl;

    
    return 0;
}