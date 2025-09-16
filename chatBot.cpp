#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
using namespace std;

int manualFind(const string &haystack, const string &needle)
{
    if (needle.empty())
        return 0;

    for (unsigned int i = 0; i <= haystack.length() - needle.length(); ++i)
    {
        bool match = true;
        for (unsigned int j = 0; j < needle.length(); ++j)
        {
            if (haystack[i + j] != needle[j])
            {
                match = false;
                break;
            }
        }
        if (match)
            return i;
    }

    return -1; // Not found
}

string manualSubstr(const string &str, unsigned int start, unsigned int length)
{
    string result = "";

    if (start >= str.length())
        return result;

    for (unsigned int i = start; i < start + length && i < str.length(); ++i)
    {
        result += str[i];
    }

    return result;
}

class ChatBot
{
protected:
    string userName;
    ResponseSystem responder;
    vector<string> chatHistory;

public:
    ChatBot(const string &botName) : userName(botName) {}

    void greet()
    {
        string greeting = userName + ": Hello! I'm " + userName + ". How are you feeling today?";
        cout << greeting << endl;
        chatHistory.push_back(greeting);
    }

    virtual string reply(const string &input)
    {
        string response = responder.getResponse(input);
        string fullResponse = userName + ": " + response;
        cout << fullResponse << endl;
        chatHistory.push_back("User: " + input);
        chatHistory.push_back(fullResponse);
        return response;
    }

    void saveToExcel(const string &filename)
    {
        ofstream excelFile(filename);
        if (!excelFile)
        {
            cout << "Error creating file!" << endl;
            return;
        }

        time_t now = time(0);
        excelFile << "Chat Session," << ctime(&now) << endl;

        excelFile << "Speaker,Message" << endl;

        for (int i = 0; i < chatHistory.size(); ++i)
        {
            string message = chatHistory[i];
            unsigned int colonPos = manualFind(message, ":");
            string speaker = manualSubstr(message, 0, colonPos);
            string msg = message.substr(colonPos + 2);
            excelFile << speaker << "," << msg << endl;
        }

        excelFile.close();
        cout << "Chat saved to " << filename << endl;
    }
};