#include "GodString.h"

    //privados
    void GodString::aux(vector<char>& s) {
        vector<char> temp;
        s = temp;
    }

    int  GodString::auxLen(char c[]) {
        int i;
        for (i = 0; c[i] != '\0'; i++) {}
        return i;
    }

    int  GodString::auxLen(const char* c) {
        int i;
        for (i = 0; c[i] != '\0'; i++) {}

        return i;
    }

    void  GodString::clearBuffer() {
        char c;
        while ((c = getchar()) != '\n' && c != EOF );
    }

    //construtor
    GodString::GodString() {}

    GodString::GodString( char c[]) {
        this->aux(this->str);
        for (int i = 0; i < auxLen(c); i++) {
            this->str.push_back(c[i]);
        }
    }

    GodString::GodString(const char* c){
        this->aux(this->str);
        for (int i = 0; i < auxLen(c); i++) {
            this->str.push_back(c[i]);
        }
    }

    GodString::GodString(const GodString& s) {
        this->str = s.str;
    }

    GodString::~GodString() {
        this->aux(this->str);
    }


    //metodos
    int GodString::godLen() {
        return this->str.size();
    }
    
    void GodString::godGetWord() {
        this->aux(this->str);

        char c ='\0';
       
        while (c != '\n') {
            c = cin.get();
            if (c == ' ') {
                clearBuffer();
                break;
            }
            else { 
                this->str.push_back(c);
            }
        }
    }
   
    void GodString::godOut() {
        for (int i = 0; i < this->str.size(); i++) {
            std::cout << this->str[i];
        }
    }

    void GodString::godGetLine() {
        this->aux(this->str);

        char c = '\0';
        while (c != '\n') {
            c = cin.get();
            this->str.push_back(c);
        }
    }

    bool GodString::godCompair(GodString comp){

        if (comp.str.size() > this->str.size() || comp.str.size() < this->str.size()) {
            return false;
        }

        bool out = true;
        for (int i = 0; i < this->godLen(); i++) {
            if (comp.str[i] != this->str[i]) {
                out = false;
                break;
            }
        }

        return out;
    }

    bool GodString::godCompair(const char* comp) {


        if (auxLen(comp) > this->str.size() || auxLen(comp) < this->str.size()) {
            return false;
        }

        bool out = true;
        for (int i = 0; i < this->godLen(); i++) {
            if (comp[i] != this->str[i]) {
                out = false;
                break;
            }
        }

        return out;
    }

    bool GodString::godCompair(char comp[]) {


        if (auxLen(comp)> this->str.size() || auxLen(comp) < this->str.size()) {
            return false;
        }

        bool out = true;
        for (int i = 0; i < this->godLen(); i++) {
            if (comp[i] != this->str[i]) {
                out = false;
                break;
            }
        }

        return out;
    }
    
    void GodString::godTrim() {

        int in = 0;
        int f = this->godLen()-1;

        std::vector<char> temp;

        for (int i = 0; i < this->godLen() - 1; i++) {
            if (this->str[i] != ' ') {
                in = i;
                break;
            }
        }

        for (int i = this->godLen() - 1; i > in - 1; i--) {
            if (this->str[i] != ' ') {
                f = i;
                break;
            }
        }
        
        for (int i = in; i < f+1; i++) {
            temp.push_back(this->str[i]);
        }
        this->str = temp;
    }

    void GodString::godUpper(){
        for (int i = 0; i < this->godLen(); i++) {
            if (this->str[i] >= 'a' && this->str[i] <= 'z') {
                this->str[i] = this->str[i] - 32;
            }
        }
    }

    void GodString::godLower() {
        for (int i = 0; i < this->godLen(); i++) {
            if (this->str[i] >= 'A' && this->str[i] <= 'Z') {
                this->str[i] = this->str[i] + 32;
            }
        }
    }

    bool GodString::godPreSuf(bool opc, GodString str) {

        if(opc){

            bool pre = true;
            if (str.godLen() > this->godLen()) {
                return pre = false;
            }

            for (int i = 0; i < str.godLen(); i++) {
                if (this->str[i] != str.str[i]) {
                    return pre = false;
                }
            }

            return pre;
        }

        else if(!opc){

            int tStr = this->godLen(), tSuf = str.godLen();
            bool suf = true;

            if (str.godLen() > this->godLen()) {
                return suf = false;
            }

            for (int i = tStr - tSuf, j = 0; i < tStr; i++, j++) {
                if (this->str[i] != str.str[j]) {
                    return  suf = false;
                }
            }

            return suf;
        }
    }

    bool GodString::godPreSuf(bool opc, const char* str) {

        if (opc) {

            bool pre = true;
            if (auxLen(str) > this->godLen()) {
                return pre = false;
            }

            for (int i = 0; i < auxLen(str); i++) {
                if (this->str[i] != str[i]) {
                    return pre = false;
                }
            }

            return pre;
        }

        else if (!opc) {

            int tStr = this->godLen(), tSuf = auxLen(str);
            bool suf = true;

            if (auxLen(str) > this->godLen()) {
                return suf = false;
            }

            for (int i = tStr - tSuf, j = 0; i < tStr; i++, j++) {
                if (this->str[i] != str[j]) {
                    return  suf = false;
                }
            }

            return suf;
        }

    }

    bool GodString::godPreSuf(bool opc, char str[]) {

        if (opc) {

            bool pre = true;
            if (auxLen(str) > this->godLen()) {
                return pre = false;
            }

            for (int i = 0; i < auxLen(str); i++) {
                if (this->str[i] != str[i]) {
                    return pre = false;
                }
            }

            return pre;
        }

        else if (!opc) {

            int tStr = this->godLen(), tSuf = auxLen(str);
            bool suf = true;

            if (auxLen(str) > this->godLen()) {
                return suf = false;
            }

            for (int i = tStr - tSuf, j = 0; i < tStr; i++, j++) {
                if (this->str[i] != str[j]) {
                    return  suf = false;
                }
            }

            return suf;
        }

    }

    bool GodString::godInsertion(char c, int p) {
        int tStr = this->godLen();

        if (p > tStr) {
            return false;
        }

        this->str.insert(this->str.begin() + p, c);

        if (this->str[p] == c && this->godLen() > tStr) {
            return true;
        }

        return false;
    }

    bool GodString::godRemoval(int p) {
        int tStr = this->godLen();

        if (p > tStr) {
            return false;
        }

        this->str.erase(this->str.begin() + p);

        return true;
    }

    bool GodString::godRemoval(char c) {
        int tStr = this->godLen();
        int p = -1;

        for (int i = 0; i < this->godLen(); i++) {
            if (this->str[i] == c) {
                p = i;
                break;
            }
        }

        if (p == -1) {
            return false;
        }

        this->godRemoval(p);

        if (this->godLen() < tStr) {
            return true;
        }

        return false;
    }

    bool GodString::godExist(char c) {
        for (int i = 0; i < this->godLen(); i++) {
            if (this->str[i] == c) {
                return true;
            }
        }
        return false;
    }

    int GodString::godFindChar(char c) {
        for (int i = 0; i < this->godLen(); i++) {
            if (this->str[i] == c) {
                return i;
            }
        }
        return -1;
    }

    void GodString::godReplace(char a, char b) {
        for (int i = 0; i < this->godLen(); i++) {
            if (this->str[i] == a) {
                this->str[i] = b;
            }
        }
    }

    void GodString::godConcat(char c[]) {
        for (int i = 0; i < auxLen(c); i++) {
            this->str.push_back(c[i]);
        }
    }

    void GodString::godConcat(const char* c) {
        for (int i = 0; i < auxLen(c); i++) {
            this->str.push_back(c[i]);
        }
    }

    void GodString::godConcat(GodString c) {
        for (int i = 0; i < c.godLen(); i++) {
            this->str.push_back(c.str[i]);
        }

    }
    
    vector<vector<char>> GodString::godSplit(char c[]) {
        vector<vector<char> > saida;
        vector<char> temp;

        for (int i = 0; i < this->str.size(); ++i) {

            if (this->str[i] == c[0]) {
                saida.push_back(temp);
                aux(temp);
            }
            else {
                temp.push_back(this->str[i]);
            }

        }
        saida.push_back(temp);

        return saida;
    }

    
    
    vector<vector<char>> GodString::godSplit(const char* c){
        vector<vector<char> > saida;
        vector<char> temp;

        for (int i = 0; i < this->str.size(); ++i) {

            if (this->str[i] == c[0]) {
                saida.push_back(temp);
                aux(temp);
            }
            else {
                temp.push_back(this->str[i]);
            }

        }
        saida.push_back(temp);

        return saida;
    
    }
    
    
    vector<vector<char>> GodString::godSplit(GodString c) {
        vector<vector<char> > saida;
        vector<char> temp;

        for (int i = 0; i < this->str.size(); ++i) {

            if (this->str[i] == c.str[0]) {
                saida.push_back(temp);
                aux(temp);
            }
            else {
                temp.push_back(this->str[i]);
            }

        }
        saida.push_back(temp);

        return saida;
    }
    