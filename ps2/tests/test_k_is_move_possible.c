#include <stdio.h>
#include "greatest.h"
#include "../k.h"

TEST test_if_move_is_possible_r() {
    struct game game = {
        .board = {
            {'A', 'A', 'A', 'A'},
            {'A', 'B', 'C', 'D'},
            {'A', 'K', 'C', 'D'},
            {'A', 'B', 'C', 'D'}
        },
        .score = 0
    };

    ASSERT_EQ_FMT(1, is_move_possible(game), "%d");

    PASS();
}

TEST test_if_move_is_possible_l() {
    struct game game = {
        .board = {
            {'A', 'A', 'A', 'A'},
            {'C', 'C', 'C', 'D'},
            {'A', 'K', 'C', 'D'},
            {'A', 'B', 'C', 'D'}
        },
        .score = 0
    };

    ASSERT_EQ_FMT(1, is_move_possible(game), "%d");

    PASS();
}


TEST test_if_move_is_possible_u() {
    struct game game = {
        .board = {
            {'A', 'A', 'A', 'A'},
            {'C', 'C', 'C', 'D'},
            {'A', 'K', 'C', 'D'},
            {'A', 'B', 'C', 'D'}
        },
        .score = 0
    };

    ASSERT_EQ_FMT(1, is_move_possible(game), "%d");
    PASS();
}

TEST test_if_move_is_possible_d() {
    struct game game = {
        .board = {
            {'A', 'A', 'A', 'A'},
            {'C', 'C', 'C', 'D'},
            {'A', 'K', 'D', 'D'},
            {'A', 'B', 'C', 'D'}
        },
        .score = 0
    };

    ASSERT_EQ_FMT(1, is_move_possible(game), "%d");
    PASS();
}

TEST test_if_move_is_possible_not_possible(){
    struct game game = {
        .board = {
            {'A', 'B', 'C', 'D'},
            {'E', 'F', 'G', 'H'},
            {'I', 'J', 'K', 'A'},
            {'B', 'C', 'D', 'E'}
        },
        .score = 0
    };

    ASSERT_EQ_FMT(0, is_move_possible(game), "%d");
    PASS();

}

TEST test_if_move_is_possible_empty(){

    struct game game = {
        .board = {
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
        },
        .score = 0
    };

    ASSERT_EQ_FMT(1, is_move_possible(game), "%d");
    PASS();

}


SUITE(test_k_is_move_possible) {
    RUN_TEST(test_if_move_is_possible_r);
    RUN_TEST(test_if_move_is_possible_l);
    RUN_TEST(test_if_move_is_possible_u);
    RUN_TEST(test_if_move_is_possible_d);
    RUN_TEST(test_if_move_is_possible_not_possible);
    RUN_TEST(test_if_move_is_possible_empty);
}
