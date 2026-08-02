#include <iostream>
#include <cmath>

#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
string winner(TournamentNode *t) {
    // Base case: if t is a null pointer, return empty string
    if (t == nullptr) {
        return "";
    }
    
    // Base case: if t is a team node, return the team name
    if (t->nodeType == team) {
        return t->name;
        //*** It doesn't make sense to return an empty string here*
    }
    
    // t is a match node
    // Determine which side won and use recursion on that side
    if (t->leftPoints > t->rightPoints) {
        return winner(t->left);    // Left team won
    } else {
        return winner(t->right);   // Right team won
    }
}
// Task 2(b).  Implement this function 
// *** ---- the function is called highestScore - not maxPoints ----***
unsigned int highestScore(TournamentNode *t) {
    // Base case: if t is a null pointer, return 0
    if (t == nullptr) {
        return 0;
    }
    
    // Base case: if t is a team node, return 0 (teams don't have scores)
    if (t->nodeType == team) {
        return 0;
    }
    
    // Recursive case: t is a match node
    // Find the max score in this match
    unsigned int maxPoints = max(t->leftPoints, t->rightPoints);
    
    // Recursively find max scores in left and right subtrees
    unsigned int leftMax = highestScore(t->left); 
    unsigned int rightMax = highestScore(t->right);
    
    
    // Return the overall maximum
    return max(maxPoints, max(leftMax, rightMax));
}



// Task 2(c).  Implement this function

bool lostAllMatches(TournamentNode *t, string teamName) {
    // Base case: if t is a nullptr, return false
    if (t == nullptr) {
        return false;
    }
    
    /* ***-- This doesn't work-- ***
    if (t->nodeType == team){
        return false;              
    }
    */
    
    // Base case: if t is a team node
    if (t->nodeType == team) {
        // If this is the team, they exist
        return (t->name == teamName);   //
    }
    
    
    // Recursive case: t is a match node
    // Check if the team won this subtree
    if (winner(t) == teamName) {
        // Team won this match, so they didn't lose all
        return false;
    }
    
    // Team didn't win this match, check if they participated in either subtree
    bool inLeft = lostAllMatches(t->left, teamName);
    bool inRight = lostAllMatches(t->right, teamName);
    
    // Return true if team is in either subtree (meaning they lost this match)
    return (inLeft || inRight);
}
