#include <iostream>
#include <math.h>
#include <cstdint>
using namespace std;

#define SIZE 10

//TASK 1
class Power {
public:
    Power(float x1 = 0.0, float y1 = 0.0) {
       x = x1;
       y = y1;
    }
    void set(float x1, float y1) {
       x = x1;
       y = y1;
    }
    void printf() {
       cout << x << " in the degree " << y << " is " << pow(x,y) << endl;
    }

private:
    float x;
    float y;
};

//TASK 2
class RGBA {
public:
    RGBA(uint8_t m_red1 = 0, uint8_t m_green1 = 0, uint8_t m_blue1 = 0, uint8_t m_alpha1 = 255) {
       m_red = m_red1;
       m_green = m_green1;
       m_blue = m_blue1;
       m_alpha = m_alpha1;
    }
    void print() {
       cout << "m_red = " << m_red << endl;
       cout << "m_green = " << m_green << endl;
       cout << "m_blue = " << m_blue << endl;
       cout << "m_alpha = " << m_alpha << endl << endl;
    }

private:
    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;
};

//TASK 3
class Stack {
public:
    bool push(int i) {
       if (length_of_stack == SIZE-1) {
          cout << "Stack is full\n";
          return false;
       }
       else {
          arr[++length_of_stack] = i;
          return true;
       }
    }
    int pop() {
       if (length_of_stack != -1) {
          return arr[length_of_stack--];
       }
       else {
          cout << "Stack is empty\n";
          return -1;
       }
    }
    void reset() {
       for(int i = 0; i < SIZE; i++) {
          arr[i] = 0;
       }
       length_of_stack = -1;
    }
    void print() {
       cout << "( ";
       for(int i = 0; i <= length_of_stack; i++) {
          cout << arr[i] << " ";
       }
       cout << ")\n" ;
    }
private:
    int arr[SIZE];
    int length_of_stack = -1;

};

int main()
{
    //1
    Power P;
    P.printf();
    Power P1(2.5f, 1.5f);
    P1.printf();

    //2
    RGBA R;
    R.print();
    RGBA R1(2,43,75,123);
    R1.print();

    //3
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

    return 0;
}
