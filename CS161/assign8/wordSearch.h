/**
* @brief Assignment 8
* @name Kern Espinoza
*/

#ifndef WORDSEARCH_H
#define WORDSEARCH_H

#include <string>

using namespace std;

// I'm pretty sure that these array dimensions need to be compile-time constants
const int ROWS = 12;
const int COLS = 10;

const char blankChar = '_';

const int maxWordPlacementAttempts = 128; // When trying to place a new word, give up after this many failed tries.

/**
 * @brief Outputs the entire puzzle grid with ONLY the answers. Filler characters will be shown as blank spaces.
 * @param grid The contents of the puzzle grid, as a 2d char array.
 */
void printKey(const char grid[ROWS][COLS]);

/**
 * @brief Outputs the actual puzzle grid, with blank spaces filled with random characters.
 * @param grid The contents of the puzzle grid, as a 2d char array.
 */
void printPuzzle(const char grid[ROWS][COLS]);

/**
 * @brief Returns the number of blank spaces in the given puzzle.
 * @param grid The contents of the puzzle grid, as a 2d char array.
 * @return
 */
int countSpaces(const char grid[ROWS][COLS]);

/**
 * @brief Returns true/false depending on whether the given word can fit (horizontally) within the given row&column.
 * @param grid The contents of the puzzle grid.
 * @param startRow Which row to search on.
 * @param startCol Which column to begin at.
 * @param word The word to check.
 * @return
 */
bool checkHorizontalFit(const char grid[ROWS][COLS],
                        int startRow,
                        int startCol,
                        const string& word);

/**
 * @brief Checks if there is a valid spot to place the given word (horizontally) at the given row&column. If so, applies that change to the grid. Returns true if the word fits; otherwise, false.
 * @param grid The contents of the puzzle grid.
 * @param startRow Which row to search on.
 * @param startCol Which column to begin at.
 * @param word The word to attempt to add.
 * @return
 */
bool placeHorizontal(char grid[ROWS][COLS],
                     int startRow, int startCol, const string& word);

/**
 * @brief Places the given word diagonally (down-right) beginning at the indicated row&column. Does NOT bother checking whether the word fits.
 * @param grid The contents of the puzzle grid.
 * @param startRow Which row to begin at.
 * @param startCol Which column to begin at.
 * @param word The word to add.
 */
void placeDiagonal(char grid[ROWS][COLS],
                   int startRow, int startCol, const string& word);

/**
 * @brief Outputs the size and location of the largest horizontal opening in each row.
 * @param grid The contents of the puzzle grid, as a 2d char array.
 */
void printLargestGaps(const char grid[ROWS][COLS]);

/**
 * @brief (Mostly for testing.) Takes in a blank grid and a word list, and attempts to populate the grid with the given words. May give up on some words if it can't find a spot for them quickly enough.
 * @param grid The puzzle grid object.
 * @param wordList The list of words to fill the puzzle with.
 */
void populateNewPuzzleGrid(char grid[ROWS][COLS], string wordList[]);

#endif // WORDSEARCH_H
