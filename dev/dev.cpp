#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

vector<string> split(const string &input, char delimiter)
{
    vector<string> tokens;
    stringstream ss(input);
    string token;
    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

string getOptimalCard(const string &input)
{
    map<char, int> cardValues = {{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'1', 10}, {'j', 11}, {'q', 12}, {'k', 13}, {'a', 14}};
    vector<string> components = split(input, ';');
    map<string, string> componentMap;

    for (const string &component : components)
    {
        vector<string> keyValue = split(component, ':');
        if (keyValue.size() == 2)
        {
            componentMap[keyValue[0]] = keyValue[1];
        }
    }
    string trump = componentMap["Trump"];
    string self = componentMap["self"];
    vector<string> cards = split(componentMap["cards"], ',');
    string optimalCard = cards[0];
    return optimalCard;
}

int main()
{
    string inputString;
    cin >> inputString;
    string optimalCard = getOptimalCard(inputString);
    cout << optimalCard << endl;
    return 0;
}
