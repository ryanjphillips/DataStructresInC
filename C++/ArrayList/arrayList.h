#include <iostream>
#include <stdexcept>
#define MIN_CAPACITY 8

template <typename T>
class ArrayList
{
    private:
        int size;
        int max_size;
        T *data;
        void resize(int new_max_size);
    public:
        ArrayList() : size (0), max_size(MIN_CAPACITY)
                    {data = new T[max_size];}
        ArrayList(const ArrayList &rhs);
        const ArrayList& operator=(const ArrayList& rhs);
        ~ArrayList();
        T & operator[](int i);
        void insert(int i, const T& x);
        void erase(int i);
        bool find(const T& x);
        void remove(int i);
};
