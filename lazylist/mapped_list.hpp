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
};

template <class T> MappedList<T>::MappedList( T (_mapFunc)(T *), LazyList<T> *_LL )
{
    mapFunc     = _mapFunc;
    LL          = _LL;
    this->elem  = new T;
}

template <class T> void MappedList<T>::next()
{
    // Here is the difference between a basic LazyList and a MappedList:
    // we call the LazyList next, and then apply the map function.
    LL->next(); 
    if(LL->getElem())
    {
        *(this->elem)   = mapFunc(LL->getElem());
    }else{
        this->elem      = NULL;
    }
}

#endif
