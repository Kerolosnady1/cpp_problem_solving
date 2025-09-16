// ================= ProtoType ===================
#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
using namespace std;

// ====================== Response System ======================
class ResponseSystem
{
private:
    vector<string> keywords;
    vector<string> responses;

public:
    ResponseSystem()
    {
        // Initialize with some default responses
        keywords = {"sad", "happy", "angry", "school", "love", "bye"};
        responses = {
            "Tell me more about your feelings...",
            "I'm glad you're happy! :)",
            "Take deep breaths. What's wrong?",
            "Education is important. What's troubling you?",
            "Love is a beautiful thing!",
            "Goodbye! It was nice talking to you."};
    }

    string getResponse(const string &keyword)
    {
        string lowerKeyword = toLower(keyword);
        for (size_t i = 0; i < keywords.size(); i++)
        {
            if (lowerKeyword.find(toLower(keywords[i])) != string::npos)
            {
                return responses[i];
            }
        }
        return "I'm not sure how to respond to that. Can you elaborate?";
    }

    string toLower(const string &input)
    {
        string lower = input;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        return lower;
    }
};

// ====================== ChatBot Class ======================
int manualFind(const string &findOne, const string &findTwo)
{
    if (findTwo.empty())
        return 0;

    for (unsigned int i = 0; i <= findOne.size() - findTwo.size(); ++i)
    {
        bool match = true;
        for (unsigned int j = 0; j < findTwo.size(); ++j)
        {
            if (findOne[i + j] != findTwo[j])
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

    if (start >= str.size())
        return result;

    for (unsigned int i = start; i < start + length && i < str.size(); ++i)
    {
        result += str[i];
    }

    return result;
}
bool isInteger(const string &str)
{
    if (str.empty())
        return false;
    for (char c : str)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
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

// ====================== AngryBot ======================
class AngryBot : public ChatBot
{
public:
    AngryBot(const string &botName) : ChatBot(botName) {}

    string reply(const string &input) override
    {
        string baseResponse = responder.getResponse(input);
        string angryResponse = userName + ": Ugh. " + baseResponse + " Stop complaining!";
        cout << angryResponse << endl;
        chatHistory.push_back("User: " + input);
        chatHistory.push_back(angryResponse);
        return angryResponse;
    }
};

// ====================== Main Program ======================
int main()
{
    string userName;
    cout << "Enter your name: ";
    getline(cin, userName);

    if (isInteger(userName))
    {
        cout << "Numeric input is not allowed. Exiting program." << endl;
        return 0;
    }

    // Create bot (switch between ChatBot and AngryBot)
    ChatBot *bot = new ChatBot("Therapy");
    // ChatBot *bot = new AngryBot("Grumpy");

    bot->greet();

    while (true)
    {
        string input;
        cout << userName << ": ";
        getline(cin, input);

        if (input == "bye")
        {
            bot->reply(input);
            break;
        }

        bot->reply(input);
    }

    // Save to Excel (CSV format)
    bot->saveToExcel("chat_history.csv");

    delete bot;
    return 0;
}