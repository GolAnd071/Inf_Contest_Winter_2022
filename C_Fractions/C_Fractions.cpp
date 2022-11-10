// C_Fractions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <cstdint>

class Fraction final
{
private:
    // Do NOT rename
    int64_t numerator;
    uint64_t denominator;

    // Do NOT delete
    template <class T>
    friend bool operator==(const Fraction& lhs, const T& rhs);

public:
    uint64_t m_gcd(uint64_t a, uint64_t b) const
    {
        return (b == 0 ? a : m_gcd(b, a % b));
    }

    uint64_t m_abs(int64_t n) const
    {
        return (n >= 0 ? n : -n);
    }

    void m_red(int64_t& a, uint64_t& b) const
    {
        uint64_t gcd = m_gcd(m_abs(a), b);
        a /= static_cast<int64_t>(gcd);
        b /= gcd;
    }

    Fraction() = delete;
    Fraction(const Fraction& rhs) = default;
    Fraction& operator=(const Fraction& rhs) = default;

    Fraction(int64_t numerator, uint64_t denominator)
    {
        m_red(numerator, denominator);
        this->numerator = numerator;
        this->denominator = denominator;
    }
    
    Fraction operator-() const
    {
        return Fraction(-numerator, denominator);
    }

    Fraction operator*(const Fraction& rha) const
    {
        uint64_t lgcd = m_gcd(m_abs(numerator), rha.denominator);
        uint64_t rgcd = m_gcd(m_abs(rha.numerator), denominator);

        int64_t res_numerator = (numerator / lgcd) * (rha.numerator / rgcd);
        uint64_t res_denominator = (denominator / rgcd) * (rha.denominator / lgcd);

        return Fraction(res_numerator, res_denominator);
    }

    Fraction operator*=(const Fraction& rha)
    {
        *this = *this * rha;
        return *this;
    }

    Fraction operator+(const Fraction& rha) const
    {
        uint64_t bd_gcd = m_gcd(denominator, rha.denominator);
        uint64_t bd_lcm = (denominator / bd_gcd) * rha.denominator;

        int64_t res_numerator = (rha.denominator / bd_gcd) * numerator + (denominator / bd_gcd) * rha.numerator;
        uint64_t res_denominator = bd_lcm;

        m_red(res_numerator, res_denominator);

        return Fraction(res_numerator, res_denominator);
    }

    Fraction operator+=(const Fraction& rha)
    {
        *this = *this + rha;
        return *this;
    }

    Fraction operator-(const Fraction& rha) const
    {
        return *this + (-rha);
    }

    Fraction operator-=(const Fraction& rha)
    {
        *this = *this - rha;
        return *this;
    }
};

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
