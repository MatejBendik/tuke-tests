#include "greatest.h"

extern SUITE(test_k_is_game_is_won);
extern SUITE(test_k_is_move_possible);

GREATEST_MAIN_DEFS();

int main(int argc, char **argv) {
    GREATEST_MAIN_BEGIN();

    RUN_SUITE(test_k_is_game_is_won);
    RUN_SUITE(test_k_is_move_possible);

    GREATEST_MAIN_END();
}
