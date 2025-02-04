#include "card.h"

Suit Card::charToSuit(char suitChar) {
    switch (suitChar) {
        case 'd':
        case 'D':
            return Suit::DIAMOND;
        case 'c':
        case 'C':
            return Suit::CLUB;
        case 'h':
        case 'H':
            return Suit::HEART;
        case 's':
        case 'S':
            return Suit::SPADE;
        default:
            throw std::invalid_argument("Invalid suit");
    }
}

int Card::charToRank(char rankChar) {
    switch (rankChar) {
        case 'k':
        case 'K':
            return 13;
        case 'q':
        case 'Q':
            return 12;
        case 'j':
        case 'J':
            return 11;
        case 'a':
        case 'A':
            return 1;
        case '0':
            return 10;
        default:
            int rank = rankChar - '0';
            if (rank < 1 || rank > 9) {
                throw std::invalid_argument("Invalid rank");
            }
            return rank;
    }
}
