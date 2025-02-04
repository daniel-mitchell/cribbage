#include <vector>
#include "card.h"

int scoreHand(std::vector<Card>& hand);
int scoreNobs(std::vector<Card>& hand);
int scoreFlush(std::vector<Card>& hand);
int scoreFifteens(std::vector<Card>& hand);
int scoreFifteens(std::vector<Card>& hand, int offset, int count);
int scoreSets(std::vector<Card>& hand);
int scoreRuns(std::vector<Card>& hand);
