//
// Created by mateu on 2022-01-19.
//

#ifndef MAIN_CPP_PLAY_H
#define MAIN_CPP_PLAY_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

// STRUCT FUNKCYJNY DO GRY
struct play{

//    std::string player_order;
    bool game_run = true;


    auto is_lower(card& c1, card& c2) -> bool {
        auto c1_rank = (int)c1.figure;
        auto c2_rank = (int)c2.figure;
        auto rank_difference = c2_rank - c1_rank;

        if(rank_difference == 1){
            return true;
        } else{
            return false;
        }
    }

    auto is_higher(card& c1, card& c2) -> bool {
        auto c1_rank = (int)c1.figure;
        auto c2_rank = (int)c2.figure;
        auto rank_difference = c1_rank - c2_rank;

        if(rank_difference == 1){
            return true;
        } else{
            return false;
        }
    }


// METODA DO SPRAWDZANIA CZY KOLEJNE KARTY MAJA INNE KOLORY - DO PRZENOSZENIA KILKU KART
    auto check_move_multiple_colors(std::vector<card> const& column, int const& amount) -> bool {

        auto good_cards_count = 0;

        for(auto i = amount; i > 1; i--) {
            if (column[column.size() - i].color != column[column.size() - i + 1].color) {
                good_cards_count++;
            }
        }

        if(good_cards_count == (amount - 1)){
            return true;
        } else {
            return false;
        }
    }

// METODA DO SPRAWDZANIA CZY KOLEJNE KARTY MAJA O 1 NIZSZE FIGURY - DO PRZENOSZENIA KILKU KART
    auto check_move_multiple_figures(std::vector<card> const& column, int const& amount) -> bool {

        auto good_cards_count = 0;

        for (auto i = amount; i > 1; i--) {
            if ((int) column[column.size() - i].figure > (int) column[column.size() - i + 1].figure) {
                good_cards_count++;
            }
        }

        if(good_cards_count == (amount - 1)){
            return true;
        } else {
            return false;
        }
    }

//  SPRAWDZAM CZY KARTY DO PRZENIESIENIA MAJA ROZNE KOLORY I FIGURY NIZSZE O 1
    auto check_move_multiple (std::vector<card> const& column, int const& amount) -> bool {

        if(check_move_multiple_colors(column, amount)) {
            if (check_move_multiple_figures(column, amount)) {
                return true;
            } else {
                return false;
            }
        }else {
            return false;
        }
    }


    auto move_multiple_take_from(std::vector<card>& column, std::vector<card>& temp_vector,
                                 int const& amount, bool& bad_move) -> void {
        if(column.empty()){
            std::cout << "\n\t\tColumn is empty!\n\n";
            bad_move = true;
            return;
        } else if(amount > column.size()){
            std::cout << "\n\t\tInvalid input! There is " << column.size() << " cards in column.\n\n";
            bad_move = true;
            return;
        } else{
            if(check_move_multiple(column, amount)){
                for(auto i = amount; i > 0; i--){
                    temp_vector.push_back(column[column.size() - i]);
                }
            } else {
                std::cout << "\n\t\tInvalid move! Cards should have different colors and decreasing figures!\n\n";
                bad_move = true;
                return;
            }
        }
    }


    auto move_multiple_take_to(std::vector<card>& column, std::vector<card>& temp_vector,
                               std::string const& column_name, int const& amount, bool& bad_move,
                               bool& good_move) -> void {

        if(column.empty() && temp_vector[0].figure != card::card_figure::king){
            std::cout << "\n\t\tFirst card on column should be King!\n\n";
            bad_move = true;
            return;
        } else if(column.empty() && temp_vector[0].figure == card::card_figure::king){
            for(auto i = 0; i < amount; i++){
                column.push_back(temp_vector[i]);
            }
            good_move = true;
        } else {
            if(is_lower(temp_vector[0], column.back()) && column.back().color != temp_vector[0].color){
                for(auto i = 0; i < amount; i++){
                    column.push_back(temp_vector[i]);
                }
                good_move = true;
            } else {
                std::cout << "\n\t\tFirst card taken must be different color and 1 lower than last on "
                          << column_name << ".\n\n";
                bad_move = true;
                return;
            }
        }
    }


