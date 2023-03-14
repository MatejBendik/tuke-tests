#include <stdio.h>
#include "greatest.h"
#include "../k.h"

#define ASSERT_EQ_ARRAYS(size, arr_expected, arr_given)                     \
    do {                                                                    \
        for (int idx = 0; idx < size; idx++) {                              \
            ASSERT_EQ_FMT(arr_expected[idx], arr_given[idx], "%d");         \
        }                                                                   \
    } while(0)                                                              \

#define ASSERT_EQ_MATRIX(rows, columns, arr_expected, arr_given)            \
    do {                                                                    \
        for (int row = 0; row < rows; row++) {                              \
            ASSERT_EQ_ARRAYS(columns, arr_expected[row], arr_given[row]);   \
        }                                                                   \
    } while(0)                                                              \

TEST test_k_update_r() {

    struct game game = {
        .board = {
            {' ', ' ', ' ', ' '},
            {'J', 'H', ' ', 'D'},
            {' ', ' ', 'E', 'A'},
            {'H', ' ', 'D', 'A'}
        },
        .score = 7604
    };

    struct game game_e = {
        .board = {
            {' ', ' ', ' ', ' '},
            {' ', 'J', 'H', 'D'},
            {' ', ' ', 'E', 'A'},
            {' ', 'H', 'D', 'A'}
        },
        .score = 7604
    };

    printf("Original board: ");
    print_game_board(4, game.board);

    printf("Expected output: ");
    print_game_board(4, game_e.board);

    printf("You produced: ");
    update(&game, 0, 1);
    print_game_board(4, game.board);

    ASSERT_EQ_MATRIX(4,4, game_e.board, game.board);
    PASSm("Test for K module update() function game board for comparison for move '>' passed!");
}


TEST test_k_update_l() {

    struct game game = {
        .board = {
            {' ', ' ', ' ', ' '},
            {'J', 'D', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', 'G'}
        },
        .score = 1833
    };

    struct game game_e = {
        .board = {
            {' ', ' ', ' ', ' '},
            {'J', 'D', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {'G', ' ', ' ', ' '}
        },
        .score = 1833
    };

    printf("Original board: ");
    print_game_board(4, game.board);

    printf("Expected output: ");
    print_game_board(4, game_e.board);

    printf("You produced: ");
    update(&game, 0, -1);
    print_game_board(4, game.board);

    ASSERT_EQ_MATRIX(4,4, game_e.board, game.board);
    PASSm("Test for K module update() function game board for comparison for move '<' passed!");
}

TEST test_k_update_u() {

    struct game game = {
        .board = {
            {' ', ' ', ' ', 'H'},
            {' ', ' ', 'H', ' '},
            {' ', ' ', ' ', 'B'},
            {' ', 'B', ' ', 'D'}
        },
        .score = 7583
    };

    struct game game_e = {
        .board = {
            {' ', 'B', 'H', 'H'},
            {' ', ' ', ' ', 'B'},
            {' ', ' ', ' ', 'D'},
            {' ', ' ', ' ', ' '}
        },
        .score = 7583
    };

    printf("Original board: ");
    print_game_board(4, game.board);

    printf("Expected output: ");
    print_game_board(4, game_e.board);

    printf("You produced: ");
    update(&game, -1, 0);
    print_game_board(4, game.board);

    ASSERT_EQ_MATRIX(4,4, game_e.board, game.board);
    PASSm("Test for K module update() function game board for comparison for move '^' passed!");
}

TEST test_k_update_d() {

    struct game game = {
        .board = {
            {' ', 'C', 'J', 'I'},
            {' ', ' ', ' ', ' '},
            {'I', 'D', ' ', 'D'},
            {' ', 'J', 'J', 'G'}
        },
        .score = 4607
    };

    struct game game_e = {
        .board = {
            {' ', ' ', ' ', ' '},
            {' ', 'C', ' ', 'I'},
            {' ', 'D', ' ', 'D'},
            {'I', 'J', 'K', 'G'}
        },
        .score = 4607
    };

    printf("Original board: ");
    print_game_board(4, game.board);

    printf("Expected output: ");
    print_game_board(4, game_e.board);

    printf("You produced: ");
    update(&game, 1, 0);
    print_game_board(4, game.board);

    ASSERT_EQ_MATRIX(4,4, game_e.board, game.board);
    PASSm("Test for K module update() function game board for comparison for move 'v' passed!");
}

TEST test_k_update_score_r(){
    struct game game = {
        .board = {
            {' ', 'J', 'J', ' '},
            {' ', 'J', ' ', 'F'},
            {'E', 'F', 'G', ' '},
            {' ', ' ', 'D', ' '}
        },
        .score = 3576
    };

    struct game game_e = {
        .board = {
            {' ', ' ', ' ', ' '},
            {' ', 'C', ' ', 'I'},
            {' ', 'D', ' ', 'D'},
            {'I', 'J', 'K', 'G'}
        },
        .score = 5624
    };

    printf("Original board: ");
    print_game_board(4, game.board);
    printf("Original score: %d\n", game.score);

    printf("Expected score: %d\n", game_e.score);
    //print_game_board(4, game_e.board);

    printf("You produced: ");
    update(&game, 0, 1);
    print_game_board(4, game.board);
    printf("Your score: %d\n", game.score);

    ASSERT_EQ_FMT(game_e.score, game.score, "%d");
    PASSm("Test for K module update() function with score comparison passed!");

}

TEST test_k_update_score_d(){
    struct game game = {
        .board = {
            {' ', 'C', 'J', 'I'},
            {' ', ' ', ' ', ' '},
            {'I', 'D', ' ', 'D'},
            {' ', ' ', 'J', 'G'}
        },
        .score = 4607
    };

    struct game game_e = {
        .board = {
            {' ', 'C', 'J', 'I'},
            {' ', ' ', ' ', ' '},
            {'I', 'D', ' ', 'D'},
            {' ', ' ', 'J', 'G'}
        },
        .score = 6655
    };

    printf("Original board: ");
    print_game_board(4, game.board);
    printf("Original score: %d\n", game.score);

    printf("Expected score: %d\n", game_e.score);
    //print_game_board(4, game_e.board);

    printf("You produced: ");
    update(&game, 1, 0);
    print_game_board(4, game.board);
    printf("Your score: %d\n", game.score);

    ASSERT_EQ_FMT(game_e.score, game.score, "%d");
    PASSm("Test for K module update() function with score comparison passed!");

}

SUITE(test_k_update) {
    // tests for board
    RUN_TEST(test_k_update_r);
    RUN_TEST(test_k_update_l);
    RUN_TEST(test_k_update_u);
    RUN_TEST(test_k_update_d);

    // tests for score
    RUN_TEST(test_k_update_score_r);
    RUN_TEST(test_k_update_score_d);
}
