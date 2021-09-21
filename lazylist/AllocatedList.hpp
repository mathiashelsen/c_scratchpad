#ifndef ALLOCATED_LIST_HPP
#define ALLOCATED_LIST_HPP

#include "List.hpp"

template <class T> class AllocatedList : public List<T>
{
    protected:
        T*  startElement;
        int N_elems;
        int index;
    public:
        AllocatedList(T* _startElement, int _N_elems);
        T*      next();
        void    rewind();
};

template <class T> AllocatedList<T>::AllocatedList(T* _startElement, int _N_elems)
{
    this->currentElement    = _startElement;
    startElement            = _startElement;
    N_elems                 = _N_elems;
    index                   = 0;
};

template <class T> T* AllocatedList<T>::next()
{
    this->currentElement++;
    index++;
    if(index > N_elems-1)
        this->currentElement = NULL;

    return this->currentElement;
};

template <class T> void AllocatedList<T>::rewind()
{
    this->currentElement    = startElement;
    index                   = 0;
};

#endif
