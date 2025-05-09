#include <iostream>
#include <vector>

class BowlingGame {
private:
    std::vector<int> rolls;

public:
    // Record a roll
    void roll(int pins) {
        rolls.push_back(pins);
    }

    int score() {
        int totalScore = 0;
        int rollIndex = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (isStrike(rollIndex)) {  // Strike
                if (frame == 9) {
                    totalScore += rolls[rollIndex] + rolls[rollIndex + 1] + rolls[rollIndex + 2];
                    break;
                }
                totalScore += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
                rollIndex += 1;
            } else if (isSpare(rollIndex)) {  
                if (frame == 9) {
                    totalScore += 10 + rolls[rollIndex + 2];
                    break;
                }
                totalScore += 10 + rolls[rollIndex + 2];
                rollIndex += 2;
            } else {  
                totalScore += rolls[rollIndex] + rolls[rollIndex + 1];
                rollIndex += 2;
            }
        }

        return totalScore;
    }

private:
    bool isStrike(int index) {
        return rolls[index] == 10;
    }

    bool isSpare(int index) {
        return rolls[index] + rolls[index + 1] == 10;
    }
};

int main() {
    BowlingGame game;
    
    // Example game input: 1 4 | 4 5 | 6 4 | 5 0 | 10 | 0 1 | 7 3 | 6 4 | 10 | 2 6
    // You can modify this vector with other test cases
    std::vector<int> inputRolls = {1, 4, 4, 5, 6, 4, 5, 0, 10, 0, 1, 7, 3, 6, 4, 10, 2, 6};

    for (int pins : inputRolls) {
        game.roll(pins);
    }

    std::cout << "Total Score: " << game.score() << std::endl;
    return 0;
}