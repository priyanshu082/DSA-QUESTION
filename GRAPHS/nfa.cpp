#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

// Structure to represent an NFA
struct NFA {
    set<int> states;                      // Q: set of states
    set<char> alphabet;                   // Σ: input alphabet (excluding ε)
    map<pair<int, char>, set<int>> transitions; // δ: transition function
    int startState;                       // q0: start state
    set<int> acceptStates;                // F: set of accept states
};

// Structure to keep track of a path in the NFA
struct Path {
    vector<int> states;
    vector<char> symbols;
    bool complete;     // Indicates if the path processed the entire input string
    bool accepted;     // Indicates if the path ended in an accept state
};

// Function to compute epsilon closure of a state
set<int> epsilonClosure(const NFA& nfa, int state) {
    set<int> closure = {state};
    queue<int> queue;
    queue.push(state);
    
    while (!queue.empty()) {
        int currentState = queue.front();
        queue.pop();
        
        // Check for epsilon transitions from current state
        auto it = nfa.transitions.find({currentState, 'ε'});
        if (it != nfa.transitions.end()) {
            for (int nextState : it->second) {
                if (closure.find(nextState) == closure.end()) {
                    closure.insert(nextState);
                    queue.push(nextState);
                }
            }
        }
    }
    
    return closure;
}

// Function to compute epsilon closure of a set of states
set<int> epsilonClosure(const NFA& nfa, const set<int>& states) {
    set<int> closure;
    for (int state : states) {
        set<int> stateClosure = epsilonClosure(nfa, state);
        closure.insert(stateClosure.begin(), stateClosure.end());
    }
    return closure;
}

// Function to get next states for a set of states and an input symbol
set<int> move(const NFA& nfa, const set<int>& states, char symbol) {
    set<int> nextStates;
    for (int state : states) {
        auto it = nfa.transitions.find({state, symbol});
        if (it != nfa.transitions.end()) {
            nextStates.insert(it->second.begin(), it->second.end());
        }
    }
    return nextStates;
}

// Function to simulate NFA and find all paths (both accepted and rejected)
bool simulateNFA(const NFA& nfa, const string& input, vector<Path>& allPaths) {
    // Initialize the search with epsilon closure of start state
    set<int> currentStates = epsilonClosure(nfa, nfa.startState);
    
    // Store initial paths
    queue<Path> pathQueue;
    for (int state : currentStates) {
        Path initialPath;
        initialPath.states.push_back(nfa.startState);
        initialPath.complete = false;
        initialPath.accepted = false;
        
        if (state != nfa.startState) {
            initialPath.symbols.push_back('ε');
            initialPath.states.push_back(state);
        }
        pathQueue.push(initialPath);
    }
    
    vector<Path> currentPaths;
    while (!pathQueue.empty()) {
        currentPaths.push_back(pathQueue.front());
        pathQueue.pop();
    }
    
    // Process each input symbol
    for (size_t inputPos = 0; inputPos < input.size(); inputPos++) {
        char symbol = input[inputPos];
        vector<Path> newPaths;
        
        // For each current path, try to extend it
        for (const Path& currentPath : currentPaths) {
            int lastState = currentPath.states.back();
            auto it = nfa.transitions.find({lastState, symbol});
            
            if (it != nfa.transitions.end()) {
                // Path can be extended for this symbol
                for (int nextState : it->second) {
                    Path newPath = currentPath;
                    newPath.symbols.push_back(symbol);
                    newPath.states.push_back(nextState);
                    
                    // Check if we've processed the entire input
                    if (inputPos == input.size() - 1) {
                        newPath.complete = true;
                        newPath.accepted = nfa.acceptStates.find(nextState) != nfa.acceptStates.end();
                    }
                    
                    // Add epsilon transitions
                    set<int> epsilonStates = epsilonClosure(nfa, nextState);
                    for (int epsilonState : epsilonStates) {
                        if (epsilonState != nextState) {
                            Path epsilonPath = newPath;
                            epsilonPath.symbols.push_back('ε');
                            epsilonPath.states.push_back(epsilonState);
                            
                            // Update acceptance if this is the last symbol
                            if (inputPos == input.size() - 1) {
                                epsilonPath.complete = true;
                                epsilonPath.accepted = nfa.acceptStates.find(epsilonState) != nfa.acceptStates.end();
                            }
                            
                            newPaths.push_back(epsilonPath);
                        }
                    }
                    
                    newPaths.push_back(newPath);
                }
            } else {
                // Dead end for this path, keep it for reporting but mark as complete and rejected
                Path deadPath = currentPath;
                deadPath.complete = inputPos > 0; // Only mark as complete if we processed at least one symbol
                deadPath.accepted = false;
                allPaths.push_back(deadPath);
            }
        }
        
        if (newPaths.empty() && inputPos < input.size() - 1) {
            // No transitions possible for this symbol, and we're not at the end
            // Save current paths as dead ends
            for (Path& path : currentPaths) {
                path.complete = false;
                path.accepted = false;
                allPaths.push_back(path);
            }
            return false;
        }
        
        // Update current paths for next iteration
        currentPaths = newPaths;
    }
    
    // Check if any path reached an accept state
    bool accepted = false;
    
    // Add all final paths to allPaths
    for (Path& path : currentPaths) {
        path.complete = true;
        path.accepted = nfa.acceptStates.find(path.states.back()) != nfa.acceptStates.end();
        
        if (path.accepted) {
            accepted = true;
        }
        
        allPaths.push_back(path);
    }
    
    return accepted;
}

