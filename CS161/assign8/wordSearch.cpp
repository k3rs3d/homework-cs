/**
* @brief Assignment 8
* @name Kern Espinoza
*/

#include <iostream>
#include "wordSearch.h"

void printKey(const char grid[ROWS][COLS])
{
    // Iterate through all of the rows.
    for (int i = 0; i < ROWS; i++)
    {
        // Iterate through each column's intersection with this row.
        for (int j = 0; j < COLS; j++)
        {
            cout << grid[i][j];

            // Unless this is the end of the row, add a space.
            // (It might actually be fine to add a space at the end too, idk)
            if (j != (COLS - 1))
                cout << " ";
        }

        cout << endl;
    }

    return;
}

void printPuzzle(const char grid[ROWS][COLS])
{
    // Iterate through all of the rows.
    for (int i = 0; i < ROWS; i++)
    {
        // Iterate through each column's intersection with this row.
        for (int j = 0; j < COLS; j++)
        {
            // If this character is non-blank, simply output it.
            if (grid[i][j] != blankChar)
            {
                cout << grid[i][j];
            } else {
                // If this space is blank, populate it with a random character.
                int r = rand() % 26;
                cout << (char)('A' + r);
            }

            // Unless this is the end of the row, add a space.
            // (It might actually be fine to add a space at the end too, idk)
            if (j != (COLS - 1))
                cout << " ";
        }

        cout << endl;
    }

    return;
}

int countSpaces(const char grid[ROWS][COLS])
{
    int numSpaces = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == blankChar)
                numSpaces++;
        }
    }

    return numSpaces;
}

bool checkHorizontalFit(const char grid[ROWS][COLS], int startRow, int startCol, const string& word)
{
    // If the word's length runs past the edge of the grid, it won't fit
    if ((int)(startCol + word.length()) > COLS)
        return false;

    // For each letter, loop through the relevant grid spaces and check for conflicting letters
    for (int i = 0; i < (int)word.length(); i++)
    {
        // If this character is non-blank and doesn't match the letter of the given word...
        if (grid[startRow][startCol+i] != blankChar && grid[startRow][startCol+i] != word[i])
            return false;
    }

    // That should be all of the checks, so if we've made it this far, it should fit
    return true;
}

bool placeHorizontal(char grid[ROWS][COLS], int startRow, int startCol, const string& word)
{
    // First, check to see whether the word actually fits.
    if (checkHorizontalFit(grid, startRow, startCol, word) == false)
        return false;

    // At this point, the word must fit.
    // Apply the new word:
    for (int i = 0; i < (int)word.length(); i++)
    {
        // Replace the grid's character at this point with the appropriate letter from the word.
        grid[startRow][startCol + i] = word[i];
    }

    return true;
}

void placeDiagonal(char grid[ROWS][COLS], int startRow, int startCol, const string& word)
{
    // Check to see if the word fits within the puzzle bounds.
    // This function isn't really supposed to do any checking, but we might as well make sure it fits in the array, at least.
    if (((startCol + (int)word.length()) > COLS) || ((startRow + (int)word.length()) > ROWS))
        return;

    for (int i = 0; i < (int)word.length(); i++)
    {
        grid[startRow + i][startCol + i] = word[i];
    }

    return;
}

void printLargestGaps(const char grid[ROWS][COLS])
{
    int currentGapStreak = 0; // How many gaps in sequence have been encountered so far.
    int streakStartColumn = 0; // Where the current gap streak began.
    int biggestGapThisRow = 0; // Size of largest gap, resetting each row.

    // Print header/info stuff.
    cout << "Row\t\tGap Size\tStart Col" << endl;

    for (int i = 0; i < ROWS; i++)
    {
        currentGapStreak = 0; // Reset current gap count.
        biggestGapThisRow = 0; // Reset max gap size.
        streakStartColumn = 0; // Reset streak column index.

        for (int j = 0; j < COLS; j++)
        {
            // Check if the character at this position is a blank.
            if (grid[i][j] == blankChar)
            {
                // Is this the beginning of a new streak?
                if (currentGapStreak == 0)
                    streakStartColumn = j;
                // Increment the current streak count.
                currentGapStreak++;
                // After increasing, is this now the biggest streak of this row?
                if (currentGapStreak > biggestGapThisRow)
                    biggestGapThisRow = currentGapStreak;
            } else {
                currentGapStreak = 0; // Reset blank streak if we hit a non-blank char.
            }
        }

        cout << i << "\t\t" << currentGapStreak << "\t\t" << streakStartColumn << endl;
    }

    return;
}
