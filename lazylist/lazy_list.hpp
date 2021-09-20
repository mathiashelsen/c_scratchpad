#ifndef LAZY_LIST_HPP
#define LAZY_LIST_HPP

template <class T> class LazyList{
    protected:
        T*      elem;
    public:
        // Variables
        T*      (*nextFunc) (T *);
        void    (*printFunc)(T *);
        T       startElem;
        T*      startElemPtr;

        // Member functions
        LazyList();
        LazyList( T* (*_nextFunc)(T *), void (*_printFunc)(T *), T* _elem);
        virtual void    next();
        virtual void    rewind();
        virtual T*      getElem();
        void            show();
};

template <class T> LazyList<T>::LazyList()
{
    nextFunc        = NULL;
    printFunc       = NULL;
    elem            = NULL;
    startElemPtr    = NULL;
};

template <class T> LazyList<T>::LazyList(T* (*_nextFunc)(T *), void (*_printFunc)(T *), T *_elem)
{
    nextFunc        = _nextFunc;
    printFunc       = _printFunc;
    elem            = _elem;
    startElem       = *elem;
    startElemPtr    = elem;
    //printf("Setting LazyList<T>->elem to %p\n", this->elem);
};

template <class T> void LazyList<T>::show()
{
    while(elem)
    {
        printFunc(elem);
        this->next();
    }
};

template <class T> void LazyList<T>::rewind()
{
    //printf("Getting a call for LazyList<T>->rewind()\n");
    this->elem      = this->startElemPtr;
    *(this->elem)   = this->startElem;
    //printf("Setting LazyList<T>->elem to %p\n", this->elem);
};

template <class T> T* LazyList<T>::getElem()
{
    return elem;
}

template <class T> void LazyList<T>::next()
{
    //printf("Getting a call for LazyList<T>->next()\n");
    //printf("Going from pointer %p", elem);
    elem = nextFunc(elem);
    //printf(" to pointer %p\n", elem);
}

template <> void LazyList<int>::show()
{
    printf("[");
    while(elem)
    {
        printf("%d", *elem);
        this->next();
        if(elem)
            printf(", ");
    }
    printf("]\n");
}


#endif
