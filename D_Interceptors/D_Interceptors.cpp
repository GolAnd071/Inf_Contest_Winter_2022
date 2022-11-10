// D_Interceptors.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

struct DoubleAbstractStack {
    // some code goes here
public:
    bool push(double next_element) {
        // some code goes here
        before_push();
        // push code
        after_push(next_element);
        return true;
    }

    // other public methods
protected:
    virtual void before_push() = 0;
    virtual void after_push(double pushed_element) = 0;
    virtual void before_pop() = 0;
    virtual void after_pop(double popped_element) = 0;
};

struct DoubleAbstractStack {
    // some code goes here
public:
    bool push(double next_element) {
        // some code goes here
        before_push();
        // push code
        after_push(next_element);
        return true;
    }

    // other public methods
protected:
    virtual void before_push() = 0;
    virtual void after_push(double pushed_element) = 0;
    virtual void before_pop() = 0;
    virtual void after_pop(double popped_element) = 0;
};

class DoubleStackWithMin : public DoubleAbstractStack
{
public:
    DoubleStackWithMin() : DoubleAbstractStack() {}

private:
    std::vector<double> minStack;

    void before_push() override
    {
        return;
    }

    void before_pop() override 
    {
        return;
    }

    void after_push(double pushedElem) override
    {
        double push_element;
        if (minStack.empty())
            push_element = pushedElem;
        else if (pushedElem < minStack.back())
            push_element = pushedElem;
        else
            push_element = minStack.back();

        minStack.push_back(push_element);
    }

    void after_pop(double poppedElem) override
    {
        minStack.pop_back();
    }

public:
    double get_min() const
    {
        return minStack.back();
    }
};

void operate_stack(DoubleAbstractStack& stack);
void check_min(DoubleStackWithMin const& stack);

int main() {
    DoubleStackWithMin min_stack;
    operate_stack(min_stack);
    check_min(min_stack);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
