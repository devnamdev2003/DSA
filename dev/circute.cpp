#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<char, unordered_map<char, pair<char, char>>> transitions;
    char present_state, next_state, input, output;
    
    // Read input until EOF
    while (cin >> present_state >> next_state >> input >> output) {
        transitions[present_state][next_state] = make_pair(input, output);
    }

    // Find the initial state
    char initial_state;
    for (const auto& entry : transitions) {
        if (entry.first != 'F' && entry.second.find(entry.first) == entry.second.end()) {
            initial_state = entry.first;
            break;
        }
    }

    // Traverse the state transition diagram to find the sequence
    char current_state = initial_state;
    string sequence;
    while (true) {
        char next_input = transitions[current_state][current_state].first;
        sequence += next_input;
        current_state = transitions[current_state][current_state].second;

        if (current_state == initial_state) {
            break;
        }
    }

    // Print the detected sequence
    cout << sequence << endl;

    // Determine the type of sequence detector
    if (transitions[current_state][current_state].second == 'F') {
        cout << "Non Overlapping Sequence Detector" << endl;
    } else {
        cout << "Overlapping Sequence Detector" << endl;
    }

    return 0;
}
