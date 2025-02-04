#include <stdexcept>
#include <algorithm>
#include <string>

enum class Suit {DIAMOND, CLUB, HEART, SPADE};
class Card {
    private:
        int rank;
        Suit suit;
        
        Suit charToSuit(char suitChar);
        int charToRank(char rankChar);
    public:
        Card() = default;
        Card(char rank, char suit): rank(charToRank(rank)), suit(charToSuit(suit)) {}
        Suit getSuit() {return suit;}
        int getRank() {return rank;}
        int getValue() {return std::min(rank, 10);}
        
        friend auto operator<=>(const Card& lhs, const Card& rhs) {
            if (lhs.rank == rhs.rank) {
                return lhs.suit <=> rhs.suit;
            } else {
                return lhs.rank <=> rhs.rank;
            }
        }
        
        friend auto& operator>>(std::istream& is, Card& c) {
            std::string s;
            is >> s;
            if (s.size() < 2) {
                throw std::invalid_argument("Card string too small");
            }
            c = Card(s[s.size() - 2], s[s.size() - 1]);
            return is;
        }
};
