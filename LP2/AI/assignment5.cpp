#include <iostream>
#include <string>
using namespace std;

class ChatBot {
public:
    void startChat() {
        cout << "Hello! I am your simple ChatBot.\n";
        cout << "You can ask me about: weather, time, hobby, or type 'exit' to leave.\n";
        string input;
        
        while (true) {
            cout << "\nYou: ";
            getline(cin, input);
            toLowerCase(input);
            
            if (input == "exit") {
                cout << "ChatBot: Goodbye! Have a nice day!\n";
                break;
            } 
            else {
                respond(input);
            }
        }
    }

private:
    void respond(string question) {
        if (question.find("weather") != string::npos) {
            cout << "ChatBot: The weather is sunny and bright!";
        } 
        else if (question.find("time") != string::npos) {
            cout << "ChatBot: It's chatbot time — always ready for you!";
        } 
        else if (question.find("hobby") != string::npos) {
            cout << "ChatBot: I love chatting with smart people like you!";
        } 
        else {
            cout << "ChatBot: Sorry, I don't understand that.";
        }
    }
    
    void toLowerCase(string &str) {
        for (int i = 0; i < str.length(); i++) {
            str[i] = tolower(str[i]);
        }
    }
};

int main() {
    ChatBot bot;
    bot.startChat();
    return 0;
}