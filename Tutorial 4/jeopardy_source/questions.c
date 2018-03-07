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
 #include "questions.h"

question questions[12];

 // Initializes the array of questions for the game
 void initialize_game(void)
 {


 	strcpy(questions[0].category, "BasketBall");
 	strcpy(questions[0].question, "Best Handles in the NBA");
 	strcpy(questions[0].answer, "Kyrie Irving");
 	questions[0].value = 200;
 	questions[0].answered = false;

 	strcpy(questions[1].category, "BasketBall");
 	strcpy(questions[1].question, "Best Shooter in the NBA");
 	strcpy(questions[1].answer, "Stephen Curry");
 	questions[1].value = 400;
 	questions[1].answered = false;

 	strcpy(questions[2].category, "BasketBall");
 	strcpy(questions[2].question, "Best PLayer in NBA");
 	strcpy(questions[2].answer, "Lebron James");
 	questions[2].value = 600;
 	questions[2].answered = false;

 	strcpy(questions[3].category, "BasketBall");
 	strcpy(questions[3].question, "Second Best Player in the NBA");
 	strcpy(questions[3].answer, "Kevin Durant");
 	questions[3].value = 800;
 	questions[3].answered = false;




 	strcpy(questions[4].category, "Soccer");
 	strcpy(questions[4].question, "Best Overall Athelete in the game");
 	strcpy(questions[4].answer, "Cristiano Ronaldo");
 	questions[4].value = 200;
 	questions[4].answered = false;

 	strcpy(questions[5].category, "Soccer");
 	strcpy(questions[5].question, "Best Playmaker in the game");
 	strcpy(questions[5].answer, "Lionel Messi");
 	questions[5].value = 400;
 	questions[5].answered = false;

 	strcpy(questions[6].category, "Soccer");
 	strcpy(questions[6].question, "Best Team");
 	strcpy(questions[6].answer, "Real Madrid");
 	questions[6].value = 600;
 	questions[6].answered = false;

 	strcpy(questions[7].category, "Soccer");
 	strcpy(questions[7].question, "Most Skillful");
 	strcpy(questions[7].answer, "Neymar");
 	questions[7].value = 800;
 	questions[7].answered = false;




 	strcpy(questions[8].category, "Random");
 	strcpy(questions[8].question, "What year did world war 1 end");
 	strcpy(questions[8].answer, "1918");
 	questions[8].value = 200;
 	questions[8].answered = false;

 	strcpy(questions[9].category, "Random");
 	strcpy(questions[9].question, "What year did World war 2 end");
 	strcpy(questions[9].answer, "1945");
 	questions[9].value = 400;
 	questions[9].answered = false;

 	strcpy(questions[10].category, "Random");
 	strcpy(questions[10].question, "Who won 2018 superbowl");
 	strcpy(questions[10].answer, "Eagles");
 	questions[10].value = 600;
 	questions[10].answered = false;

 	strcpy(questions[11].category, "Random");
 	strcpy(questions[11].question, "Best fried chicken");
 	strcpy(questions[11].answer, "KFC");
 	questions[11].value = 800;
 	questions[11].answered = false;

 }

 // Displays each of the remaining categories and question dollar values that have not been answered
 void display_categories(void)
 {

 	char v[12][20];
 	for (int i = 0; i < 12; i++)
  {
 		if (questions[i].answered == false)
    {
 			snprintf(v[i], 20, "%d", questions[i].value);
 		}
    else
    {
 			strcpy(v[i], "   ");
 		}

 	}


 	printf("   %s   |   %s   |   %s   \n", categories[0], categories[1], categories[2]);
 	printf("  -------------------------------------------------\n");

 	printf("      %s      |     %s     |         %s   \n", v[0], v[1], v[2]);
 	printf("  -------------------------------------------------\n");

 	printf("      %s      |     %s     |         %s   \n", v[3], v[4], v[5]);
 	printf("  -------------------------------------------------\n");

 	printf("      %s      |     %s     |         %s   \n", v[6], v[7], v[8]);
 	printf("  -------------------------------------------------\n");

 	printf("      %s      |     %s     |         %s   \n", v[9], v[10], v[11]);
 	printf("  -------------------------------------------------\n");


 }

 // Displays the question for the category and dollar value
 void display_question(char *category, int value)
 {
 	for (int i = 0; i < 12; i++) {
 		if ((questions[i].category == category) && (questions[i].value == value)) {
 			printf("Question: %s (%d)\n", questions[i].question, questions[i].value);
 		}
 	}
 }


 bool valid_answer(char *category, int value, char *answer)
 {
 	bool is_valid;

 	for (int i = 0; i < 12; i++)
  {
 		if ((questions[i].category == category) && (questions[i].value == value))
    {
 			if (strcmp(questions[i].answer, answer) == 0)
      {

 				is_valid = true;

 			}
      else
      {

 				is_valid = false;
 			}
 		}
 	}

 	return is_valid;
 }

 /
 bool already_answered(char *category, int value)
 {
 	bool answered;
 	for (int i = 0; i < 12; i++)
  {
 		if ((questions[i].category == category) && (questions[i].value == value))
    {
 			if (questions[i].answered == true)
      {
 				answered = true;
 			}
      else
      {
 				answered = false;
 			}
 		}
 	}
 	return answered;
 }

 void question_answered(char *category, int value)
 {
 	for (int i = 0; i < 12; i++)
  {
 		if ((questions[i].category == category) && (questions[i].value == value))
    {
 			questions[i].answered = true;
 		}
 	}
 }
