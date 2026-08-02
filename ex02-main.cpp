#include <iostream>
#include "ex02-library.h"
using namespace std;

// Using a different main 

int main() {
    TournamentNode t0 = {team, "Energy", 0, 0, nullptr, nullptr};
    TournamentNode t1 = {team, "Aqua", 0, 0, nullptr, nullptr};
    TournamentNode t2 = {team, "Compute", 0, 0, nullptr, nullptr};
    TournamentNode t3 = {team, "Space", 0, 0, nullptr, nullptr};

    // Initial matches
    TournamentNode m0 = {match, "", 1, 5, &t0, &t1};  // The result of the match was a win for the team (Aqua) on the right. 
    TournamentNode m1 = {match, "", 3, 1, &t2, &t3};  // The result of the match was a win for the team on the left. (Compute)

    // Final match
    TournamentNode t = {match, "", 1, 2, &m0, &m1}; 

    cout << "The winner of the tournament is: " << winner(&t) << endl;
    cout << "The maximum points scored during a match were: " << highestScore(&t) << endl;


    cout << "Has DTU Energy lost all matches? ";
    if (lostAllMatches(&t, "Energy")) { cout << "Yes! (true)" << endl; }
    else { cout << "No!(false)" << endl; }

    cout << "Has DTU Space lost all matches? ";
    if (lostAllMatches(&t, "Space")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Has DTU Physics lost all matches? ";
        if (lostAllMatches(&t, "Physics")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }

    cout << "Has DTU Aqua lost all matches? ";
    if (lostAllMatches(&t, "Aqua")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }
    
    cout << "Has DTU Compute lost all matches? ";
    if (lostAllMatches(&t, "Compute")) { cout << "Yes!" << endl; }
    else { cout << "No!" << endl; }
    
    
    return 0;
}