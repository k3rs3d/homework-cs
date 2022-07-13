/**
* @brief Assignment 3
* @name Kern Espinoza
*/

#ifndef PAGE_H
#define PAGE_H

#include <iostream> // mostly for strings
#include <cstdlib> // mostly for RNG in getRandomLink()

using namespace std;

class Page
{
private:
    string url;
    int visits;
    Page* links[3];
    int usedLinks;
public:
// [CONSTRUCTORS]
    Page();
    Page(string urlValue);
// [GETTERS]
    string getURL();
    int getNumLinks();
    int getNumVisits();
// [FUNCTIONS]
    void visit();
    void addLink(Page* other);
    Page* getRandomLink();

};

#endif // PAGE_H
