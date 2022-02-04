#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <bits/stdc++.h>
#include <algorithm>



#include "card.h"
#include "deck.h"

// FUNKCJA DO DRUKOWANIA KART
auto format_card(card c)-> std::string;

#include "board.h"
#include "play.h"



int main() {

// TWORZE OBIEKT STRUCTU DECK
    auto some_deck = deck();

//    TWORZE OBIEKT STRUCTU BOARD
    auto some_board = board();

//    POPULUJE (TWORZE) DECK
    some_deck.populate_deck();


//    TWORZE KOLUMNY
    some_board.column_1 = some_board.deal_columns(some_deck, 1);
    some_board.column_2 = some_board.deal_columns(some_deck, 2);
    some_board.column_3 = some_board.deal_columns(some_deck, 3);
    some_board.column_4 = some_board.deal_columns(some_deck, 4);
    some_board.column_5 = some_board.deal_columns(some_deck, 5);
    some_board.column_6 = some_board.deal_columns(some_deck, 6);
    some_board.column_7 = some_board.deal_columns(some_deck, 7);


    auto my_play = play();

    my_play.gameplay(some_board, some_deck);

}

// FUNKCJA DO DRUKOWANIA KART
auto format_card(card c)-> std::string {

    auto formatted_card = std::string();

    switch (c.suit) {
        case card::card_suit::spades :
            formatted_card += "S";
            break;
        case card::card_suit::clubs :
            formatted_card += "C";
            break;
        case card::card_suit::diamonds :
            formatted_card += "D";
            break;
        case card::card_suit::hearts :
            formatted_card += "H";
            break;
    }

    formatted_card += "_";

    switch (c.figure) {
        case card::card_figure::ace :
            formatted_card += "A";
            break;
        case card::card_figure::two :
            formatted_card += "2";
            break;
        case card::card_figure::three :
            formatted_card += "3";
            break;
        case card::card_figure::four :
            formatted_card += "4";
            break;
        case card::card_figure::five :
            formatted_card += "5";
            break;
        case card::card_figure::six :
            formatted_card += "6";
            break;
        case card::card_figure::seven :
            formatted_card += "7";
            break;
        case card::card_figure::eight :
            formatted_card += "8";
            break;
        case card::card_figure::nine :
            formatted_card += "9";
            break;
        case card::card_figure::ten :
            formatted_card += "10";
            break;
        case card::card_figure::jack :
            formatted_card += "J";
            break;
        case card::card_figure::queen :
            formatted_card += "Q";
            break;
        case card::card_figure::king :
            formatted_card += "K";
            break;
    }

    return formatted_card;
}


