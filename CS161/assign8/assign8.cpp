/**
* @brief Assignment 8
* @name Kern Espinoza
*/

#include <iostream>
#include <ctime>
#include "wordSearch.h"

using namespace std;

void TestStaticPuzzle()
{
    // STATIC PUZZLE:
    char puzzle[ROWS][COLS] = {
            {'H','_','_','_','_','_','_','_','_','_'},
            {'E','_','_','_','_','_','_','_','_','_'},
            {'A','_','D','_','_','_','I','N','T','_'},
            {'P','R','O','G','R','A','M','_','_','_'},
            {'_','_','U','_','_','_','_','_','_','_'},
            {'_','_','B','_','_','_','M','_','_','_'},
            {'_','_','L','_','_','_','A','_','_','_'},
            {'_','_','E','_','V','O','I','D','_','_'},
            {'_','_','_','_','_','_','N','_','_','_'},
            {'S','T','A','C','K','_','_','_','_','_'},
            {'_','_','_','_','_','_','_','_','_','_'},
            {'_','_','_','_','_','_','_','_','_','_'}
    };

    // Test puzzle output:
    cout << "Original Puzzle: " << endl;
    printPuzzle(puzzle);
    cout << endl << "Original Key: " << endl;
    printKey(puzzle);

    // Test measuring functions:
    printLargestGaps(puzzle);

}

void TestRandomPuzzle()
{
    // Get ready to make the puzzle grid
    char puzzle[ROWS][COLS];
    // Ideally, these words would actually come from a file or from keyboard input:
    string wordList[] = { "HEAP", "PROGRAM", "DOUBLE", "INT", "MAIN", "VOID", "STACK", "BOOL", "NULL", "IDE", "MYSQL", "" };

    // First, populate grid with blanks
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            puzzle[i][j] = blankChar;

    // Then add a few words diagonally (since diagonal placement doesn't really check for validity)
    int numDiagonalWords = 3; // How many words to attempt to place diagonally?
    for (int i =0; (i < numDiagonalWords) && (i < (int)wordList->length()); i++)
        placeDiagonal(puzzle, (rand() % ROWS), (rand() % COLS), wordList[i]);

    // Try randomly adding each remaining word:
    for (int i = numDiagonalWords; i < (int)(sizeof(wordList) / sizeof(wordList[0])); i++)
    {
        for (int j = 0; j < maxWordPlacementAttempts; j++)
        {
            if (placeHorizontal(puzzle, (rand() % ROWS), (rand() % COLS), wordList[i]))
                break; // Stop this inner loop as soon as a word is successfully placed
        }
    }

    // Test output modified grid:
    cout << "Generated Puzzle: " << endl;
    printPuzzle(puzzle);
    cout << endl << "Generated Key: " << endl;
    printKey(puzzle);
    cout << endl;

    printLargestGaps(puzzle);
}

int main()
{
    // Seed PRNG:
    srand( time(NULL) );

    // Functions for testing:
    TestStaticPuzzle(); // Test basic output
    TestRandomPuzzle(); // Test generating an entirely new puzzle
}
