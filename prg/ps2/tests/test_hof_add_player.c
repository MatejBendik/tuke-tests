#include <stdio.h>
#include "greatest.h"
#include "../hof.h"

#define ASSERT_EQ_ARRAYS(size, arr_expected, arr_given)                     \
    do {                                                                    \
        for (int idx = 0; idx < size; idx++) {                              \
            ASSERT_EQ(arr_expected[idx], arr_given[idx]);                   \
        }                                                                   \
    } while(0)                                                              \

#define ASSERT_EQ_MATRIX(rows, columns, arr_expected, arr_given)            \
    do {                                                                    \
        for (int row = 0; row < rows; row++) {                              \
            ASSERT_EQ_ARRAYS(columns, arr_expected[row], arr_given[row]);   \
        }                                                                   \
    } while(0)                                                              \

TEST test_hof_add_player_6() {

    struct player player = {.name="Bill", .score=913};

    int size = 6;

    struct player hof[10] = {
        {.score= 1170, .name="Samuel"},
        {.score=  913, .name="John"},
        {.score=  826, .name="Manager"},
        {.score=  583, .name="Sue"},
        {.score=  406, .name="Jack"},
        {.score=  293, .name="John"}
    };

    struct player hof_e[10] = {
        {.score= 1170, .name="Samuel"},
        {.score=  913, .name="Bill"},
        {.score=  913, .name="John"},
        {.score=  826, .name="Manager"},
        {.score=  583, .name="Sue"},
        {.score=  406, .name="Jack"},
        {.score=  293, .name="John"}
    };

    printf("Original list: \n");

    for (int i = 0; i < size; i++) {
        printf("{.score= %d, .name='%s'}, \n", hof[i].score, hof[i].name);
    }

    printf("\nExpected output: \n");

    for (int i = 0; i < size; i++) {
        printf("{.score= %d, .name='%s'}, \n", hof_e[i].score, hof_e[i].name);
    }

    printf("\nYou produced: \n");
    add_player(hof,&size, player);

    for (int i = 0; i < size; i++) {
        printf("{.score= %d, .name='%s'}, \n", hof[i].score, hof[i].name);
    }

    int count = 0;

    // compare hof and hof_e
    for (int i = 0; i < size; i++) {
        if(hof[i].score == hof_e[i].score && strcmp(hof[i].name, hof_e[i].name) == 0) {
            count++;
        }else {
            FAILm("Test for HOF module add_player() function for size 6 failed!");
        }
    }

    ASSERT_EQ(count, size);

    PASSm("Test for HOF module add_player() function for size 6 passed!");
}

TEST test_hof_add_player_10() {

    struct player player = {.name="Sue", .score=91};

    int size = 10;

    struct player hof[10] = {
        {.score= 1955, .name="John"},
        {.score= 1856, .name="Sue"},
        {.score= 1749, .name="Sue"},
        {.score= 1219, .name="Jack"},
        {.score=  940, .name="Manager"},
        {.score=  794, .name="Jack"},
        {.score=  574, .name="John"},
        {.score=  307, .name="Bill"},
        {.score=   91, .name="Bill"},
        {.score=   50, .name="Jack"}
    };

    struct player hof_e[10] = {
        {.score= 1955, .name="John"},
        {.score= 1856, .name="Sue"},
        {.score= 1749, .name="Sue"},
        {.score= 1219, .name="Jack"},
        {.score=  940, .name="Manager"},
        {.score=  794, .name="Jack"},
        {.score=  574, .name="John"},
        {.score=  307, .name="Bill"},
        {.score=   91, .name="Sue"},
        {.score=   91, .name="Bill"}
    };

    printf("Original list: \n");

    for (int i = 0; i < size; i++) {
        printf("{.score= %d, .name='%s'}, \n", hof[i].score, hof[i].name);
    }

    printf("\nExpected output: \n");

    for (int i = 0; i < size; i++) {
        printf("{.score= %d, .name='%s'}, \n", hof_e[i].score, hof_e[i].name);
    }

    printf("\nYou produced: \n");
    add_player(hof,&size, player);

    for (int i = 0; i < size; i++) {
        printf("{.score= %d, .name='%s'}, \n", hof[i].score, hof[i].name);
    }

    int count = 0;

    // compare hof and hof_e
    for (int i = 0; i < size; i++) {
        if(hof[i].score == hof_e[i].score && strcmp(hof[i].name, hof_e[i].name) == 0) {
            count++;
        }else {
            FAILm("Test for HOF module add_player() function for size 10 failed!");
        }
    }

    ASSERT_EQ(count, size);

    PASSm("Test for HOF module add_player() function for size 10 passed!");
}


