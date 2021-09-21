#ifndef LIST_HPP
#define LIST_HPP

#include <stdio.h>

template <class T> class List
{
    protected:
        T*              currentElement;
        void            (*printFunction)(T *);
    public:
        List();
        virtual T*      next();
        virtual void    rewind();
                void    show();
                T*      get();
};


template <class T> List<T>::List(void)
{
    currentElement = NULL;
};

template <class T> void List<T>::show(void)
{
    while(currentElement)
    {
        printFunction(currentElement);
        this->next();
    };

    this->rewind();
};

template <> void List<int>::show(void)
{
    printf("[");
    while(currentElement)
    {
        printf("%d", *currentElement);
        this->next();
        if(currentElement)
            printf(", ");
    }
    printf("]\n");

    this->rewind();
};

template <class T> T* List<T>::next(void)
{
    return NULL;
}

template <class T> T* List<T>::get(void)
{
    return currentElement;
};

template <class T> void List<T>::rewind(void)
{

}
#endif
