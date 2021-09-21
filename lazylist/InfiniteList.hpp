#ifndef INFINITE_LIST_HPP
#define INFINITE_LIST_HPP

#include "List.hpp"

template <class T> class InfiniteList : public List<T>
{
    protected:
        void*   successorArgs;
        void    (*successorFunction)    (T* element, void* args);
        T*      startElement;
    public:
        InfiniteList( void (*_successorFunction)(T*, void*), void * _successorArgs, T* _startElement); 
        ~InfiniteList();
        T*      next();
        void    rewind();
};

template <class T> InfiniteList<T>::InfiniteList( void (*_successorFunction)(T*, void*), void * _successorArgs, T* _startElement)
{
    startElement            = _startElement;
    this->currentElement    = new T;
    *(this->currentElement) = *startElement;
    successorFunction       = _successorFunction;
    successorArgs           = _successorArgs;
};

template <class T> InfiniteList<T>::~InfiniteList()
{
    delete this->currentElement;
}

template <class T> T* InfiniteList<T>::next()
{
    successorFunction(this->currentElement, successorArgs);
    return this->currentElement;
}

template <class T> void InfiniteList<T>::rewind()
{
    *(this->currentElement) = *startElement;
}

#endif
