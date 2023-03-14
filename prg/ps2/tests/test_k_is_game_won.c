#include "greatest.h"
#include "../k.h"

TEST test_if_game_is_won_failed(){
    struct game game = {
        .board = {
            {'A', 'B', 'C', 'D'},
            {'A', 'B', 'C', 'D'},
            {'A', 'B', 'C', 'D'},
            {'A', 'B', 'C', 'D'}
        },
        .score = 1234
    };

    ASSERT_EQ_FMT(0, is_game_won(game), "%d");
    PASS();
}

TEST test_if_game_is_won(){
    struct game game = {
        .board = {
            {'A', 'B', ' ', 'D'},
            {'A', 'B', ' ', 'D'},
            {'A', 'K', ' ', 'D'},
            {'A', 'B', ' ', 'D'}
        },
        .score = 1234
    };

    ASSERT_EQ_FMT(1, is_game_won(game), "%d");
    PASS();
}

SUITE(test_k_is_game_is_won) {
    RUN_TEST(test_if_game_is_won_failed);
    RUN_TEST(test_if_game_is_won);
}

