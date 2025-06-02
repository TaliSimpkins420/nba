#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

struct Player {
    std::string name;
    std::string team;
    double ppg; // Points per game
    double apg; // Assists per game
    double rpg; // Rebounds per game
};

std::vector<Player> players;

double getValidatedInput(const std::string& prompt) {
    double value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cin.clear(); // clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid input. Please enter a number: ";
    }
    std::cin.ignore(); // clean up leftover newline
    return value;
}

void addPlayer() {
    Player p;
    std::cout << "Enter player name: ";
    std::getline(std::cin, p.name);
    std::cout << "Enter team name: ";
    std::getline(std::cin, p.team);

    p.ppg = getValidatedInput("Enter points per game: ");
    p.apg = getValidatedInput("Enter assists per game: ");
    p.rpg = getValidatedInput("Enter rebounds per game: ");

    players.push_back(p);
    std::cout << "Player added successfully!\n";
}

void showLeaderboard() {
    if (players.empty()) {
        std::cout << "No players added yet.\n";
        return;
    }

    std::cout << "\nTop Scorers Leaderboard:\n";
    std::cout << std::fixed << std::setprecision(1);

    for (size_t i = 0; i < players.size(); ++i) {
        std::cout << i + 1 << ". " << players[i].name
                  << " (" << players[i].team << ") - "
                  << players[i].ppg << " PPG\n";
    }
}

void comparePlayers() {
    if (players.size() < 2) {
        std::cout << "Need at least 2 players to compare.\n";
        return;
    }

    std::string name1, name2;
    std::cout << "Enter first player name: ";
    std::getline(std::cin, name1);
    std::cout << "Enter second player name: ";
    std::getline(std::cin, name2);

    Player* p1 = nullptr;
    Player* p2 = nullptr;

    for (auto& p : players) {
        if (p.name == name1) p1 = &p;
        if (p.name == name2) p2 = &p;
    }

    if (p1 && p2) {
        std::cout << "\nPlayer Comparison:\n";
        std::cout << std::fixed << std::setprecision(1);
        std::cout << name1 << " vs " << name2 << "\n";
        std::cout << "PPG: " << p1->ppg << " vs " << p2->ppg << "\n";
        std::cout << "APG: " << p1->apg << " vs " << p2->apg << "\n";
        std::cout << "RPG: " << p1->rpg << " vs " << p2->rpg << "\n";
    } else {
        std::cout << "One or both players not found.\n";
    }
}

int main() {
    int choice;
    do {
        std::cout << "\nNBA Stats Tracker\n";
        std::cout << "1. Add Player\n";
        std::cout << "2. Show Leaderboard\n";
        std::cout << "3. Compare Two Players\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore(); // clear newline

        switch (choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                showLeaderboard();
                break;
            case 3:
                comparePlayers();
                break;
            case 4:
                std::cout << " Goodbye!\n";
                break;
            default:
                std::cout << "Invalid option. Please choose 1-4.\n";
        }
    } while (choice != 4);

    return 0;
}