TEST test_hof_add_player_1() {

    struct player player = {.name="Sue", .score=681};

    int size = 1;

    struct player hof[10] = {
        {.score= 1720, .name="Manager"}
    };

    struct player hof_e[10] = {
        {.score= 1720, .name="Manager"},
        {.score=  681, .name="Sue"}
    };

    printf("Original list: \n");

    for (int i = 0; i < size; i++) {
        printf("{.score= %d, .name='%s'}, \n", hof[i].score, hof[i].name);
    }

    printf("\nExpected output: \n");

    for (int i = 0; i < size; i++) {
        printf("{.score= %d, .name='%s'}, \n", hof_e[i].score, hof_e[i].name);
    }

    printf("\nYou produced: \n");
    add_player(hof,&size, player);

    for (int i = 0; i < size; i++) {
        printf("{.score= %d, .name='%s'}, \n", hof[i].score, hof[i].name);
    }

    int count = 0;

    // compare hof and hof_e
    for (int i = 0; i < size; i++) {
        if(hof[i].score == hof_e[i].score && strcmp(hof[i].name, hof_e[i].name) == 0) {
            count++;
        }else {
            FAILm("Test for HOF module add_player() function for size 1 failed!");
        }
    }

    ASSERT_EQ(count, size);

    PASSm("Test for HOF module add_player() function for size 1 passed!");
}

TEST test_hof_add_player_8() {

    struct player player = {.name="Sue", .score=17};

    int size = 8;

    struct player hof[10] = {
        {.score= 1547, .name="Samuel"},
        {.score= 1302, .name="Bill"},
        {.score=  825, .name="Jack"},
        {.score=  770, .name="Sue"},
        {.score=  683, .name="Samuel"},
        {.score=  428, .name="Sue"},
        {.score=  408, .name="Jack"},
        {.score=  304, .name="Jack"}
    };

    struct player hof_e[10] = {
        {.score= 1547, .name="Samuel"},
        {.score= 1302, .name="Bill"},
        {.score=  825, .name="Jack"},
        {.score=  770, .name="Sue"},
        {.score=  683, .name="Samuel"},
        {.score=  428, .name="Sue"},
        {.score=  408, .name="Jack"},
        {.score=  304, .name="Jack"},
        {.score=   17, .name="Sue"}
    };

    printf("Original list: \n");

    for (int i = 0; i < size; i++) {
        printf("{.score= %d, .name='%s'}, \n", hof[i].score, hof[i].name);
    }

    printf("\nExpected output: \n");

    for (int i = 0; i < size + 1; i++) {
        printf("{.score= %d, .name='%s'}, \n", hof_e[i].score, hof_e[i].name);
    }

    printf("\nYou produced: \n");

    add_player(hof,&size, player);

    for (int i = 0; i < size; i++) {
        printf("{.score= %d, .name='%s'}, \n", hof[i].score, hof[i].name);
    }

    int count = 0;

    // compare hof and hof_e
    for (int i = 0; i < size; i++) {
        if(hof[i].score == hof_e[i].score && strcmp(hof[i].name, hof_e[i].name) == 0) {
            count++;
        }else {
            FAILm("Test for HOF module add_player() function for size 8 failed!");
        }
    }

    ASSERT_EQ(count, size);

    PASSm("Test for HOF module add_player() function for size 8 passed!");
}

