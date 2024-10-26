#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    ifstream br("input.txt");
    ofstream mnt("mnt.txt"), mdt("mdt.txt"), kpdt("kpdt.txt"), pnt("pntab.txt"), ir("intermediate.txt");

    if (!br.is_open() || !mnt.is_open() || !mdt.is_open() || !kpdt.is_open() || !pnt.is_open() || !ir.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    map<string, int> pntab;
    string line, Macroname;
    int mdtp = 1, kpdtp = 0, paramNo = 1, pp = 0, kp = 0;
    bool isMacroDef = false;

    while (getline(br, line)) {
        istringstream iss(line);
        vector<string> parts((istream_iterator<string>(iss)), istream_iterator<string>());

        if (parts.empty()) continue;  // skip empty lines

        if (parts[0] == "MACRO" || parts[0] == "macro") {
            isMacroDef = true;
            if (!getline(br, line)) break;

            istringstream iss2(line);
            vector<string> defParts((istream_iterator<string>(iss2)), istream_iterator<string>());
            Macroname = defParts[0];

            // Process parameters
            for (size_t i = 1; i < defParts.size(); ++i) {
                string param = defParts[i];
                param.erase(remove_if(param.begin(), param.end(), [](char c) { return c == '&' || c == ','; }), param.end());

                size_t pos = param.find('=');
                if (pos != string::npos) {
                    ++kp;
                    string keyParam = param.substr(0, pos);
                    string value = param.substr(pos + 1);
                    pntab[keyParam] = paramNo++;
                    kpdt << keyParam << "\t" << value << "\n";
                } else {
                    pntab[param] = paramNo++;
                    ++pp;
                }
            }

            mnt << Macroname << "\t" << pp << "\t" << kp << "\t" << mdtp << "\t" << (kp ? kpdtp + 1 : kpdtp) << "\n";
            kpdtp += kp;
            pp = kp = 0;  // Reset for next macro

        } else if (parts[0] == "MEND" || parts[0] == "mend") {
            mdt << "MEND\n";
            isMacroDef = false;
            mdtp++;
            paramNo = 1;

            // Write PNTAB entry
            pnt << Macroname << ":\t";
            for (const auto& [param, index] : pntab) pnt << param << "\t";
            pnt << "\n";
            pntab.clear();

        } else if (isMacroDef) {
            for (const auto& part : parts) {
                if (part.find('&') != string::npos) {
                    string param = part;
                    param.erase(remove_if(param.begin(), param.end(), [](char c) { return c == '&' || c == ','; }), param.end());
                    mdt << "(P," << pntab[param] << ")\t";
                } else {
                    mdt << part << "\t";
                }
            }
            mdt << "\n";
            mdtp++;
        } else {
            ir << line << "\n";  // Non-macro line to intermediate file
        }
    }

    cout << "Macro Pass1 Processing done. :)" << endl;
    return 0;
}
