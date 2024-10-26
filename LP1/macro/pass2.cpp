#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MNTEntry {
public:
    MNTEntry() : name(""), pp(0), kp(0), mdtp(0), kpdtp(0) {}
    MNTEntry(const string& name, int pp, int kp, int mdtp, int kpdtp)
        : name(name), pp(pp), kp(kp), mdtp(mdtp), kpdtp(kpdtp) {}

    int getPp() const { return pp; }
    int getKp() const { return kp; }
    int getMdtp() const { return mdtp; }
    int getKpdtp() const { return kpdtp; }

private:
    string name;
    int pp, kp, mdtp, kpdtp;
};

int main() {
    ifstream irb("intermediate.txt"), mdtb("mdt.txt"), kpdtb("kpdt.txt"), mntb("mnt.txt");
    ofstream fr("pass2.txt");

    if (!irb.is_open() || !mdtb.is_open() || !kpdtb.is_open() || !mntb.is_open() || !fr.is_open()) {
        cerr << "Error opening files!" << endl;
        return 1;
    }

    unordered_map<string, MNTEntry> mnt;
    unordered_map<int, string> aptab;
    unordered_map<string, int> aptabInverse;
    vector<string> mdt, kpdt;
    string line;

    // Load MDT, KPDT, and MNT data
    while (getline(mdtb, line)) mdt.push_back(line);
    while (getline(kpdtb, line)) kpdt.push_back(line);
    while (getline(mntb, line)) {
        istringstream iss(line);
        string name; int pp, kp, mdtp, kpdtp;
        iss >> name >> pp >> kp >> mdtp >> kpdtp;
        mnt[name] = MNTEntry(name, pp, kp, mdtp, kpdtp);
    }

    // Process Intermediate Representation
    while (getline(irb, line)) {
        istringstream iss(line);
        vector<string> parts{istream_iterator<string>{iss}, istream_iterator<string>{}};
        
        // Check if macro call
        if (mnt.count(parts[0])) {
            const MNTEntry& entry = mnt[parts[0]];
            int pp = entry.getPp(), kp = entry.getKp(), mdtp = entry.getMdtp(), kpdtp = entry.getKpdtp();
            int paramNo = 1;

            // Load Positional Parameters
            for (int i = 1; i <= pp && i < parts.size(); ++i) {
                aptab[paramNo] = parts[i];
                aptabInverse[parts[i]] = paramNo++;
            }

            // Load Keyword Parameters with defaults
            for (int i = kpdtp - 1; i < kpdtp - 1 + kp && i < kpdt.size(); ++i) {
                istringstream kpss(kpdt[i]);
                string paramName, defaultValue;
                kpss >> paramName >> defaultValue;
                aptab[paramNo] = defaultValue;
                aptabInverse[paramName] = paramNo++;
            }

            // Override with provided keyword parameters
            for (int i = pp + 1; i < parts.size(); ++i) {
                size_t eqPos = parts[i].find('=');
                if (eqPos != string::npos) {
                    string name = parts[i].substr(0, eqPos);
                    string value = parts[i].substr(eqPos + 1);
                    if (aptabInverse.count(name)) aptab[aptabInverse[name]] = value;
                }
            }

            // Expand Macro in MDT
            for (int i = mdtp - 1; i < mdt.size() && mdt[i] != "MEND"; ++i) {
                istringstream mdiss(mdt[i]);
                string token;
                fr << "+ ";
                while (mdiss >> token) {
                    if (token.find("(P,") != string::npos) {
                        int num = stoi(token.substr(3, token.find(')') - 3));
                        fr << aptab[num] << " ";
                    } else {
                        fr << token << " ";
                    }
                }
                fr << "\n";
            }
            aptab.clear();
            aptabInverse.clear();
        } else {
            fr << line << "\n";  // Non-macro line
        }
    }

    return 0;
}
