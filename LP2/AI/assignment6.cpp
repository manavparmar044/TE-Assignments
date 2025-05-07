#include <iostream>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

class AdvancedMedicalExpertSystem {
private:
    // disease_name -> (symptom map, description, treatment)
    map<string, tuple<map<string, int>, string, string>> knowledgeBase;

public:
    AdvancedMedicalExpertSystem() {
        knowledgeBase.insert({
            {"Flu", {
                {
                    {"fever", 2}, 
                    {"cough", 2}, 
                    {"sore throat", 1}
                }, 
                "A common viral infection causing fever, cough, and sore throat.",
                "Rest, fluids, antiviral medications"
            }},
            {"Diabetes", {
                {
                    {"fatigue", 2}, 
                    {"frequent urination", 3},
                    {"blurred vision", 1}
                },
                "A chronic condition that affects how the body processes blood sugar.",
                "Insulin therapy, dietary changes, exercise"
            }},
            {"Hypertension", {
                {
                    {"headache", 1}, 
                    {"dizziness", 2}, 
                    {"chest pain", 3}
                },
                "High blood pressure often with no symptoms.",
                "Lifestyle changes, antihypertensive medication"
            }}
        });
    }

    void diagnose(const set<string>& userSymptoms) {
        string likelyDisease;
        int highestScore = 0;
        string description, treatment;

        for (const auto& diseaseEntry : knowledgeBase) {
            const string& diseaseName = diseaseEntry.first;
            const auto& diseaseData = diseaseEntry.second;
            const auto& symptomsMap = get<0>(diseaseData);
            int score = 0;

            for (const auto& symptom : userSymptoms) {
                auto it = symptomsMap.find(symptom);
                if (it != symptomsMap.end()) {
                    score += it->second;
                }
            }

            if (score > highestScore) {
                highestScore = score;
                likelyDisease = diseaseName;
                description = get<1>(diseaseData);
                treatment = get<2>(diseaseData);
            }
        }

        if (!likelyDisease.empty()) {
            cout << "Likely Disease: " << likelyDisease << "\n";
            cout << "Description: " << description << "\n";
            cout << "Recommended Treatment: " << treatment << "\n";
        } else {
            cout << "No matching disease found.\n";
        }
    }
};

int main() {
    AdvancedMedicalExpertSystem system;

    set<string> userSymptoms;
    string symptom;

    cout << "Enter symptoms one by one (type 'done' to finish):\n";
    while (true) {
        cout << "Symptom: ";
        getline(cin, symptom);
        if (symptom == "done") break;
        userSymptoms.insert(symptom);
    }

    system.diagnose(userSymptoms);

    return 0;
}