TEST test_hof_add_player_size_1() {

    struct player player = {.name="Sue", .score=681};

    int size = 1;

    struct player hof[10] = {
        {.score= 1720, .name="Manager"}
    };

    int size_e = size + 1;

    printf("\nOriginal list size: %d\n", size);

    printf("Expected: \n");
    printf("add_player(hof, &size, player) == %d", size_e);

    add_player(hof,&size, player);

    printf("\nYou produced: \n");
    printf("add_player(hof, &size, player) == %d\n", size);

    ASSERT_EQ(size_e, size);
    PASSm("Test for HOF module add_player() function for size 8 passed!");
}

TEST test_hof_add_player_size_2() {

    struct player player = {.name="Manager", .score=652};

    int size = 2;

    struct player hof[10] = {
        {.score= 1308, .name="Jack"},
        {.score=  294, .name="Jack"}
    };

    int size_e = size + 1;

    printf("\nOriginal list size: %d\n", size);

    printf("Expected: \n");
    printf("add_player(hof, &size, player) == %d", size_e);

    add_player(hof,&size, player);

    printf("\nYou produced: \n");
    printf("add_player(hof, &size, player) == %d\n", size);

    ASSERT_EQ(size_e, size);
    PASSm("Test for HOF module add_player() function for size 8 passed!");
}

TEST test_hof_add_player_size_3() {

    struct player player = {.name="Bill", .score=1299};

    int size = 3;

    struct player hof[10] = {
        {.score= 1327, .name="Manager"},
        {.score= 1299, .name="Manager"},
        {.score=  633, .name="Jack"}
    };

    int size_e = size + 1;

    printf("\nOriginal list size: %d\n", size);

    printf("Expected: \n");
    printf("add_player(hof, &size, player) == %d", size_e);

    add_player(hof,&size, player);

    printf("\nYou produced: \n");
    printf("add_player(hof, &size, player) == %d\n", size);

    ASSERT_EQ(size_e, size);
    PASSm("Test for HOF module add_player() function for size 8 passed!");
}

TEST test_hof_add_player_size_4() {

    struct player player = {.name="Jack", .score=1451};

    int size = 4;

    struct player hof[10] = {
        {.score= 1593, .name="John"},
        {.score=  812, .name="Sue"},
        {.score=  450, .name="Bill"},
        {.score=  348, .name="Manager"}
    };

    int size_e = size + 1;

    printf("\nOriginal list size: %d\n", size);

    printf("Expected: \n");
    printf("add_player(hof, &size, player) == %d", size_e);

    add_player(hof,&size, player);

    printf("\nYou produced: \n");
    printf("add_player(hof, &size, player) == %d\n", size);

    ASSERT_EQ(size_e, size);
    PASSm("Test for HOF module add_player() function for size 8 passed!");
}

TEST test_hof_add_player_size_5() {

    struct player player = {.name="Samuel", .score=1312};

    int size = 5;

    struct player hof[10] = {
        {.score= 1659, .name="Bill"},
        {.score= 1600, .name="Sue"},
        {.score=  756, .name="Sue"},
        {.score=  717, .name="John"},
        {.score=   24, .name="Manager"}
    };

    int size_e = size + 1;

    printf("\nOriginal list size: %d\n", size);

    printf("Expected: \n");
    printf("add_player(hof, &size, player) == %d", size_e);

    add_player(hof,&size, player);

    printf("\nYou produced: \n");
    printf("add_player(hof, &size, player) == %d\n", size);

    ASSERT_EQ(size_e, size);
    PASSm("Test for HOF module add_player() function for size 8 passed!");
}

TEST test_hof_add_player_size_6() {

    struct player player = {.name="Jack", .score=306};

    int size = 6;
    struct player hof[10] = {
        {.score= 1509, .name="Sue"},
        {.score=  802, .name="Manager"},
        {.score=  553, .name="Samuel"},
        {.score=  306, .name="Sue"},
        {.score=  203, .name="Manager"},
        {.score=   19, .name="Manager"}
    };

    int size_e = size + 1;

    printf("\nOriginal list size: %d\n", size);

    printf("Expected: \n");
    printf("add_player(hof, &size, player) == %d", size_e);

    add_player(hof,&size, player);

    printf("\nYou produced: \n");
    printf("add_player(hof, &size, player) == %d\n", size);

    ASSERT_EQ(size_e, size);
    PASSm("Test for HOF module add_player() function for size 8 passed!");
}

