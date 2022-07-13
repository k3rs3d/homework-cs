#include <cstring> // For strlen

#include "DNAStrand.h"

using namespace std;

// ---[CONSTRUCTORS]---

// Generic constructor
DNAStrand::DNAStrand(int length)
{
    // Set length
    this->length = length;

    // Set contents of nucleotide array to blank values
    delete[] bases;
    bases = new char[length];

    for (int i = 0; i < length; i++)
    {
        bases[i] = 0;
    }
}

// Char Array constructor
DNAStrand::DNAStrand(const char* startingString)
{
    // Determine string length
    length = strlen(startingString);

    // Write base chars to new array
    delete[] bases;
    bases = new char[length];

    for (int i = 0; i < length; i++)
    {
        bases[i] = startingString[i];
    }

}

// Copy Constructor
DNAStrand::DNAStrand(const DNAStrand& other)
{
    // Copy length
    length = other.getLength();

    // Copy contents of nucleotide array
    delete [] bases;
    bases = new char[length];

    for (int i = 0; i < length; i++)
    {
        bases[i] = other.bases[i];
    }
}

// Assignment Operator
DNAStrand& DNAStrand::operator=(const DNAStrand& other)
{
    if (this != &other)
    {
        // Copy length
        length = other.getLength();

        // Copy contents of nucleotide array
        delete [] bases;
        bases = new char[length];

        for (int i = 0; i < length; i++)
        {
            bases[i] = other.bases[i];
        }
    }

    return *this;
}

// Destructor
DNAStrand::~DNAStrand() { delete[] bases; }

// ---[OPERATORS]---

bool DNAStrand::operator==(const DNAStrand& other) const
{
    // First, compare addresses
    if (this == &other)
        return true;

    // Next, compare just the lengths (also helps avoid out-of-bounds)
    if (length != other.getLength())
        return false;

    // Finally, compare each individual char
    for (int i = 0; i < length; i++)
    {
        if (bases[i] != other[i])
            return false;
    }

    // If both tests passed, we can say that they match
    return true;
}

char DNAStrand::operator[](int index) const
{
    if (index < 0 || index >= length)
        throw std::out_of_range("DNAStrand nucleotide index out of range.");

    return bases[index];
}

DNAStrand DNAStrand::operator+(const DNAStrand& other) const
{
    DNAStrand newStrand(length + other.getLength());

    int i; // Reusable iterator

    // Copy over the first half of the new strand
    for (i = 0; i < length; i++)
    {
        newStrand.bases[i] = bases[i];
    }

    // Second half of the new strand
    for (i = 0; i < other.getLength(); i++)
    {
        newStrand.bases[length+i] = other[i];
    }

    // Done
    return newStrand;
}

std::ostream& operator<<(std::ostream& dest, const DNAStrand& source)
{
    for (int i = 0; i < source.getLength(); i++)
    {
        dest << source[i];
    }

    return dest;
}

// ---[GETTERS]---

int DNAStrand::getLength() const { return length; }

DNAStrand DNAStrand::getComplement() const
{
    DNAStrand newStrand(getLength());

    for (int i = 0; i < newStrand.getLength(); i++)
    {
        switch (bases[i])
        {
        case 'A':
            newStrand.bases[i] = 'T'; break;
        case 'T':
            newStrand.bases[i] = 'A'; break;
        case 'C':
            newStrand.bases[i] = 'G'; break;
        case 'G':
            newStrand.bases[i] = 'C'; break;
        default:
            throw std::runtime_error("Invalid nucleotide in DNAStrand."); break;
        }
    }

    return newStrand;
}

DNAStrand DNAStrand::substr(int start, int length) const
{
    if (start < 0 || length < 0)
    {
        throw std::out_of_range("Invalid index for DNAStrand substring.");
        return DNAStrand(0);
    }

    if ((start+length) > getLength())
    {
        throw std::out_of_range("Invalid index for DNAStrand substring.");
        return DNAStrand(0);
    }

    DNAStrand newStrand(length);

    for (int i = 0; i < length; i++)
    {
        newStrand.bases[i] = (*this)[start+i];
    }

    return newStrand;
}

