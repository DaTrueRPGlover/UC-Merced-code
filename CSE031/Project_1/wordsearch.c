#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
int bSize;

void upperCase(char* word);
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
int around(int** puzleInt, char** arr, char* word, int i, int j, int index);
int wordInPuzzle(char** arr, int** puzzleInt, char* word);

// Main function, DO NOT MODIFY
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
    return 2;
  }
  int i, j;
  FILE *fptr;

  // Open file for reading puzzle
  fptr = fopen(argv[1], "r");
  if (fptr == NULL) {
    printf("Cannot Open Puzzle File!\n");
    return 0;
  }

  // Read the size of the puzzle block
  fscanf(fptr, "%d\n", &bSize);

  // Allocate space for the puzzle block and the word to be searched
  char **block = (char **)malloc(bSize * sizeof(char *));
  char *word = (char *)malloc(20 * sizeof(char));

  // Read puzzle block into 2D arrays
  for (i = 0; i < bSize; i++) {
    *(block + i) = (char *)malloc(bSize * sizeof(char));
    for (j = 0; j < bSize - 1; ++j) {
      fscanf(fptr, "%c ", *(block + i) + j);
    }
    fscanf(fptr, "%c \n", *(block + i) + j);
  }
  fclose(fptr);

  printf("Enter the word to search: ");
  scanf("%s", word);

  // Print out original puzzle grid
  printf("\nPrinting puzzle before search:\n");
  printPuzzle(block);

  // Call searchPuzzle to the word in the puzzle
  searchPuzzle(block, word);

  return 0;
}

void printPuzzle(char **arr) {
  int i = 0;
  int j = 0;

  for (i = 0; i < bSize; i++) {
    if (i != 0) {
      printf("\n");
    }
    for (j = 0; j < bSize; j++) {
      printf("%c ", *(*(arr + i) + j));
    }
  }
  printf("\n");
}

void searchPuzzle(char **arr, char *word) {
  int i = 0;
  int j = 0;

  int** puzzleInt = (int**)malloc(bSize * sizeof(int*)); // creates our array of integers we need to print the puzzle path
  for (i = 0; i < bSize; i++) {
      *(puzzleInt + i) = (int*)malloc(bSize * sizeof(int));
  }

  upperCase(word);

  for (i = 0; i < bSize; i++) {
      for (j = 0; j < bSize; j++) {
          *(*(puzzleInt + i) + j) = 0; // sets the values of our integer puzzle to be all 0
      }
  }

  if (wordInPuzzle(arr, puzzleInt, word) == 1) {
      printf("\n\nWord found!\n");
      printf("Printing the search visited path: \n");

      for (i = 0; i < bSize; i++) {
          for (j = 0; j < bSize; j++) {
              printf("%d\t", *(*(puzzleInt + i) + j));
          }
          printf("\n");
      }
  }

  else {
      printf("\n\nWord not found!\n");
  }
  // int k = 0;
  // int count = 1;
  // char map = '1';
  free(puzzleInt);
}

void upperCase(char *word) {
  int i;
  for (i = 0; *(word + i) != '\0'; i++) {
    if (*(word + i) >= 'a' && *(word + i) <= 'z') {
      *(word + i) = *(word + i) - 32;
    }
  }
  /*int i;
  int count = 0;

  while (word + 1 != NULL) {
      count++;
      word++;
  }

  word = word - count;

  for (i = 0; i < count; i++) {
      if (*word >= 97) {
          *(word + i) -= 32;
      }
      printf("%c ", *(word));
  }*/
}

/*char* cycle(char* letter, char** arr, int i, int j) {
    char* nextLetter;

    if (letter + 1 == NULL) {
        return letter;
    }

    if (*(*(arr + i - 1) + j - 1) == (*(letter + 1)) {
        return ((arr + i - 1) + j);
    }

    for (i; i < bSize; i++) {
        for (j ; j < bSize; j++) {
            if (*(*(arr + i + 1) + j) != NULL && *(*(arr + i) + j + 1) != NULL
&& *(*(arr + i - 1) + j) != NULL && *(*(arr + i) + j - 1) != NULL) { if
(*(letter + 1) != NULL) {

                    if (*(*(arr + i - 1) + j - 1) == (*(letter + 1)) || *(*(arr
+ i) + j - 1) == (*(letter + 1)) || *(*(arr + i + 1) + j - 1) == (*(letter + 1))
|| *(*(arr + i + 1) + j) == (*(letter + 1)) || *(*(arr + i + 1) + j + 1) ==
(*(letter + 1)) || *(*(arr + i) + j + 1) == (*(letter + 1)) || *(*(arr + i - 1)
+ j + 1) == (*(letter + 1)) || *(*(arr + i - 1) + j) == (*(letter + 1))) {
                        return
                    }
                }
            }
        }
    }
}*/

