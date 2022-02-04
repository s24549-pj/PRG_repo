//
// Created by mateu on 2022-01-19.
//

#ifndef MAIN_CPP_BOARD_H
#define MAIN_CPP_BOARD_H

#include <string>
#include <vector>

struct board{

//    KOLUMNY NA KARTY
    std::vector<card> column_1;
    std::vector<card> column_2;
    std::vector<card> column_3;
    std::vector<card> column_4;
    std::vector<card> column_5;
    std::vector<card> column_6;
    std::vector<card> column_7;


//    NAZWY KOLUMN DO DRUKOWANIA NA PLANSZY
    std::string column_1_name = "C1";
    std::string column_2_name = "C2";
    std::string column_3_name = "C3";
    std::string column_4_name = "C4";
    std::string column_5_name = "C5";
    std::string column_6_name = "C6";
    std::string column_7_name = "C7";

//    STOSY NA KONKRETNE KOLORY
    std::vector<card> stack_spades;
    std::vector<card> stack_clubs;
    std::vector<card> stack_diamonds;
    std::vector<card> stack_hearts;

//    NAZWY STOSOW DO DRUKOWANIA NA PLANSZY

    std::string stack_spades_name = "SPADES  ";
    std::string stack_clubs_name = "CLUBS   ";
    std::string stack_diamonds_name = "DIAMONDS";
    std::string stack_hearts_name = "HEARTS  ";

//    KONSTRUKTOR BEZARGUMENTOWY / DOMYSLNY
    board(){

    }

    auto deal_columns(deck& some_deck, int cards_in_column) -> std::vector<card> {

        auto temp_vector = std::vector<card>();

        for (auto i = 0; i < cards_in_column; i++) {

//        LOSUJE RANDOMOWA KARTE Z DECKU DO KOLUMNY
            auto rd = std::random_device();
            auto d = std::uniform_int_distribution<int>(0, some_deck.deck_of_cards.size() - 1);
            auto num = d(rd);

            temp_vector.push_back(some_deck.deck_of_cards[num]);
            some_deck.deck_of_cards.erase(some_deck.deck_of_cards.begin() + num);
        }

//    TASUJE DECK NA KONIEC
        some_deck.deck_shuffle();

        return temp_vector;
    }


