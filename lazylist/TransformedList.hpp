#ifndef TRANSFORMED_LIST_HPP
#define TRANSFORMED_LIST_HPP

#include "List.hpp"

// This could perfectly be T->S but I'm too lazy
template <class T> class TransformedList : public List<T>
{
    protected:
        List<T>*    baseList;
        void        *iteratorArgs;
        T*          (*iteratorFunction) (List<T>* L, T* E, void *args);
    public:
        TransformedList( 
            List<T>* _baseList,
            T* (*_iteratorFunction)(List<T>* L, T* E, void *args),
            void *_iteratorArgs
        );
        ~TransformedList() {delete this->currentElement;};

        T*      next();
        void    rewind();
};

template <class T> TransformedList<T>::TransformedList(
    List<T>* _baseList,
    T* (*_iteratorFunction)(List<T>* L, T* E, void *args),
    void *_iteratorArgs
){
    baseList = _baseList;
    iteratorArgs = _iteratorArgs;
    iteratorFunction = _iteratorFunction;

    this->currentElement = new T;
    this->currentElement = iteratorFunction(baseList, this->currentElement, iteratorArgs);
}

template <class T> T* TransformedList<T>::next()
{
    this->currentElement = iteratorFunction(baseList, this->currentElement, iteratorArgs);
    return this->currentElement;
}

template <class T> void TransformedList<T>::rewind()
{
    baseList->rewind();
    this->currentElement = iteratorFunction(baseList, this->currentElement, iteratorArgs);
}

#endif
