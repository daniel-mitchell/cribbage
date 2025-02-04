#include <iostream>
#include <sstream>
#include "hand.h"

int main() {
    std::string handString;
    std::vector<Card> hand;
    while (std::getline(std::cin, handString)) {
        try {
            std::istringstream handStream(handString);
            hand.clear();
            while(handStream) {
                Card c;
                handStream >> c;
                hand.push_back(c);
                if (handStream.eof()) {
                    break;
                }
            }
            std::cout << scoreHand(hand) << std::endl;
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}