/*void puzzleInt(char** arr, char* word) {
  int **intarr = (int **)malloc(bSize * sizeof(int *));
  int i, j, h;
  int wordlen = 0;               // size of word
  for (int i = 0; *(word + i) != '\0'; i++) { // h goes til 20 cuz of line 35
    wordlen++;
  }

  for (i = 0; i < bSize; i++) {
    *(intarr + i) = (int *)malloc(bSize * sizeof(int));
  }
  for (i = 0; i < bSize; i++) {
    for (j = 0; j < bSize; j++) {
      *(*(intarr + i) + j) = 0; // make a 2d array bsize*bsize filled with zeros
    }
  }
  for (h = 0; h < wordlen; h++) { // iterate thru the word
    for (i = 0; i < bSize; i++) {
      for (j = 0; j < bSize; j++) {             // iterate thru the 2d array
        if (*(word + h) == *(*(arr + i) + j)) { // if a letter matches
          if (*(*(intarr + i) + j) == 0) {
            *(*(intarr + i) + j) =
                h + 1; // mark it down as the letter position in the intarr
          } else {
            *(*(intarr + i) + j) = concatenate(*(*(intarr + i) + j), h + 1);
          } // concat if it isnt a zero
        }
      }
    }
  }

  for (i = 0; i < bSize; i++) {
    if (i != 0) {
      printf("\n");
    }
    for (j = 0; j < bSize; j++) {
      printf("%d       ", *(*(intarr + i) + j));
    }
  }

  // return intarr;
}*/

/*unsigned concatenate(unsigned x, unsigned y) {
  unsigned pow = 10;
  while (y >= pow) {
    pow *= 10;
  }
  return x * pow + y;
}*/

int wordInPuzzle(char** arr, int** puzzleInt, char* word) { // checks is we can actually find the word in the puzzle using out function that goes around
    int i = 0;
    int j = 0;

    for (i = 0; i < bSize; i++) {
        for (j = 0; j < bSize; j++) {
            if (around(puzzleInt, arr, word, i, j, 0) == 1) {
                return 1;
            }
        }
    }
    return 0;
}

int around(int** puzzleInt, char** arr, char* word, int i, int j, int index) { // function to go around the letters in the column and row we are in right now (this is a boolean function, the numbers represent whether we found the path to the letter or not)

    int found = 0;
    int length = strlen(word);


    if (index == length) {
        found = 1;
        return 1;
    }

    if (*(word + index) != *(*(arr + i) + j)) {
        found = 0;
        return 0;
    }

    *(*(puzzleInt + i) + j) *= 10; // this is a way to concatenate the numbers when a letter is found multiple times in the same spot in the puzzle (banana puzzle)
    *(*(puzzleInt + i) + j) += index + 1; // this adds the numbers needed to show the pathing

    if ((i + 1 < bSize && around(puzzleInt, arr, word, i + 1, j, index + 1)) || (i - 1 >= 0 && around(puzzleInt, arr, word, i - 1, j, index + 1)) || (j + 1 < bSize && around(puzzleInt, arr, word, i, j + 1, index + 1)) || (j - 1 >= 0 && around(puzzleInt, arr, word, i, j - 1, index + 1)) || (i - 1 >= 0 && j + 1 < bSize && around(puzzleInt, arr, word, i - 1, j + 1, index + 1)) || (i - 1 >= 0 && j - 1 >= 0 && around(puzzleInt, arr, word, i - 1, j - 1, index + 1)) || (i + 1 < bSize && j - 1 >= 0 && around(puzzleInt, arr, word, i + 1, j - 1, index + 1)) || (i + 1 < bSize && j + 1 < bSize && around(puzzleInt, arr, word, i + 1, j + 1, index + 1)) || (i - 1 >= 0 && j - 1 >= 0 && around(puzzleInt, arr, word, i - 1, j - 1, index + 1))) { // checks every possibility of a letter of each word to be around the word that we are at at the moment (with restrictions so that we don't move somewhere we did not intend to)
        found = 1;
        return 1;
    }

    *(*(puzzleInt + i) + j) = 0;


    return 0;

}