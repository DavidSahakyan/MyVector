#include <iostream>
#include <cassert>

template <typename T>
class Vector
{
public:
    Vector()
    {
        this->array_size = 1;
        this->array = new T[this->array_size];
    }

    Vector(const Vector<T>& vector) : Vector()
    {
        this->concat(vector);
    }

    Vector(int initial_capacity)
    {
        initial_capacity ? initial_capacity : initial_capacity = 1;
        this->array = new T[initial_capacity + 1];
        this->array_size = initial_capacity;
    }

    T get(int index) const
    {
        assert(0 <= index && index < this->array_size);

        return this->array[index];
    }

    int size() const
    {
        return this->elements_count;
    }

    void add(const T& e)
    {
        if(this->array_size > this->elements_count + 1)
        {
            this->array[elements_count++] = e;
            return this;
        }

        this->array_size = array_size * 2;

        T* new_array = new T[this->array_size];

        for(int i = 0;  i < this->array_size; i++)
        {
            new_array[i] = this->array[i];
        }
        delete[] this->array;
        this->array = new_array;
        this->array[elements_count++] = e;
    }

    void remove_element(int index)
    {
        assert(elements_count > 0);
        assert(0 <= index && index < this->elements_count);

        for(int i = index; i < this->elements_count - 1; i++)
        {
            this->array[i] = this->array[i + 1];
        }
        this->elements_count--;
    }

    void concat(const Vector<T>& vector)
    {
        for(int i = 0; i < vector.size(); i++)
        {
            this->add(vector.get(i));
        }
    }

    bool contains(T e)
    {
        for(int i = 0; i < this->elements_count; i++)
        {
            if(array[i] == e)
            {
                return true;
            }
        }
        return false;
    }

    void insert(int insert_index, T element)
    {
        assert(0 <= insert_index && insert_index <= elements_count - 1);
        if(elements_count + 1 > array_size)
        {
            this->array_size = array_size * 2;
            T* new_array = new T[array_size];
            for(int index = 0; index < insert_index; index++)
            {
                new_array[index] = array[index];
            }
            new_array[insert_index] = element;
            for(int index = insert_index + 1; index < elements_count; index++)
            {
                new_array[index] = array[index - 1] ;
            }
            this->elements_count++;
            delete[] array;
            array = new_array;
        }
        else
        {
            for(int index = elements_count; index > insert_index; index--)
            {
                array[index] = array[index - 1];
            }
            array[insert_index] = element;
            elements_count++;
        }
    }

    void iprint()
    {
        for(int index = 0; index < this->size(); index++)
        {
            std::cout<<index<<"->"<<this->get(index)<<std::endl;
        }
    }

    void print()
    {
         for(int index = 0; index < this->size() - 1; index++)
        {
            std::cout<<this->get(index)<<", ";
        }
        std::cout<<this->get(this->size() - 1);
    }

    void operator+=(Vector<T> a)
    {
        this->concat(a);
    }

    void operator+=(T a)
    {
        this->add(a);
    }

    Vector<T> operator+(Vector<T> a)
    {
        Vector<T> res(this->size() + a.size() + 1);
        for(int index = 0; index < this->size(); index++)
        {
            res.add(this->get(index));
        }
        res.concat(a);
        return res;
    }

    Vector<T> operator+(T a)
    {
        Vector<T> res(this->size() + 3);
        for(int index = 0; index < this->size(); index++)
        {
            res.add(this->get(index));
        }
        res.add(a);
        return res;
    }

    ~Vector()
    {
        delete[] array;
    }

private:
    T* array;
    int array_size;
    int elements_count = 0;
};

int main()
{
    }
