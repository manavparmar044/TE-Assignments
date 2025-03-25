#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

struct OPTab{
    string opcode;
    string mclass;
    string mnemonic;
};

struct OPTab optab[18] = {
    {"STOP","IS","00"},
    {"ADD","IS","01"},
    {"SUB","IS","02"},
    {"MULT","IS","03"},
    {"MOVER","IS","04"},
    {"MOVEM","IS","05"},
    {"COMP","IS","06"},
    {"BC","IS","07"},
    {"DIV","IS","08"},
    {"READ","IS","09"},
    {"PRINT","IS","10"},
    {"START","AD","01"},
    {"END","AD","02"},
    {"ORIGIN","AD","03"},
    {"EQU","AD","04"},
    {"LTORG","AD","05"},
    {"DC","DL","01"},
    {"DL","DL","02"},
};

int getOP(string s){
    for(int i = 0; i < 18; i++){
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
        return -1;
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
        return -1;
}

struct symTable{
    int no;
    string sname;
    string addr;
};

struct symTable ST[10];
int symIndex = 0;

bool presentST(string s){
    for(int i = 0; i < 10; i++){
        if(ST[i].sname == s){
            return true;
        }
    }
    return false;
}

int getSymID(string s){
    for(int i = 0; i < 10; i++){
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
int litIndex = 0;

bool presentLT(string s){
    for(int i = 0; i < 10; i++){
        if(LT[i].lname == s){
            return true;
        }
    }
    return false;
}

int getLitID(string s){
    for(int i = 0; i < 10; i++){
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
int poolIndex = 0;

int main(){
    ifstream fin;
    fin.open("input.txt");  // Open your input file
    int LC = 0; // Location Counter
    int nlcnt = 0; // No. of Literals
    string label, opcode, op1, op2;

    cout << "Instruction Code (IC):\n";
    cout << "--------------------------------\n";
    
    while(!fin.eof()){
        fin >> label >> opcode >> op1 >> op2;
        int id;
        string IC, lc;
        id = getOP(opcode);
        IC = "(" + optab[id].mclass + "," + optab[id].mnemonic + ") ";

        if(opcode == "START"){
            lc = "---";
            if(op1 != "NAN"){
                LC = stoi(op1);
                IC += "(C," + op1 + ") NAN";
            }
            cout << IC << endl;
        }
        else if(opcode == "EQU"){
            lc = "---";
            IC += "NAN NAN";
            if(presentST(label)){}
            cout << IC << endl;
        }
        else if(opcode == "LTORG"){ // Literal pool processing
            cout << "Literals in pool:\n";
            for (int i = 0; i < nlcnt; i++) {
                cout << "(" << LT[i].no << ", '" << LT[i].lname << "', " << LT[i].addr << ")\n";
            }
        }
        else{
            // Handle symbol table and literal table population logic
            if(opcode == "MOVER" || opcode == "MOVEM" || opcode == "ADD" || opcode == "SUB" || opcode == "MULT") {
                if (!presentST(label)) {
                    ST[symIndex].no = symIndex + 1;
                    ST[symIndex].sname = label;
                    ST[symIndex].addr = to_string(LC);
                    symIndex++;
                }
            }

            // Print IC for each opcode
            cout << IC << endl;

            // Check and add to the literal table
            if(opcode == "LTORG" || op1 != "") {
                if(!presentLT(op1)) {
                    LT[litIndex].no = litIndex + 1;
                    LT[litIndex].lname = op1;
                    LT[litIndex].addr = to_string(LC);
                    litIndex++;
                    nlcnt++;
                }
            }
            LC++;  // Increment Location Counter
        }
    }

    // Print Symbol Table
    cout << "\nSymbol Table (ST):\n";
    cout << "--------------------------------\n";
    for(int i = 0; i < symIndex; i++){
        cout << "(" << ST[i].no << ", " << ST[i].sname << ", " << ST[i].addr << ")\n";
    }

    // Print Literal Table
    cout << "\nLiteral Table (LT):\n";
    cout << "--------------------------------\n";
    for(int i = 0; i < litIndex; i++){
        cout << "(" << LT[i].no << ", " << LT[i].lname << ", " << LT[i].addr << ")\n";
    }

    fin.close();
    return 0;
}
