#include "Set.h"

namespace SET
{
    /*template<typename T>
    Set<T>::Set()
    {
        size = -1;
        capasity = 10;
        arr = new T[capasity];
    }*/

    /*template<typename T>
    Set<T>::Set(int _size)
    {
        size = -1;
        for(capasity = 10; capasity < _size; capasity*=2);
        arr = new T[capasity];
    }*/

    /*template<typename T>
    Set<T>::Set(T* sorce, int _size)
    {
        for(capasity = 10; capasity < _size; capasity*=2);
        arr = new T[capasity];
        for(size = 0; size<=_size; ++size)
        {
            arr[size] = sorce[size];
        }
        --size;
        remove_dub();
    }*/

    /*template<typename T>
    Set<T>::Set(const Set<T> &old)
    {
        capasity = old.capasity;
        arr = new T[capasity];
        for(size = 0; size<=old.size; ++size)
        {
            arr[size] = old.arr[size];
        }
        --size;
    }*/

    /*template<typename T>
    Set<T>::~Set()
    {
        delete [] arr;
    }*/

    /*template<typename T>
    bool Set<T>::belong_this(const T &op) const
    {
        for(int i = 0; i<=size; ++i)
        {
            if(arr[i]==op)
            {
                return true;
            }
        }
        return false;
    }*/

    /*template<typename T>
    Set<T> Set<T>::operator+(Set<T> &op2)
    {
        remove_dub();
        op2.remove_dub();
        int tmp_size = size + op2.size;
        T tmp[tmp_size];
        int i = 0;
        for(int j = 0; j<=size; ++j)
        {
            tmp[i] = arr[j];
            ++i;
        }
        for(int j = 0; j<=op2.size; ++j)
        {
            tmp[i] = arr[j];
            ++i;
        }
        return Set(tmp, tmp_size);
    }*/

    /*template<typename T>
    Set<T> Set<T>::operator+(T &op2)
    {
        remove_dub();
        if(this->belong_this(op2))
            return *this;
        double tmp[size+1];
        for(int i = 0; i<=size; ++i)
        {
            tmp[i] = arr[i];
        }
        tmp[size+1] = op2;
        return Set<T>(tmp, size+1);
    }*/

    /*template<typename T>
    void Set<T>::remove_dub()
    {
        for(int i = 0; i <= size; i++)
        {
            for(int j = i+1; j <= size; )
            {
                if(arr[j] == arr[i])
                {
                    for(int k = j; k <= size; k++)
                    {
                        arr[k] = arr[k+1];
                    }
                    size--;
                }
                else
                {
                    j++;
                }
            }
        }
    }*/

    /*template<typename T>
    Set<T> operator+(T &op1, Set<T> &op2)
    {
        return op2+op1;
    }*/

    /*template<typename T>
    void Set<T>::resize()
    {
        auto *tmp = new double [capasity*2];
        for(int i = 0; i<=size; ++i)
        {
            tmp[i] = arr[i];
        }
        capasity*=2;
        delete [] arr;
        arr = tmp;
    }*/

    /*template<typename T>
    Set<T> Set<T>::operator/(Set<T> &op2)
    {
        remove_dub();
        op2.remove_dub();
        double tmp[size+op2.size];
        int tmp_size = -1;
        for(int i = 0; i<=size; ++i)
        {
            if(!op2.belong_this(arr[i]))
            {
                ++tmp_size;
                tmp[tmp_size] = arr[i];
            }
        }
        return Set<T>(tmp, tmp_size);
    }*/

    /*template<typename T>
    Set<T> Set<T>::operator-(Set<T> &op2)
    {
        remove_dub();
        op2.remove_dub();
        double tmp[size+op2.size];
        int tmp_size = -1;
        for(int i = 0; i<=size; ++i)
        {
            if(op2.belong_this(arr[i]))
            {
                ++tmp_size;
                tmp[tmp_size] = arr[i];
            }
        }
        return Set<T>(tmp, tmp_size);
    }*/

    /*template<typename T>
    Set<T> Set<T>::operator^(Set<T> &op2)
    {
        remove_dub();
        op2.remove_dub();
        double tmp[size+op2.size];
        int tmp_size = -1;
        for(int i = 0; i<=size; ++i)
        {
            if(!op2.belong_this(arr[i]))
            {
                ++tmp_size;
                tmp[tmp_size] = arr[i];
            }
        }
        for(int i = 0; i<=op2.size; ++i)
        {
            if(!belong_this(op2.arr[i]))
            {
                ++tmp_size;
                tmp[tmp_size] = op2.arr[i];
            }
        }
        return Set<T>(tmp, tmp_size);
    }*/

    /*template<typename T>
    Set<T>& Set<T>::operator=(const Set<T> &op2)
    {
        if(&op2==this)
            return *this;
        delete [] arr;
        while(capasity<op2.capasity)capasity*=2;
        arr = new double [capasity];
        for(size=0; size<=op2.size; ++size)
            arr[size] = op2.arr[size];
        --size;
        return *this;
    }*/

    /*template<typename T>
    std::ostream &operator<<(std::ostream &os, Set<T> &set)
    {
        for(int i = 0; i<=set.size; ++i)
        {
            os<<set.arr[i]<<" ";
        }
        return os;
    }*/

    /*template<typename T>
    Set<T> operator-(T &op1, Set<T> &op2)
    {
        return op2 - op1;
    }*/

    /*template<typename T>
    Set<T> Set<T>::operator-(T &op2)
    {
        remove_dub();
        double tmp[size];
        int tmp_size = -1;
        for(int i = 0; i <= size; i++)
        {
                if(arr[i] == op2)
                {
                    continue;
                }
                ++tmp_size;
                tmp[tmp_size] = arr[i];
        }
        return Set<T>(tmp, tmp_size);
    }*/

    /*template<typename T>
    void Set<T>::remove(const T &op)
    {
        remove_dub();
        for(int i = 0; i <= size; i++)
        {
            if(arr[i] == op)
            {
                for(int k = i; k <= size; k++)
                {
                    arr[k] = arr[k+1];
                }
                size--;
                break;
            }
        }
    }*/

}