    auto multiple_move_cards_delete(std::vector<card>& column, int const& amount) -> void{
        for (auto i = 0; i < amount; i++) {
            column.pop_back();
        }
    }


//    METODA DO PRZEKLADANIA KILKU KART NA RAZ
    auto move_multiple(board& some_board, deck& some_deck) -> void {

        auto take_from = std::string();
        auto take_to = std::string();
        auto amount = 0;
        auto temp_vector = std::vector<card>();
        auto good_move = false;
        auto bad_move = false;

        std::cout << "Take from? (Columns: 1,2,3,4,5,6,7; Break: b)";
        std::cin >> take_from;

        std::cout << "How many cards? (Integer)";
        std::cin >> amount;

//        IF SKAD BIORE KILKA KART
        if(take_from == "1"){
            play::move_multiple_take_from(some_board.column_1, temp_vector,amount,bad_move);
            if(bad_move){
                return;
            }
        } else if(take_from == "2"){
            play::move_multiple_take_from(some_board.column_2, temp_vector,amount,bad_move);
            if(bad_move){
                return;
            }
        } else if(take_from == "3"){
            play::move_multiple_take_from(some_board.column_3, temp_vector,amount,bad_move);
            if(bad_move){
                return;
            }
        } else if(take_from == "4"){
            play::move_multiple_take_from(some_board.column_4, temp_vector,amount,bad_move);
            if(bad_move){
                return;
            }
        } else if(take_from == "5"){
            play::move_multiple_take_from(some_board.column_5, temp_vector,amount,bad_move);
            if(bad_move){
                return;
            }
        } else if(take_from == "6"){
            play::move_multiple_take_from(some_board.column_6, temp_vector,amount,bad_move);
            if(bad_move){
                return;
            }
        } else if(take_from == "7"){
            play::move_multiple_take_from(some_board.column_7, temp_vector,amount,bad_move);
            if(bad_move){
                return;
            }
        } else if(take_from == "b"){
            return;
        } else {
            std::cout << "\n\t\tInvalid input! (take from)\n\n";
            return;
        }


        std::cout << "\n\t\tCards you take: ";
        for(auto e : temp_vector){
            std::cout << format_card(e) << ' ';
        }
        std::cout << "\n\n";

        std::cout << "Where to? (Columns: 1,2,3,4,5,6,7)";
        std::cin >> take_to;


//        IF GDZIE KLADE KILKA KART
        if(take_to == "1"){
            play::move_multiple_take_to(some_board.column_1, temp_vector, some_board.column_1_name,
                                        amount, bad_move, good_move);
            if(bad_move){
                return;
            }
        } else if(take_to == "2"){
            play::move_multiple_take_to(some_board.column_2, temp_vector, some_board.column_2_name,
                                        amount, bad_move, good_move);
            if(bad_move){
                return;
            }
        } else if(take_to == "3"){
            play::move_multiple_take_to(some_board.column_3, temp_vector, some_board.column_3_name,
                                        amount, bad_move, good_move);
            if(bad_move){
                return;
            }
        } else if(take_to == "4"){
            play::move_multiple_take_to(some_board.column_4, temp_vector, some_board.column_4_name,
                                        amount, bad_move, good_move);
            if(bad_move){
                return;
            }
        } else if(take_to == "5"){
            play::move_multiple_take_to(some_board.column_5, temp_vector, some_board.column_5_name,
                                        amount, bad_move, good_move);
            if(bad_move){
                return;
            }
        } else if(take_to == "6"){
            play::move_multiple_take_to(some_board.column_6, temp_vector, some_board.column_6_name,
                                        amount, bad_move, good_move);
            if(bad_move){
                return;
            }
        } else if(take_to == "7"){
            play::move_multiple_take_to(some_board.column_7, temp_vector, some_board.column_7_name,
                                        amount, bad_move, good_move);
            if(bad_move){
                return;
            }
        } else {
            std::cout << "\n\t\tInvalid input! (take to)\n\n";
            return;
        }


//        IF GDZIE USUWAM ZABRANE KARTY JESLI RUCH BYL DOBRY
        if(good_move){
            if(take_from == "1"){
                play::multiple_move_cards_delete(some_board.column_1, amount);
            } else if(take_from == "2"){
                play::multiple_move_cards_delete(some_board.column_2, amount);
            } else if(take_from == "3"){
                play::multiple_move_cards_delete(some_board.column_3, amount);
            } else if(take_from == "4"){
                play::multiple_move_cards_delete(some_board.column_4, amount);
            } else if(take_from == "5"){
                play::multiple_move_cards_delete(some_board.column_5, amount);
            } else if(take_from == "6"){
                play::multiple_move_cards_delete(some_board.column_6, amount);
            } else if(take_from == "7"){
                play::multiple_move_cards_delete(some_board.column_7, amount);
            }
        }

    }