    // FUNKCJA DO DRUKOWANIA CALEJ PLANSZY
    auto print_board(deck& some_deck) -> void {

        std::string empty_symbol = "...";
        std::string face_down_symbol = "#_#";

//    DRUKUJE DECK
        std::cout << "Cards in deck: " << some_deck.deck_of_cards.size() << ' ';

        std::cout << "\t\tDECK: ";
        if (some_deck.deck_of_cards.empty()) {
            std::cout << empty_symbol;
        } else if (!some_deck.deck_of_cards.empty()) {
//            DRUKUJE TYLKO OSTATNIA KARTE Z DECKU
            std::cout << format_card(some_deck.deck_of_cards.back());

//            DRUKOWANIE WSZYSTKICH KART Z DECKU
//            std::cout << "\nDECK: ";
//            for (auto e: some_deck.deck_of_cards) {
//                std::cout << format_card(e) << ' ';
//            }
        }
        std::cout << "\n\n";

//    DRUKUJE STOSY NA KARTY DANYCH KOLOROW
        std::cout << board::stack_spades_name << ": ";
        if (board::stack_spades.empty()) {
            std::cout << empty_symbol;
        } else if (!board::stack_spades.empty()) {
            for (auto e: board::stack_spades) {
                std::cout << format_card(e) << ' ';
            }
        }
        std::cout << '\n';

        std::cout << board::stack_clubs_name << ": ";
        if (board::stack_clubs.empty()) {
            std::cout << empty_symbol;
        } else if (!board::stack_clubs.empty()) {
            for (auto e: board::stack_clubs) {
                std::cout << format_card(e) << ' ';
            }
        }
        std::cout << '\n';

        std::cout << board::stack_diamonds_name << ": ";
        if (board::stack_diamonds.empty()) {
            std::cout << empty_symbol;
        } else if (!board::stack_diamonds.empty()) {
            for (auto e: board::stack_diamonds) {
                std::cout << format_card(e) << ' ';
            }
        }
        std::cout << '\n';

        std::cout << board::stack_hearts_name << ": ";
        if (board::stack_hearts.empty()) {
            std::cout << empty_symbol;
        } else if (!board::stack_hearts.empty()) {
            for (auto e: board::stack_hearts) {
                std::cout << format_card(e) << ' ';
            }
        }
        std::cout << "\n\n";

//    DRUKUJE KOLUMNY
//  JESLI KOLUMNA JEST PUSTA = "EMPTY"; JESLI NIE JEST PUSTA = DRUKUJ ZAWARTOSC

        std::cout << board::column_1_name << ": ";
        if (board::column_1.empty()) {
            std::cout << empty_symbol;
        } else if (!board::column_1.empty()) {
            for (auto i = 0; i < board::column_1.size(); i++) {
                if (i == (board::column_1.size() - 1)) {
                    board::column_1[i].face_up = true;
                    std::cout << format_card(board::column_1[i]) << ' ';
                } else if (board::column_1[i].face_up) {
                    std::cout << format_card(board::column_1[i]) << ' ';
                } else if (!board::column_1[i].face_up) {
                    std::cout << face_down_symbol << ' ';
                }
            }
        }
        std::cout << '\n';

        std::cout << board::column_2_name << ": ";
        if (board::column_2.empty()) {
            std::cout << empty_symbol;
        } else if (!board::column_2.empty()) {
            for (auto i = 0; i < board::column_2.size(); i++) {
                if (i == (board::column_2.size() - 1)) {
                    board::column_2[i].face_up = true;
                    std::cout << format_card(board::column_2[i]) << ' ';
                } else if (board::column_2[i].face_up) {
                    std::cout << format_card(board::column_2[i]) << ' ';
                } else if (!board::column_2[i].face_up) {
                    std::cout << face_down_symbol << ' ';
                }
            }
        }
        std::cout << '\n';

        std::cout << board::column_3_name << ": ";
        if (board::column_3.empty()) {
            std::cout << empty_symbol;
        } else if (!board::column_3.empty()) {
            for (auto i = 0; i < board::column_3.size(); i++) {
                if (i == (board::column_3.size() - 1)) {
                    board::column_3[i].face_up = true;
                    std::cout << format_card(board::column_3[i]) << ' ';
                } else if (board::column_3[i].face_up) {
                    std::cout << format_card(board::column_3[i]) << ' ';
                } else if (!board::column_3[i].face_up) {
                    std::cout << face_down_symbol << ' ';
                }
            }
        }
        std::cout << '\n';

        std::cout << board::column_4_name << ": ";
        if (board::column_4.empty()) {
            std::cout << empty_symbol;
        } else if (!board::column_4.empty()) {
            for (auto i = 0; i < board::column_4.size(); i++) {
                if (i == (board::column_4.size() - 1)) {
                    board::column_4[i].face_up = true;
                    std::cout << format_card(board::column_4[i]) << ' ';
                } else if (board::column_4[i].face_up) {
                    std::cout << format_card(board::column_4[i]) << ' ';
                } else if (!board::column_4[i].face_up) {
                    std::cout << face_down_symbol << ' ';
                }
            }
        }
        std::cout << '\n';

        std::cout << board::column_5_name << ": ";
        if (board::column_5.empty()) {
            std::cout << empty_symbol;
        } else if (!board::column_5.empty()) {
            for (auto i = 0; i < board::column_5.size(); i++) {
                if (i == (board::column_5.size() - 1)) {
                    board::column_5[i].face_up = true;
                    std::cout << format_card(board::column_5[i]) << ' ';
                } else if (board::column_5[i].face_up) {
                    std::cout << format_card(board::column_5[i]) << ' ';
                } else if (!board::column_5[i].face_up) {
                    std::cout << face_down_symbol << ' ';
                }
            }
        }
        std::cout << '\n';

        std::cout << board::column_6_name << ": ";
        if (board::column_6.empty()) {
            std::cout << empty_symbol;
        } else if (!board::column_6.empty()) {
            for (auto i = 0; i < board::column_6.size(); i++) {
                if (i == (board::column_6.size() - 1)) {
                    board::column_6[i].face_up = true;
                    std::cout << format_card(board::column_6[i]) << ' ';
                } else if (board::column_6[i].face_up) {
                    std::cout << format_card(board::column_6[i]) << ' ';
                } else if (!board::column_6[i].face_up) {
                    std::cout << face_down_symbol << ' ';
                }
            }
        }
        std::cout << '\n';

        std::cout << board::column_7_name << ": ";
        if (board::column_7.empty()) {
            std::cout << empty_symbol;
        } else if (!board::column_7.empty()) {
            for (auto i = 0; i < board::column_7.size(); i++) {
                if (i == (board::column_7.size() - 1)){
                    board::column_7[i].face_up = true;
                    std::cout << format_card(board::column_7[i]) << ' ';
                } else if (board::column_7[i].face_up){
                    std::cout << format_card(board::column_7[i]) << ' ';
                }  else if(!board::column_7[i].face_up){
                    std::cout << face_down_symbol << ' ';
                }
            }
        }
        std::cout << "\n\n";

    }

};


#endif //MAIN_CPP_BOARD_H
