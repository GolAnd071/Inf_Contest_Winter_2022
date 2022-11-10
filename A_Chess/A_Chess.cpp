// A_Chess.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Cell final {
public:
    char v; 					                         // Вертикаль, от 'A' до 'H'
    unsigned short int h;		                         // Горизонталь, от '1' до '8'
    Cell() : Cell('A', 1) {}			                 // Конструктор клетки по умолчанию
    Cell(char v, unsigned short int h) : v(v), h(h) {}	 // Конструктор заданной клетки поля с параметрами
};

int m_abs(int n)
{
    return (n >= 0 ? n : -n);
}

class Piece
{
protected:
    Cell c;

public:
    Piece() : c(Cell()) {}
    Piece(Cell c) : c(c) {}

    virtual ~Piece() {}

    virtual bool available(Cell) const = 0;
};

class King final : public Piece
{
public:
    King(Cell c) : Piece(c) {}

    bool available(Cell c) const override
    {
        unsigned dv = m_abs(static_cast<int>(this->c.v) - static_cast<int>(c.v));
        unsigned dh = m_abs(static_cast<int>(this->c.h) - static_cast<int>(c.h));
        return (dv | dh) == 1;
    }
};

class Bishop final : public Piece
{
public:
    Bishop(Cell c) : Piece(c) {}

    bool available(Cell c) const override
    {
        unsigned dv = m_abs(static_cast<int>(this->c.v) - static_cast<int>(c.v));
        unsigned dh = m_abs(static_cast<int>(this->c.h) - static_cast<int>(c.h));
        return dv == dh && dv != 0;
    }
};

class Rook final : public Piece
{
public:
    Rook(Cell c) : Piece(c) {}

    bool available(Cell c) const override
    {
        unsigned dv = m_abs(static_cast<int>(this->c.v) - static_cast<int>(c.v));
        unsigned dh = m_abs(static_cast<int>(this->c.h) - static_cast<int>(c.h));
        return dv == 0 ^ dh == 0;
    }
};

class Queen final : public Piece
{
public:
    Queen(Cell c) : Piece(c) {}

    bool available(Cell c) const override
    {
        unsigned dv = m_abs(static_cast<int>(this->c.v) - static_cast<int>(c.v));
        unsigned dh = m_abs(static_cast<int>(this->c.h) - static_cast<int>(c.h));
        return (dv == dh && dv != 0) || (dv == 0 ^ dh == 0);
    }
};

void are_available(Cell c, const Piece** pieces, bool* availability, std::size_t pieces_count) {
    for (std::size_t piece_idx = 0; piece_idx != pieces_count; ++piece_idx)
        availability[piece_idx] = pieces[piece_idx]->available(c);
}

int main() {
    const std::size_t size = 4;
    const Piece* pieces[size];
    bool availability[size];

    pieces[0] = new King(Cell('A', 1));
    pieces[1] = new Queen(Cell('B', 2));
    pieces[2] = new Rook(Cell('C', 3));
    pieces[3] = new Bishop(Cell('D', 4));

    are_available(Cell('A', 1), pieces, availability, size);
    for (auto ans : availability)
        std::cout << ans << ' ';
    std::cout << std::endl;

    for (auto p : pieces)
        delete p;

    return 0;
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