    auto move_take_from(std::vector<card>& column, std::vector<card>& temp_vec, bool& bad_move) -> void {

        if(column.empty()){
            std::cout << "\n\t\tThis column is empty!\n\n";
            bad_move = true;
            return;
        } else if(!column.empty()){
            temp_vec.push_back(column.back());
        }
    }

    auto move_take_to_columns(std::vector<card>& column, std::vector<card>& temp_vec, bool& good_move,
                              bool& bad_move) -> void {
//        SPRAWDZAM CZY KOLUMNA JEST PUSTA
        if(column.empty()){
            if(temp_vec.back().figure != card::card_figure::king){
                std::cout << "\n\t\tYou can put only King on empty column!\n\n";
                temp_vec.pop_back();
                bad_move = true;
                return;
            } else {
                column.push_back(temp_vec.back());
                temp_vec.pop_back();
                good_move = true;
            }
//                    SPRAWDZAM CZY KOLORY SA TAKIE SAME - POWINNY BYC ROZNE W KOLUMNIE - INACZEJ - ZLY RUCH
        } else if(temp_vec.back().color == column.back().color){
            std::cout << "\n\t\tCan't move same colors!\n\n";
            std::cin;
            temp_vec.pop_back();
            bad_move = true;
            return;
        } else{
//                    SPRAWDZAM CZY KARTA KTORA KLADE JEST MNIEJSZA - JESLI NIE JEST - ZLY RUCH
            if(!is_lower(temp_vec.back(), column.back())){
                std::cout << "\n\t\tInvalid move!\n\n";
                temp_vec.pop_back();
                bad_move = true;
                return;
            } else{
//                        JESLI POWYZSZE WARUNKI NIE ZOSTALY SPENIONE - RUCH JEST DOBRY
                column.push_back(temp_vec.back());
                temp_vec.pop_back();
                good_move = true;
            }
        }
    }