TEST test_hof_add_player_size_7() {

    struct player player = {.name="Jack", .score=1224};

    int size = 7;

    struct player hof[10] = {
        {.score= 1970, .name="John"},
        {.score= 1557, .name="Sue"},
        {.score=  899, .name="Bill"},
        {.score=  778, .name="Jack"},
        {.score=  736, .name="Jack"},
        {.score=  610, .name="Jack"},
        {.score=   76, .name="Samuel"}
    };

    int size_e = size + 1;

    printf("\nOriginal list size: %d\n", size);

    printf("Expected: \n");
    printf("add_player(hof, &size, player) == %d", size_e);

    add_player(hof,&size, player);

    printf("\nYou produced: \n");
    printf("add_player(hof, &size, player) == %d\n", size);

    ASSERT_EQ(size_e, size);
    PASSm("Test for HOF module add_player() function for size 8 passed!");
}

TEST test_hof_add_player_size_8() {

    struct player player = {.name="Sue", .score=17};

    int size = 8;

    struct player hof[10] = {
        {.score= 1547, .name="Samuel"},
        {.score= 1302, .name="Bill"},
        {.score=  825, .name="Jack"},
        {.score=  770, .name="Sue"},
        {.score=  683, .name="Samuel"},
        {.score=  428, .name="Sue"},
        {.score=  408, .name="Jack"},
        {.score=  304, .name="Jack"}
    };

    int size_e = size + 1;

    printf("\nOriginal list size: %d\n", size);

    printf("Expected: \n");
    printf("add_player(hof, &size, player) == %d", size_e);

    add_player(hof,&size, player);

    printf("\nYou produced: \n");
    printf("add_player(hof, &size, player) == %d\n", size);

    ASSERT_EQ(size_e, size);
    PASSm("Test for HOF module add_player() function for size 8 passed!");
}

TEST test_hof_add_player_size_9() {

    struct player player = {.name="Sue", .score=1899};

    int size = 9;

    struct player hof[10] = {
        {.score= 1899, .name="Sue"},
        {.score= 1891, .name="Samuel"},
        {.score= 1828, .name="Manager"},
        {.score= 1622, .name="Jack"},
        {.score=  910, .name="Bill"},
        {.score=  569, .name="Bill"},
        {.score=  488, .name="Samuel"},
        {.score=  432, .name="Jack"},
        {.score=  391, .name="Bill"}
    };

    int size_e = size + 1;

    printf("\nOriginal list size: %d\n", size);

    printf("Expected: \n");
    printf("add_player(hof, &size, player) == %d", size_e);

    add_player(hof,&size, player);

    printf("\nYou produced: \n");
    printf("add_player(hof, &size, player) == %d\n", size);

    ASSERT_EQ(size_e, size);
    PASSm("Test for HOF module add_player() function for size 8 passed!");
}


SUITE(test_hof_add_player) {
    
    // hof test 
    RUN_TEST(test_hof_add_player_6);
    RUN_TEST(test_hof_add_player_10);
    RUN_TEST(test_hof_add_player_1);
    RUN_TEST(test_hof_add_player_8);

    // size test
    RUN_TEST(test_hof_add_player_size_1);
    RUN_TEST(test_hof_add_player_size_2);
    RUN_TEST(test_hof_add_player_size_3);
    RUN_TEST(test_hof_add_player_size_4);
    RUN_TEST(test_hof_add_player_size_5);
    RUN_TEST(test_hof_add_player_size_6);
    RUN_TEST(test_hof_add_player_size_7);
    RUN_TEST(test_hof_add_player_size_8);
    RUN_TEST(test_hof_add_player_size_9);
}
