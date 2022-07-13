/**
* @brief Assignment 3
* @name Kern Espinoza
*/

#include "Page.h"

// [CONSTRUCTOR IMPLEMENTATION]

Page::Page()
    : url(""), visits(0), usedLinks(0)
{
    links[0] = nullptr;
    links[1] = nullptr;
    links[2] = nullptr;
}

Page::Page(string urlValue)
    : visits(0), usedLinks(0)
{
    url = urlValue;

    links[0] = nullptr;
    links[1] = nullptr;
    links[2] = nullptr;
}

// [GETTER IMPLEMENTATION]

string Page::getURL()
{
    return url;
}

int Page::getNumLinks()
{
    return usedLinks;
}

int Page::getNumVisits()
{
    return visits;
}

// [FUNCTION IMPLEMENTATION]

void Page::visit()
{
    visits++;
}

void Page::addLink(Page *other)
{
    // Skip adding if the page can't hold any more links
    if (usedLinks >= 3)
        return;

    // Add the link & increment link count
    links[usedLinks] = other;
    usedLinks++;
}

Page* Page::getRandomLink()
{
    // If a page has no links, return nullptr
    if (usedLinks == 0)
        return nullptr;

    // Otherwise, get a random value from 0 to (usedLinks-1)
    // and use that as an index
    int randIndex = (rand() % usedLinks);
    return links[randIndex];
}