    auto move_take_to_stacks(std::vector<card>& stack, std::vector<card>& temp_vec, int stack_suit,
                             bool& good_move, bool& bad_move) -> void {

//                SPRAWDZAM CZY KOLOR ZGADZA SIE Z KOLOREM STOSU - JAK NIE - ZLY RUCH
        if(temp_vec.back().suit != (card::card_suit)stack_suit){
            std::cout << "\n\t\tWrong stack_suit!\n\n";
            temp_vec.pop_back();
            bad_move = true;
            return;
        } else {
//                    JESLI KOLOR SIE ZGADZA
//                    JESLI STOS JEST PUSTY I KARTA TO AS - DOBRY RUCH
            if(stack.empty() && temp_vec.back().figure == card::card_figure::ace){
                stack.push_back(temp_vec.back());
                temp_vec.pop_back();
                good_move = true;
//                    SPRAWDZAM CZY KARTA KTORA KLADE JEST O 1 WIEKSZA OD POPRZEDNIEJ
            } else if (is_higher(temp_vec.back(), stack.back())){
                stack.push_back(temp_vec.back());
                temp_vec.pop_back();
                good_move = true;
//                    JESLI COS SIE NIE ZGADZA - ZLY RUCH
            } else {
                std::cout << "\n\t\tInvalid move!\n\n";
                temp_vec.pop_back();
                bad_move = true;
                return;
            }
        }
    }



//      METODA DO PRZEKLADANIA KART MIEDZY DECKIEM, STOSAMI I KOLUMNAMI
    auto move(board& some_board, deck& some_deck) -> void {

        auto take_from = std::string();
        auto take_to = std::string();
        auto temp_vec = std::vector<card>();
        auto good_move = false;
        auto bad_move = false;
        auto stop_console = std::string();


            std::cout << "Take from? (Columns: 1,2,3,4,5,6,7; Deck: d; Break: b)";

            std::cin >> take_from;
            std::transform(take_from.begin(), take_from.end(), take_from.begin(), ::tolower);


// IF SKAD BIORE KARTE
            if (take_from == "1") {
                play::move_take_from(some_board.column_1, temp_vec, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_from == "2") {
                play::move_take_from(some_board.column_2, temp_vec, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_from == "3") {
                play::move_take_from(some_board.column_3, temp_vec, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_from == "4") {
                play::move_take_from(some_board.column_4, temp_vec, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_from == "5") {
                play::move_take_from(some_board.column_5, temp_vec, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_from == "6") {
                play::move_take_from(some_board.column_6, temp_vec, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_from == "7") {
                play::move_take_from(some_board.column_7, temp_vec, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_from == "d") {
                play::move_take_from(some_deck.deck_of_cards, temp_vec, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_from == "b") {
                return;
            } else {
                std::cout << "\n\t\tInvalid input!\n\n";
                return;
            }


            std::cout << "Where to? (Columns: 1,2,3,4,5,6,7; Stacks: s,c,d,h;)";
            std::cin >> take_to;
            std::transform(take_to.begin(), take_to.end(), take_to.begin(), ::tolower);
            std::cout << "\n\n";


// IF GDZIE PRZENOSZE KARTE
            if (take_to == "1") {
                play::move_take_to_columns(some_board.column_1, temp_vec, good_move, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_to == "2") {
                play::move_take_to_columns(some_board.column_2, temp_vec, good_move, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_to == "3") {
                play::move_take_to_columns(some_board.column_3, temp_vec, good_move, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_to == "4") {
                play::move_take_to_columns(some_board.column_4, temp_vec, good_move, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_to == "5") {
                play::move_take_to_columns(some_board.column_5, temp_vec, good_move, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_to == "6") {
                play::move_take_to_columns(some_board.column_6, temp_vec, good_move, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_to == "7") {
                play::move_take_to_columns(some_board.column_7, temp_vec, good_move, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_to == "s") {
                play::move_take_to_stacks(some_board.stack_spades, temp_vec, 0, good_move, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_to == "c") {
                play::move_take_to_stacks(some_board.stack_clubs, temp_vec, 1, good_move, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_to == "d") {
                play::move_take_to_stacks(some_board.stack_diamonds, temp_vec, 2, good_move, bad_move);
                if(bad_move){
                    return;
                }
            } else if (take_to == "h") {
                play::move_take_to_stacks(some_board.stack_hearts, temp_vec, 3, good_move, bad_move);
                if(bad_move){
                    return;
                }
            } else {
                std::cout << "\n\t\tInvalid input!\n\n";
                return;
            }

// SWITCH USUWAJACY KARTE Z KOLUMNY Z KTOREJ ZOSTALA ZABRANA
// DZIALA TYLKO JESLI RUCH BYL WYKONANY DOBRZE
            if (good_move) {
                if (take_from == "1") {
//  JESLI RUCH BYL DOBRY - USUWAM KARTE KTORA ZABRALEM ZEBY JEJ NIE DUBLOWAC
                    some_board.column_1.pop_back();
                } else if (take_from == "2") {
                    some_board.column_2.pop_back();
                } else if (take_from == "3") {
                    some_board.column_3.pop_back();
                } else if (take_from == "4") {
                    some_board.column_4.pop_back();
                } else if (take_from == "5") {
                    some_board.column_5.pop_back();
                } else if (take_from == "6") {
                    some_board.column_6.pop_back();
                } else if (take_from == "7") {
                    some_board.column_7.pop_back();
                } else if (take_from == "d") {
                    some_deck.deck_of_cards.pop_back();
                }
            }

    }


//    METODA DO PRZEKLADANIA KART W DECKU
    auto move_cards_in_deck(deck& some_deck) -> void{
        auto temp = card();
        temp = some_deck.deck_of_cards.back();
        some_deck.deck_of_cards.pop_back();
        some_deck.deck_of_cards.insert(some_deck.deck_of_cards.begin(), temp);
    }

//  DRUKUJE NA KONIEC PELNE STACKI DLA ZWYCIEZCY
    auto print_stack_for_winner(board const& some_board) -> void {
        std::cout << some_board.stack_spades_name << ": ";
            for (auto e: some_board.stack_spades) {
                std::cout << format_card(e) << ' ';
        }
        std::cout << '\n';

        std::cout << some_board.stack_clubs_name << ": ";
        for (auto e: some_board.stack_clubs) {
            std::cout << format_card(e) << ' ';
        }
        std::cout << '\n';

        std::cout << some_board.stack_diamonds_name << ": ";
        for (auto e: some_board.stack_diamonds) {
            std::cout << format_card(e) << ' ';
        }
        std::cout << '\n';

        std::cout << some_board.stack_hearts_name << ": ";
        for (auto e: some_board.stack_diamonds) {
            std::cout << format_card(e) << ' ';
        }
        std::cout << '\n';

        std::cout << "\n\n";
    }


//    METODA ZAWIERAJACA ROZGRYWKE W PASJANSA
    auto gameplay(board& some_board, deck& some_deck)-> void {

        auto player_order = std::string();

        while(game_run){

            some_board.print_board(some_deck);

            std::cout << "Choose your move: \n"
                      <<"d - move cards in deck\n"
                      <<"mm - move multiple cards\n"
                      <<"m - move card\n"
                      <<"e - exit game\n"
                      <<"Type in move: ";

            std::cin >> player_order;
//  ZAMIENIAM INPUT NA MALE LITERY - WSZEDZIE PRZYJMUJE MALE LITERY
            std::transform(player_order.begin(), player_order.end(),player_order.begin(), ::tolower);
            std::cout << '\n';


            if(player_order == "e"){
                game_run = false;
                std::cout << "\n\t\tEXIT GAME\n\n";
            } else if(player_order == "d"){
                play::move_cards_in_deck(some_deck);
            } else if(player_order == "m"){
                play::move(some_board, some_deck);
            } else if(player_order == "mm"){
                play::move_multiple(some_board, some_deck);
            } else {
                std::cout << "\n\t\tWrong command!\n\n";
            }

            if(some_board.stack_spades.size() == 13 && some_board.stack_clubs.size() == 13 &&
               some_board.stack_diamonds.size() == 13 && some_board.stack_hearts.size() == 13){

                std::cout << "\n\t\t!!!CONGRATULATIONS YOU WIN!!!\n\n";

                print_stack_for_winner(some_board);

                game_run = false;
            }
//            player_order.clear();

        }
    }

};


#endif //MAIN_CPP_PLAY_H
