#include <algorithm>
#include "hand.h"

int scoreHand(std::vector<Card>& hand) {
    // Cut card must be last
    if (hand.size() != 5) {
        throw std::invalid_argument("Hand must be five cards");
    }
    int score = 0;
    score += scoreNobs(hand);
    score += scoreFlush(hand);
    std::sort(hand.begin(), hand.end());
    score += scoreFifteens(hand);
    score += scoreSets(hand);
    score += scoreRuns(hand);
    return score;
}

int scoreNobs(std::vector<Card>& hand) {
    // Cut card must be last
    Suit cutSuit = hand[4].getSuit();
    for (int i = 0; i < 4; i++) {
        if (hand[i].getRank() == 11 && hand[i].getSuit() == cutSuit) {
            return 1;
        }
    }
    return 0;
}

int scoreFlush(std::vector<Card>& hand) {
    // Cut card must be last
    Suit firstSuit = hand[0].getSuit();
    for (int i = 1; i < 4; i++) {
        if (hand[i].getSuit() != firstSuit) {
            return 0;
        }
    }
    return hand[4].getSuit() == firstSuit ? 5 : 4;
}

int scoreFifteens(std::vector<Card>& hand) {
    return scoreFifteens(hand, 0, 0);
}

int scoreFifteens(std::vector<Card>& hand, int offset, int count) {
    int score = 0;
    for (int i = offset; i < 5; i++) {
        if (count + hand[i].getValue() == 15) {
            score += 2;
        } else if (count + hand[i].getValue() < 15) {
            score += scoreFifteens(hand, i + 1, count + hand[i].getValue());
        }
    }
    return score;
}

int scoreSets(std::vector<Card>& hand) {
    // Hand must be ordered by rank
    int score = 0;
    int lastRank = hand[0].getRank();
    int count = 1;
    for (int i = 1; i < 5; i++) {
        if (hand[i].getRank() == lastRank) {
            count++;
        } else {
            score += count*(count - 1);
            lastRank = hand[i].getRank();
            count = 1;
        }
    }
    score += count*(count - 1);
    return score;
}

int scoreRuns(std::vector<Card>& hand) {
    int length = 1;
    int dups = 1;
    int mult = 1;
    int lastRank = hand[0].getRank();
    int score = 0;
    for (int i = 1; i < 5; i++) {
        if (hand[i].getRank() == lastRank) {
            dups++;
        } else if (std::abs(hand[i].getRank() - lastRank) == 1) {
            mult *= dups;
            dups = 1;
            length++;
        } else {
            score += length < 3 ? 0 : length * mult;
            mult = 1;
            dups = 1;
        }
        lastRank = hand[i].getRank();
    }
    score += length < 3 ? 0 : length * mult;
    return score;
}
