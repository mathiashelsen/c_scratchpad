#ifndef LAZY_LIST_HPP
#define LAZY_LIST_HPP

template <class T> class LazyList{
    protected:
        T*      elem;
    public:
        // Variables
        T*      (*nextFunc) (T *);
        void    (*printFunc)(T *);
        T*      startElem;

        // Member functions
        LazyList();
        LazyList( T* (*_nextFunc)(T *), void (*_printFunc)(T *), T* _elem);
        virtual void    next();
        T*      getElem();
        void    show();
};

template <class T> LazyList<T>::LazyList()
{
    nextFunc    = NULL;
    printFunc   = NULL;
    elem        = NULL;
    startElem   = NULL;
};

template <class T> LazyList<T>::LazyList(T* (*_nextFunc)(T *), void (*_printFunc)(T *), T *_elem)
{
    nextFunc    = _nextFunc;
    printFunc   = _printFunc;
    elem        = _elem;
    startElem   = _elem;
};

template <class T> void LazyList<T>::show()
{
    while(elem)
    {
        printFunc(elem);
        this->next();
    }
};

template <class T> T* LazyList<T>::getElem()
{
    return elem;
}

template <class T> void LazyList<T>::next()
{
    elem = nextFunc(elem);
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
