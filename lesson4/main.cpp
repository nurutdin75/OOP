#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <iterator>
#include <array>

using namespace std;
void qs(int* mdata, int first, int last)
{
        int i = first;
        int j = last;
        int x = mdata[(first + last)/2];
        do {
            while (mdata[i] < x) i++;
            while (mdata[j] > x) j--;
            if (i <= j) {
                int temp = mdata[i];
                mdata[i] = mdata[j];
                mdata[j] = temp;
                i++;
                j--;
            }
        } while (i < j);
        if (i < last) qs(mdata, i, last);
        if (first < j) qs(mdata, first, j);
}
class ArrayInt
{
private:
    int m_length;
    int* m_data;
public:
    ArrayInt() : m_length(0), m_data(nullptr){}
    ArrayInt(int _size) : m_length(_size)
    {
        if (_size > 0)
            m_data = new int [m_length];
        else
            m_data = nullptr;
    }
    ArrayInt(int _size, int init_value) : m_length(_size)
    {
        if (_size > 0)
            m_data = new int [m_length];
        else
            m_data = nullptr;
        for (size_t i = 0; i < m_length; i++)
            m_data[i] = init_value;
    }
    ~ArrayInt()
    {
        delete[] m_data;
        m_data = nullptr;
    }
    int size()
    {
        return m_length;
    }
    friend ostream& operator<<(ostream& output, ArrayInt& AI);
    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    void clear()
    {
        if (m_data != nullptr)
        {
            delete[] m_data;
            m_data = nullptr;
            m_length = 0;
        }
    }
    void resize(int newsize)
    {
        if (newsize == m_length) return;
        if (newsize <= 0)
        {
            clear();
            return;
        }
        int* newdata = new int[newsize];
        int copysize = (newsize > m_length) ? m_length : newsize;
        for(size_t i = 0; i < copysize; i++)
            newdata[i] = m_data[i];
        delete[] m_data;
        m_data = newdata;
        m_length = newsize;
    }
    void insert(int value, int index)
    {
        resize(m_length + 1);
        for(size_t i = m_length - 1; i > index; i--)
        {
            m_data[i] = m_data[i - 1];
        }
        m_data[index] = value;
    }
    void random(int number, int range)
    {
        if (m_data != nullptr)
            delete[] m_data;
        m_data = new int[number];
        m_length = number;
        for(size_t i = 0; i < number; i++)
        {
            m_data[i] = rand() % range;
        }

    }
    erase()
    {
        resize(m_length - 1);
    }
    pop_front()
    {
        int copysize = m_length - 1;
        int* newdata = new int[copysize];
        for(size_t i = 0; i < copysize; i++)
        {
            newdata[i] = m_data[i + 1];
        }
        delete[] m_data;
        m_data = newdata;
        m_length = copysize;
    }
    void sort()
    {
       qs(m_data, 0, m_length - 1);
    }

};
ostream& operator<<(ostream& output, ArrayInt& AI)
{
    for(size_t i = 0; i < AI.size(); i++)
        cout << AI.m_data[i] << " ";
        return output;
}
// TASK 3
enum suit {Hearts, Diamonds, Clubs, Spades};
enum mean {Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack = 10, Queen = 10, King = 10, Ace};

class Card
{
public:
    void Flip(){face = !(face);}

protected:
    suit _suit;
    mean _mean;
    bool face;
};
class Hand
{
protected:
    vector<Card> hand1;
};


int main()
{
    setlocale(LC_ALL, "Rus");

    // TASK 1
    cout << "TASK 1" << endl;
    ArrayInt Arr(10,4);
    Arr[5] = 50;
    cout << Arr << endl;
    Arr.resize(8);
    cout << Arr << endl;
    Arr.insert(48, 6);
    cout << Arr << endl;
    Arr.erase();
    cout << Arr << endl;
    Arr.pop_front();
    cout << Arr << endl;
    Arr.random(10, 100);
    cout << Arr << endl;
    Arr.sort();
    cout << Arr << endl;

    //TASK 2
    cout << "\nTASK 2" << endl;
    const int size = 10;
	const int range = 10;
	vector<int> V;
	for(size_t i = 0; i < size; i++)
        V.push_back(rand()%range);
    for(size_t i = 0; i < size; i++)
        cout << V[i] << " ";
    cout << endl;

    vector<int> V2;
    for(size_t i = 0; i < size; i++)
        V2.push_back(1);

    for(size_t i = 0; i < size - 1; i++)
    {
        for(size_t j = i + 1; j < size; j++)
        {
            if (V2[j] != 1) continue;
            if (V[i] == V[j])
            {
                V2[i]++;
                V2[j]++;
            }
        }
    }
    int count = 0;
    for(size_t i = 0; i < size; i++)
        if (V2[i] == 1)
            count++;
    cout << "\nКоличество не повторяющихся элементов : " << count << endl;

    // TASK3

    return 0;
}
