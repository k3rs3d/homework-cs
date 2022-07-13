/**
* @brief Assignment 6
* @name Kern Espinoza
*/

#ifndef SET_H
#define SET_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
class Set
{
private:
    int size;
    int capacity;
    T* elements;
public:
    Set();
    Set(const Set& other);
    ~Set();
    bool contains(T item) const;
    int getSize() const;
    void clear();
    void add(T item);
    void remove(T item);
    T removeSmallest();
    bool operator==(const Set& other) const;
    Set<T>& operator=(const Set<T>& other);
    Set intersectionWith(const Set& other) const;
    string toString() const;
};

// No-arg constructor
template <typename T>
Set<T>::Set() {
    size = 0;
    capacity = 8;
    elements = new T[capacity];

    // Initialize empty (???)
    //for (int i = 0; i < capacity; i++)
    //    elements[i] = NULL;
}

// Copy Constructor
template <typename T>
Set<T>::Set(const Set& other)
{
    // Copy variables
    size = other.getSize();
    capacity = other.capacity;

    // Copy contents of array
    delete [] elements;
    elements = new T[size];

    for (int i = 0; i < size; i++)
    {
        elements[i] = other.elements[i];
    }
}

// Assignment Operator
template <typename T>
Set<T>& Set<T>::Set::operator=(const Set<T>& other)
{
    if (this != &other)
    {
        // Copy variables
        size = other.getSize();
        capacity = other.capacity;

        // Copy contents of array
        delete [] elements;
        elements = new T[size];

        for (int i = 0; i < size; i++)
        {
            elements[i] = other.elements[i];
        }
    }

    return *this;
}

// Destructor
template <typename T>
Set<T>::~Set() {
    delete[] elements;
}

// Equality Operator
template <typename T>
bool Set<T>::operator==(const Set<T>& other) const
{
    // Compare addresses first
    if (this == &other)
        return true;

    // Then simply compare sizes
    if (size != other.getSize())
        return false;

    // Finally, ensure each element is present in both sets
    for (int i = 0; i < size; i++)
    {
        if (!other.contains(elements[i]))
            return false;
    }

    // At this point, they must match
    return true;
}

// Getters
template<typename T>
int Set<T>::getSize() const
{
    return size;
}

// Collection Functions
template<typename T>
bool Set<T>::contains(T item) const
{
    for (int i = 0; i < size; i++)
    {
        if (item == elements[i])
            return true;
    }

    return false;
}

template<typename T>
void Set<T>::add(T item)
{
    // Skip adding if the item already exists within the collection
    if (this->contains(item))
        return;

    // How the new item gets added depends on whether the collection is currently full
    // If it's full, we need to resize the array
    if (size >= capacity)
    {
        // Resize array
        T* newElements = new T[capacity+1];

        // Copy old elements
        for (int i = 0; i < capacity; i++)
        {
            newElements[i] = elements[i];
        }

        // Add new element
        delete[] elements;
        elements = newElements;
        capacity++;
        elements[size] = item;

        delete[] newElements;
    }
        else // If it's not full, set the next element to the item
    {
        elements[size] = item;
    }

    // Either way, the number of items now increases
    size++;
}

template<typename T>
void Set<T>::remove(T item)
{
    // First, ensure the item actually exists within the collection
    if (!this->contains(item))
        return;

    // Replace the item to be removed with the last item in the set
    // (to avoid gaps)
    for (int i = 0; i < capacity; i++)
    {
        if (item == elements[i])
        {
            elements[i] = elements[size-1];
            size--;
            capacity--;
        }
    }
}

template<typename T>
void Set<T>::clear()
{
    size = 0;
    capacity = 1; // ???
    delete[] elements;
    elements = new T[capacity];
}

template<typename T>
T Set<T>::removeSmallest()
{
    // Check empty set
    if (size <= 0 || capacity <= 0)
        throw invalid_argument("Cannot remove elements from an empty set.");

    // The assignment instructions seemed to indicate that this should return the removed object
    // So I'll keep a copy of the object and just remember the index:
    int smallestIndex = 0;
    T smallestElement = elements[smallestIndex];

    for (int i = 0; i < size; i++)
    {
        if (elements[i] < elements[smallestIndex])
            smallestIndex = i;
    }

    smallestElement = elements[smallestIndex];
    remove(elements[smallestIndex]);

    // Return whatever was removed.
    return smallestElement;
}

template<typename T>
string Set<T>::toString() const
{
    string setString = "{";

    // This could be cleaner, but it'll work
    for (int i = 0; i < size; i++)
    {
        setString += to_string(elements[i]);

        if (i < (size-1))
            setString += ", ";
    }

    setString += "}";

    return setString;
}

template<typename T>
Set<T> Set<T>::intersectionWith(const Set<T>& other) const
{
    Set<T> newSet;

    for (int i = 0; i < size; i++)
    {
        if (other.contains(elements[i]))
            newSet.add(elements[i]);
    }

    return newSet;
}

#endif // SET_H
