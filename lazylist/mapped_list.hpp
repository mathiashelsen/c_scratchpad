#ifndef MAPPED_LIST_HPP
#define MAPPED_LIST_HPP

#include "lazy_list.hpp"

template <class T> class MappedList: public LazyList<T>
{
    public:
        T               (* mapFunc) (T *);
        LazyList<T>*    LL;

        MappedList( T (_mapFunc)(T *), LazyList<T> *_LL);
        void            next();
        void            rewind();
};

template <class T> MappedList<T>::MappedList( T (_mapFunc)(T *), LazyList<T> *_LL )
{
    mapFunc             = _mapFunc;
    LL                  = _LL;
    this->elem          = new T;
    *(this->elem)       = mapFunc(LL->getElem());
    this->startElemPtr  = this->elem;
    //printf("Setting MappedList<T>->elem to %p\n", this->elem);
}

template <class T> void MappedList<T>::next()
{
    //printf("Getting a call for MappedList<T>->next()\n");
    // Here is the difference between a basic LazyList and a MappedList:
    // we call the LazyList next, and then apply the map function.
    LL->next(); 

    // Here we keep iterating as long at the base list is valid. However,
    // it makes sense to check that the map function also returns valid
    // values. For filter we should keep going until the baselist is exhausted,
    // but for find/take we should keep stop when the return value goes false/true.
    // This can be done by a FilteredList or TakenList class or similar.
    if(LL->getElem())
    {
        *(this->elem)   = mapFunc(LL->getElem());
    }else{
        this->elem      = NULL;
    }
}

template <class T> void MappedList<T>::rewind()
{
    //printf("Getting a call for MappedList<T>->rewind()\n");
    LL->rewind();
    this->elem = this->startElemPtr;
    *(this->elem)   = mapFunc(LL->getElem());
    //printf("Setting MappedList<T>->elem to %p\n", this->elem);
}

#endif
