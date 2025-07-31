#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// --- Task 3: Player Class ---
class Player {
private:
    string name;
    char avatar;
    int score;

public:
    Player() : score(0) {}  // default constructor initializes score to 0

    void createProfile() {
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Choose an avatar (single character): ";
        cin >> avatar;
        cin.ignore(); // Clear newline after avatar input
    }

    void showProfile() const {
        cout << "\nPlayer Profile:\n";
        cout << "Name: " << name << "\n";
        cout << "Avatar: " << avatar << "\n";
        cout << "Score: " << score << "\n";
    }

    void addScore(int points) {
        score += points;
    }

    int getScore() const {
        return score;
    }

    string getName() const {
        return name;
    }
};
 class Game {
private:
    int level;
    int maxRange;
    int maxAttempts;
    int number;    // secret number to guess
    bool hintUsed;

public:
    Game() : level(1), hintUsed(false) {}

    void showRules() {
        cout << "Welcome to the Number Guessing Game!\n";
        cout << "You will guess numbers in increasing difficulty levels.\n";
        cout << "You can use one hint per game that reveals if the number is even or odd.\n";
        cout << "Good luck!\n\n";
    }

    void setupLevel() {
        maxRange = level * 50;
        maxAttempts = max(3, 10 - level);  // minimum 3 attempts
        number = rand() % maxRange + 1;    // random number between 1 and maxRange
        cout << "Level " << level << ": Guess the number between 1 and " << maxRange << ". You have " << maxAttempts << " attempts.\n";
    }
};
int main() {
    srand(time(0));  
    Player player;
    player.createProfile();
    player.showProfile();

    Game game;
    game.showRules();

    return 0;
}