#ifndef CLASSSET_SET_H
#define CLASSSET_SET_H
#include <iostream>
#include <QLabel>
#include <QString>
#include <QTableWidget>
namespace SET
{

    template<typename T>
    class Set
    {
    public:
        Set<T>()
        {
            size = -1;
            capasity = 10;
            arr = new T[capasity];
        }

        explicit Set<T>(int _size)
        {
            size = -1;
            for(capasity = 10; capasity < _size; capasity*=2);
            arr = new T[capasity];
        }

        Set<T>(T* sorce, int _size)
        {
            for(capasity = 10; capasity < _size; capasity*=2);
            arr = new T[capasity];
            for(size = 0; size<=_size-1; ++size)
            {
                arr[size] = sorce[size];
            }
            --size;
            remove_dub();
        }
        Set<T>(const Set<T>& old)
        {
            capasity = old.capasity;
            arr = new T[capasity];
            for(size = 0; size<=old.size; ++size)
            {
                arr[size] = old.arr[size];
            }
            --size;
        }
        ~Set<T>()
        {
            delete [] arr;
        }

        bool belong_this(const T& op) const
        {
            for(int i = 0; i<=size; ++i)
            {
                if(arr[i]==op)
                {
                    return true;
                }
            }
            return false;
        }
        void remove(const T& op)
        {
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
        }

        Set<T> operator+(Set<T>& op2)
        {//обєднання
            remove_dub();
            op2.remove_dub();
            int tmp_size = size + op2.size+1;
            T tmp[tmp_size];
            int i = -1;
            for(int j = 0; j<=size; ++j)
            {
                ++i;
                tmp[i] = arr[j];
            }
            for(int j = 0; j<=op2.size; ++j)
            {
                ++i;
                tmp[i] = op2.arr[j];
            }
            return Set(tmp, tmp_size+1);
        }
        Set<T> operator+(T op2)
        {//додати новий елемент
            remove_dub();
            if(this->belong_this(op2))
                return *this;
            T tmp[size+1];
            for(int i = 0; i<=size; ++i)
            {
                tmp[i] = arr[i];
            }
            tmp[size+1] = op2;
            return Set<T>(tmp, size+2);
        }
        friend Set<T> operator+(T op1, Set<T>& op2)
        {
            return op2+op1;
        }
        Set<T> operator/(Set<T>& op2)
        {//а без в
            remove_dub();
            op2.remove_dub();
            T tmp[size+op2.size];
            int tmp_size = -1;
            for(int i = 0; i<=size; ++i)
            {
                if(!op2.belong_this(arr[i]))
                {
                    ++tmp_size;
                    tmp[tmp_size] = arr[i];
                }
            }
            return Set<T>(tmp, tmp_size+1);
        }
        Set<T> operator-(Set<T> &op2)
        {//спільна частина
            remove_dub();
            op2.remove_dub();
            T tmp[size+op2.size];
            int tmp_size = -1;
            for(int i = 0; i<=size; ++i)
            {
                if(op2.belong_this(arr[i]))
                {
                    ++tmp_size;
                    tmp[tmp_size] = arr[i];
                }
            }
            return Set<T>(tmp, tmp_size+1);
        }
        Set<T> operator-(T op2)
        {//видаоити елемент
            remove_dub();
            T tmp[size];
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
            return Set<T>(tmp, tmp_size+1);
        }
        friend Set<T> operator-(T op1, Set<T>& op2)
        {
            return op2 - op1;
        }
        Set<T> operator^(Set<T>& op2)
        {//альтернативне або
            remove_dub();
            op2.remove_dub();
            T tmp[size+op2.size];
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
            return Set<T>(tmp, tmp_size+1);
        }
        Set<T>& operator=(const Set<T>& op2)
        {
            if(&op2==this)
                return *this;
            delete [] arr;
            while(capasity<op2.capasity)capasity*=2;
            arr = new T [capasity];
            for(size=0; size<=op2.size; ++size)
                arr[size] = op2.arr[size];
            --size;
            return *this;
        }
        /*friend void operator<<(QTableWidget *table, Set<T>& set)
        {

        }*/
        int get_size(){return size;}
        T operator[](int index)
        {
            return arr[index];
        }
    private:
        void resize()
        {
            auto *tmp = new T [capasity*2];
            for(int i = 0; i<=size; ++i)
            {
                tmp[i] = arr[i];
            }
            capasity*=2;
            delete [] arr;
            arr = tmp;
        }
        void remove_dub()
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
        }
        int size;
        int capasity;
        T *arr;
    };
}


#endif //CLASSSET_SET_H
