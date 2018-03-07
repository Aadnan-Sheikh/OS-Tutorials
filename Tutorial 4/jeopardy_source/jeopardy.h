/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
 #ifndef JEOPARDY_H_
#define JEOPARDY_H_

#define MAX_LEN 256

extern void tokenize(char *input, char **tokens);

extern void show_results(player *players);

extern void run_game(char **token, player *players);
#endif
