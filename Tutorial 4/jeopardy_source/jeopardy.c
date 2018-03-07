/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdbool.h>
 #include "questions.h"
 #include "players.h"
 #include "jeopardy.h"

 // Put macros or constants here using #define
 #define BUFFER_LEN 256

 // Put global environment variables here

 // Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
 void tokenize(char *input, char **tokens);

 // Displays the game results for each player, their name and final score, ranked from first to last place
 void show_results(player *players);


 int main(void)
 {

     player players[4];

     char buffer[BUFFER_LEN] = { 0 };


     printf("Welcome to the Jeopardy Game! Please Enter your Names:\n");
     for(int i=0; i<4; i++)
     {
         scanf("%s", players[i].name);
     }

     while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
     {
         char token[4][BUFFER_LEN] = {{0}};
         initialize_game();
         run_game(token, players);
         return 0;
     }


 }
 void show_results(player *players)
 {
     for(int i = 0; i <= 4; i++)
     {
         printf("Name: %s\tScore:%d\n", players[i].name, players[i].score);
     }
 }

 void tokenize(char *input, char **tokens)
 {

     char *token1 = strtok(input, " ");
     token1 = strtok(input, " ");

     for(int i = 0; token1 != NULL; i++)
     {
         strcpy(tokens[i], token1);
         token1 = strtok(NULL, " ");
     }
 }

 void run_game(char **token, player *players)
 {
     int questions_remaining = sizeof(questions);
     bool correct;
     char category;
     int value;
     char response[BUFFER_LEN] = {0};

     category = (char *) calloc(BUFFER_LEN, sizeof(char));

     while(questions_remaining > 0)
     {
         for(int i =0; i < sizeof(players); i++)
         {
             printf("%s's Turn\nChoose Category, then press enter. Then Enter the value you would like to play for\n\n", players[i].name);

             display_categories();

             printf("\n\n");
             scanf("%s", category);
             scanf("%d", value);
             printf("\n");

             if(already_answered(category, value))
             {
                 printf("Question has already been answered. Choose a different question");
                 i--;
             }
             else
             {
                 display_question(category, value);
                 scanf("%s", response);

                 tokenize(response, token);
                 correct = valid_answer(category,value,token[2]);
                 if(correct){
                     printf("Correct! You may now choose another question.\n\n");
                     players[i].score += value;
                     i--;
                 }
                 else{
                     printf("That is incorrect, or you forgot to say \"What is/Who is\".\n\n");
                 }
                 question_answered(category, value);
                 questions_remaining--;
                 if(questions_remaining<=0){
                     break;
                 }
             }
         }


         free(category);
     }

     show_results(players);

 }