// Function to parse the NFA from a file
NFA parseNFAFromFile(const string& filename) {
    NFA nfa;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }
    
    string line;
    
    // Read states (Q)
    getline(file, line);
    istringstream statesStream(line);
    int state;
    while (statesStream >> state) {
        nfa.states.insert(state);
    }
    
    // Read alphabet (Σ)
    getline(file, line);
    for (char symbol : line) {
        if (symbol != ' ') {
            nfa.alphabet.insert(symbol);
        }
    }
    
    // Read transitions (δ)
    int transitionCount;
    file >> transitionCount;
    file.ignore(); // Ignore the newline character
    
    for (int i = 0; i < transitionCount; i++) {
        getline(file, line);
        istringstream transitionStream(line);
        
        int fromState, toState;
        char symbol;
        
        transitionStream >> fromState >> symbol >> toState;
        
        // Handle epsilon as 'e' in input file
        if (symbol == 'e') {
            symbol = 'ε';
        }
        
        nfa.transitions[{fromState, symbol}].insert(toState);
    }
    
    // Read start state (q0)
    file >> nfa.startState;
    
    // Read accept states (F)
    int acceptCount;
    file >> acceptCount;
    
    for (int i = 0; i < acceptCount; i++) {
        int acceptState;
        file >> acceptState;
        nfa.acceptStates.insert(acceptState);
    }
    
    return nfa;
}

// Function to print a path
void printPath(const Path& path, bool showStatus = false) {
    cout << "Path: " << path.states[0];
    
    for (size_t i = 0; i < path.symbols.size(); i++) {
        cout << " -(" << path.symbols[i] << ")-> " << path.states[i + 1];
    }
    
    if (showStatus) {
        if (!path.complete) {
            cout << " (Incomplete - no valid transition)";
        } else if (path.accepted) {
            cout << " (Accepted)";
        } else {
            cout << " (Rejected - not in accept state)";
        }
    }
    
    cout << endl;
}

int main() {
    string filename;
    cout << "Enter the NFA specification file: ";
    cin >> filename;
    
    NFA nfa = parseNFAFromFile(filename);
    
    cout << "\nNFA loaded successfully!" << endl;
    cout << "Start state: " << nfa.startState << endl;
    cout << "Accept states: ";
    for (int state : nfa.acceptStates) {
        cout << state << " ";
    }
    cout << endl;
    
    string testString;
    while (true) {
        cout << "\nEnter a test string (or 'quit' to exit): ";
        cin >> testString;
        
        if (testString == "quit") {
            break;
        }
        
        vector<Path> allPaths;
        bool accepted = simulateNFA(nfa, testString, allPaths);
        
        cout << "String \"" << testString << "\" is ";
        if (accepted) {
            cout << "ACCEPTED" << endl;
            cout << "Paths taken:" << endl;
            
            // Print accepted paths
            for (const Path& path : allPaths) {
                if (path.accepted) {
                    printPath(path);
                }
            }
            
            // Also print rejected paths if any
            bool hasRejectedPaths = false;
            for (const Path& path : allPaths) {
                if (path.complete && !path.accepted) {
                    if (!hasRejectedPaths) {
                        cout << "\nRejected paths:" << endl;
                        hasRejectedPaths = true;
                    }
                    printPath(path, true);
                }
            }
        } else {
            cout << "REJECTED" << endl;
            cout << "Paths taken:" << endl;
            
            // Print all paths with their rejection reason
            for (const Path& path : allPaths) {
                printPath(path, true);
            }
        }
    }
    
    return 0;
}