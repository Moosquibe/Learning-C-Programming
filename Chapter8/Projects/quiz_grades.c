#include <stdio.h>

#define NUM_QUIZZES 5
#define NUM_STUDENTS 5

#define MIN(A, B) ((A < B) ? A : B)
#define MAX(A, B) ((A < B) ? B : A)

int main(void){
  int grades[NUM_STUDENTS][NUM_QUIZZES] = {0};
  int totalScoreStudent[NUM_STUDENTS],
    highQuiz[NUM_QUIZZES], lowQuiz[NUM_QUIZZES];
  float averageScoreStudent[NUM_STUDENTS], averageScoreQuiz[NUM_QUIZZES];

  // Getting input
  for(int i = 0; i < NUM_STUDENTS; i++) {
    printf("Enter quiz grades for student %d: ", i + 1);
    for(int j=0; j < NUM_QUIZZES; j++){
      scanf(" %d", &grades[i][j]);
    }
  }

  // Computing per student statistics
  for(int i = 0; i < NUM_STUDENTS; i++) {
     totalScoreStudent[i] = 0; averageScoreStudent[i] = 0;
     for(int j=0; j < NUM_QUIZZES; j++) {
       totalScoreStudent[i] += grades[i][j];
     }
     averageScoreStudent[i] = totalScoreStudent[i] / NUM_QUIZZES;
  }

  // Computing per quiz statistics
  for(int j = 0; j < NUM_QUIZZES; j++) {
    averageScoreQuiz[j] = 0;
    lowQuiz[j] = grades[0][j];
    highQuiz[j] = grades[0][j];
    for(int i=0; i < NUM_STUDENTS; i++) {
      averageScoreQuiz[j] += grades[i][j];
      lowQuiz[j] = MIN(lowQuiz[j], grades[i][j]);
      highQuiz[j] = MAX(highQuiz[j], grades[i][j]);
    }
    averageScoreQuiz[j] /= NUM_STUDENTS; 
  }

  printf("\nStudent statistic:\n ");
  for(int i = 0; i < NUM_STUDENTS; i++)
    printf("\tStudent %d:\n\t\tTotal:   %d\n\t\tAverage: %.2f\n",
           i, totalScoreStudent[i], averageScoreStudent[i]);

  printf("\nQuiz statistics:\n");
  for(int j = 0; j < NUM_QUIZZES; j++)
    printf("\tQuiz %d:\n\t\tAverage: %.2f\n\t\tHigh: %d\n\t\tLow: %d\n",
           j, averageScoreQuiz[j], highQuiz[j], lowQuiz[j]);

  return 0;
}
