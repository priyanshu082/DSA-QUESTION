#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

class VotingSystem {
private:
    int NumCan;
    int NumStu;
    int VoteFor[10];
    string CanName[10];
    string id[100];
    string pass;

public:
    VotingSystem() {
        NumCan = 0;
        NumStu = 0;
        pass = "ajay";
    }

    void adminPanel() {
        cout << "Enter the number of candidates: ";
        cin >> NumCan;

        if (NumCan > 1) {
            for (int i = 1; i <= NumCan; i++) {
                cout << "Enter the name of Candidate-" << i << ": ";
                cin >> CanName[i];
                VoteFor[i] = 0;
            }

            cout << "Enter the number of students: ";
            cin >> NumStu;

            cout << "Thank you, Admin! We are going to start our election with " << NumStu
                 << " students and " << NumCan << " candidates." << endl;
        } else {
            cout << "Sorry! Number of candidates must be more than one person." << endl;
        }
    }

    void studentVoting() {
        cout << "Enter the password: ";
        string inputPass;
        cin >> inputPass;

        if (inputPass != pass) {
            cout << "Wrong password! Exiting the voting process." << endl;
            return;
        }

        for (int i = 1; i <= NumStu; i++) {
            cout << "Student - " << i << endl;
            cout << "Enter your ID: ";
            string inputId;
            cin >> inputId;

            if (!isValidId(inputId)) {
                cout << "Sorry, ID not found or invalid. Try again." << endl;
                i--;  // Retry for the same student
                continue;
            }

            cout << "Name: " << id[i] << endl;
            cout << "ID: " << inputId << endl;

            cout << "Candidates: ";
            for (int j = 1; j <= NumCan; j++) {
                cout << j << ". " << CanName[j] << " ";
            }
            cout << endl;

            cout << "Put your vote: ";
            int vote;
            cin >> vote;

            if (vote >= 1 && vote <= NumCan) {
                VoteFor[vote]++;
                cout << "Thanks for your vote." << endl;
            } else {
                cout << "Invalid vote! Please choose a valid candidate." << endl;
                i--;  // Retry for the same student
            }

            cout << "Press Enter for the next student..." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("clear");
        }
    }

    void displayResults() {
        cout << "==============================================" << endl;
        cout << "Results" << endl;
        cout << "==============================================" << endl;

        for (int j = 1; j <= NumCan; j++) {
            cout << CanName[j] << " received " << VoteFor[j] << " votes." << endl;
        }

        int maxVotes = 0;
        int winningCandidate = 0;

        for (int j = 1; j <= NumCan; j++) {
            if (VoteFor[j] > maxVotes) {
                maxVotes = VoteFor[j];
                winningCandidate = j;
            }
        }

        cout << "==============================================" << endl;
        cout << "Congratulations " << CanName[winningCandidate] << "! You are elected as the winner." << endl;
        cout << "==============================================" << endl;
    }

    bool isValidId(const string& inputId) {
        for (int i = 1; i <= NumStu; i++) {
            if (id[i] == inputId) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    VotingSystem votingSystem;
    votingSystem.adminPanel();
    votingSystem.studentVoting();
    votingSystem.displayResults();

    return 0;
}
