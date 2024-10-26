#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<fstream>
#include<cstdlib>
using namespace std;

struct OPTab{
    string opcode;
    string mclass;
    string mnemonic;
};

struct OPTab optab[18] = {
    {"STOP","IS",00},
    {"ADD","IS",00},
    {"SUB","IS",00},
    {"MULT","IS",00},
    {"MOVER","IS",00},
    {"MOVEM","IS",00},
    {"COMP","IS",00},
    {"BC","IS",00},
    {"DIV","IS",00},
    {"READ","IS",00},
    {"PRINT","IS",00},
    {"START","AD",00},
    {"END","AD",00},
    {"ORIGIN","AD",00},
    {"EQU","AD",00},
    {"LTORG","AD",00},
    {"DC","AD",00},
    {"DL","AD",00},
};

int getOP(string s){
    for(int i = 0;i<18;i++){
        if(optab[i].opcode == s){
            return i;
        }
    }
    return -1;
}

int getRegID(string s){
    if (s == "AREG")
        return 1;
    else if (s == "BREG")
        return 2;
    else if (s == "CREG")
        return 3;
    else if (s == "DREG")
        return 4;
    else
        return (-1);
}

int getConditionalCode(string s){
    if (s == "LT")
        return 1;
    else if (s == "LE")
        return 2;
    else if (s == "EQ")
        return 3;
    else if (s == "GT")
        return 4;
    else if (s == "GE")
        return 5;
    else if (s == "ANY")
        return 6;
    else
        return (-1);
}

struct symTable{
    int no;
    string sname;
    string addr;
};

struct symTable ST[10];

bool presentST(string s){
    for(int i = 0;i<10;i++){
        if(ST[i].sname == s){
            return true;
        }
    }
    return false;
}

int getSymID(string s){
    for(int i = 0;i<10;i++){
        if(ST[i].sname == s){
            return i;
        }
    }
    return -1;
}

struct litTable{
    int no;
    string lname;
    string addr;
};

struct litTable LT[10];

bool presentLT(string s){
    for(int i = 0;i<10;i++){
        if(LT[i].lname == s){
            return true;
        }
    }
    return false;
}

int getLitID(string s){
    for(int i = 0;i<10;i++){
        if(LT[i].lname == s){
            return i;
        }
    }
    return -1;
}

struct poolTable{
    int no;
    string pname;
    string addr;
};

struct poolTable PT[10];

int main(){
    ifstream fin;
    fin.open("input.txt");
    ofstream ic,st,lt;
    const char *path1 = "ic.txt";
    const char *path2 = "st.txt";
    const char *path3 = "lt.txt";
    ic.open(path1);
    st.open(path2);
    lt.open(path3);
    int scnt = 0;
    int lcnt = 0;
    int pcnt = 0;
    int LC = 0;
    int nlcnt = 0;
    string label,opcode,op1,op2;

    while(!fin.eof()){
        fin>>label>>opcode>>op1>>op2;
        int id;
        string IC,lc;
        id = getOP(opcode);
        IC = "("+optab[id].mclass+","+optab[id].mnemonic+") ";

        if(opcode == "START"){
            lc = "---";
            if(op1!="NAN"){
                LC = stoi(op1);
                IC+="(C,"+op1+") NAN";
            }
        }
        if(opcode == "EQU"){
            lc = "---";
            IC+="NAN NAN";
            if(presentST(label)){}
        }
    }
    return 0;
}