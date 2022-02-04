//
// Created by mateu on 2022-01-18.
//

#ifndef MAIN_CPP_DECK_H
#define MAIN_CPP_DECK_H


#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>


struct deck{

    std::vector<card> deck_of_cards;

//    KONSTRUKTOR BEZARGUMENTOWY / DOMYSLNY
    deck(){

    }


//    FUNKCJA DO TWORZENIA TALII KART
    auto populate_deck()-> void {
        auto num_color = 0;

        for(auto i = (int)card::card_suit::spades; i <= (int)card::card_suit::hearts; i++){

            if(i <= (int)card::card_suit::clubs){
                num_color = (int)card::card_color::black;
            } else{
                num_color = (int)card::card_color::red;
            }

            for(auto k = (int)card::card_figure::ace; k <= (int)card::card_figure::king; k++){
                auto c = card((card::card_suit)i, (card::card_figure)k, (card::card_color)num_color);
                deck::deck_of_cards.push_back(c);
            }
        }
    }
// ZACZELO DZIALAC POPRAWNIE PO DODANIU srand(time(NULL)) - TERAZ ZAWSZE TASUJE INACZEJ, WCZESNIEJ TASOWAL
// ZA KAZDYM RAZEM TAK SAMO
    auto deck_shuffle()-> void {
        srand(time(NULL));
        std::random_shuffle(deck::deck_of_cards.begin(), deck::deck_of_cards.end());
    }
};


#endif //MAIN_CPP_DECK_H
