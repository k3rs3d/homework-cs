/**
* @brief Assignment 3
* @name Kern Espinoza
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Page.h"

using namespace std;

int main()
{
    // Constants
    const int numIterations = 1000000; // Total pages to visit
    const int randMod = 101; // Maximum random value + 1
    const int randThreshold = 15; // Random values less than or equal to this threshold value will cause the 'surfer' to jump to a random page (instead of a linked page)

    // Page constructors:
    Page pages[4];
    pages[0] = Page("http://page1");
    pages[1] = Page("http://page2");
    pages[2] = Page("http://page3");
    pages[3] = Page("http://page4");

    // Link pages together according to the assignment:
    pages[0].addLink(&pages[1]);
    pages[0].addLink(&pages[2]);
    pages[1].addLink(&pages[2]);
    pages[2].addLink(&pages[0]);
    pages[3].addLink(&pages[0]);
    pages[3].addLink(&pages[2]);

    // Pointer to the active page
    Page* currentPage = &pages[0];

    // Seed RNG
    srand(time(nullptr)); // QT makes a fuss about this, but it seems to work just fine

    // Outside of the loop, make declare a spot to store random values
    int randValue;

    // Announce the beginning of the big loop:
    cout << "Running the PageRank algorithm..." << endl;

    // Each iteration: grab a page, then 'visit' it
    for (int i = 0; i < numIterations; i++)
    {
        randValue = (rand() % randMod);

        // If the value is <= 15, then we need to pick a totally random page
        if (randValue <= randThreshold)
        {
            // Get a random page from the main page array
            randValue = (rand() % 4);
            currentPage = &pages[randValue];
        }
        else // If the value is instead greater than 15:
        {
            // ask the current page for one of its links
            currentPage = currentPage->getRandomLink();
        }

        // We have a new page; perform a visit
        currentPage->visit();
    }

    // Loop has completed; report its results
    double visitPercent; // visits / iterations, as a percentage
    for (int i = 0; i < 4; i++)
    {
        visitPercent = ((pages[i].getNumVisits() * 100) / numIterations);
        cout << "Page " << (i+1) << " received " << visitPercent << "% of " << numIterations << " visits." << endl;
    }

    // Done
    return 0;
}
