#ifndef LAZY_LIST_HPP
#define LAZY_LIST_HPP

template <class T> class LazyList{
    private:
        T* (*nextFunc)(T *);
        void (*printFunc)(T *);
        T* elem;
    public:
        LazyList( T* (*_nextFunc)(T *), void (*_printFunc)(T *), T* _elem);
        void show();
};

template <class T> LazyList<T>::LazyList(T* (*_nextFunc)(T *), void (*_printFunc)(T *), T *_elem)
{
    nextFunc    = _nextFunc;
    printFunc   = _printFunc;
    elem        = _elem;
};

template <class T> void LazyList<T>::show()
{
    T* elemIterator = elem;
    while(elemIterator)
    {
        printFunc(elemIterator);
        elemIterator = nextFunc(elemIterator);
    }
};

template <> void LazyList<int>::show()
{
    int* elemIterator = elem;
    printf("[");
    while(elemIterator)
    {
        printf("%d", *elemIterator);
        elemIterator = nextFunc(elemIterator);
        if(elemIterator)
            printf(", ");
    }
    printf("]\n");
}

#endif
