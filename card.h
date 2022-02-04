//
// Created by mateu on 2022-01-15.
//

#ifndef MAIN_CPP_CARD_H
#define MAIN_CPP_CARD_H
#include <string>

struct card{

    enum class card_suit {spades, clubs, diamonds, hearts };
    enum class card_color {black, red};
    enum class card_figure {ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king };

    card_suit suit;
    card_color color;
    card_figure figure;
    bool face_up = false;

    card(card::card_suit s, card::card_figure f, card::card_color c){
        suit = s;
        figure = f;

        if(s == card_suit::spades || s == card_suit::clubs){
            color = card_color::black;
        } else {
            color = card_color::red;
        }

        color = c;
    }

//    KONSTRUKTOR BEZARGUMENTOWY
    card(){

    };
};

#endif //MAIN_CPP_CARD_H
