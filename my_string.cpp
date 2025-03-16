#include <iostream>

class My_string {
public:
    /// Деструктор
    ~My_string() {
        delete[] Data;
    }

    /// Конструктор по умолчанию
    My_string() {
        Data = nullptr;
    }

    /// Конструктор копирования
    /// <param name="rhs">Объект, который копируем </param>
    My_string(const My_string &rhs) {
        Data = new char[rhs.Size()];
        for (int i = 0; i < rhs.Size(); i++)
            Data[i] = rhs.Data[i];
    }

    /// Пользовательский конструктор
    /// <param name="data">Данные, которые требуется поместить в создаваемый
    /// объект </param>
    My_string(const char *data) {
        Data = new char[length(data) + 1];
        for (int i = 0; i < length(data); i++)
            Data[i] = data[i];
        Data[length(data)] = '\0';
    }

    /// Оператор присваивания
    /// <param name="data">Объект, который копируем </param>
    /// <returns>Возвращаем ссылку на себя</returns>
    My_string &operator=(const My_string &rhs) {
        if (this == &rhs)
            return *this;
        if (Data != nullptr)
            delete[] Data;

        Data = new char[rhs.Size()];
        for (int i = 0; i < rhs.Size(); i++)
            Data[i] = rhs.Data[i];
        return *this;
    }

    /// Оператор +=
    /// <param name="rhs">Объект, который стоит после знака '+=' </param>
    /// <returns>Возвращаем ссылку на себя</returns>
    My_string &operator+=(const My_string &rhs) {
        char * newData = new char[rhs.Size() + Size() + 1];
        for (int i = 0; i < Size(); i++)
            newData[i] = Data[i];
        for (int i = 0; i < rhs.Size(); i++)
            newData[Size() + i] = rhs.Data[i];
        delete[] Data;
        Data = newData;
        Data[rhs.Size() + Size()] = '\0';
        return *this;
    }

    /// Оператор *=
    /// <returns>Возвращаем ссылку на себя</returns>
    My_string &operator*=(unsigned int m) {
        char * newData = new char[m*Size() + 1];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < Size(); j++)
                newData[i*Size() + j] = Data[j];
        delete[] Data;
        Data = newData;
        Data[m*Size()] = '\0';
        return *this;
    }

    /// Оператор ==
    /// <param name="rhs">Объект, который стоит после знака '==' </param>
    /// <returns>Возвращаем значения равенства двух строк</returns>
    bool operator==(const My_string &rhs) const {
        if (rhs.Size() != Size())
            return false;
        for (int i = 0; i < Size(); i++)
            if (Data[i] != rhs.Data[i])
                return false;
        return true;
    }

    /// Оператор &lt;
    /// <param name="rhs">Объект, который стоит после знака "&lt;" </param>
    /// <returns>Возвращаем значения сравнения двух строк</returns>
    bool operator<(const My_string &rhs) const {
        for (int i = 0; i < std::min(Size(), rhs.Size()); i++) {
            if (Data[i] < rhs.Data[i])
                return true;
            if (Data[i] > rhs.Data[i])
                return false;
        }
        return false;
    }

    /// Функция поиска подстроки
    /// <param name="substr">Подстрока, которую необходимо найти </param>
    /// <returns>Возвращаем позицию substr. Если подстрока не найдена, то
    /// возвратить -1</returns>
    size_t Find(const My_string &substr) const {
        if (substr.Size() == 0)
            return 0;
        if (substr.Size() > Size())
            return -1;
        size_t index = 0;
        for (size_t i = 0; i < Size(); i++)
            if (Data[i] == substr.Data[0]) {
                int count = 0;
                for (size_t j = 1; j < substr.Size(); j++)
                    if (Data[i + j] == substr.Data[j])
                        count++;
                if (count == substr.Size())
                    return i;
            }
        return -1;

    }

    /// Функция замены символов, заменяет все символы oldSymbol на newSymbol.
    /// <param name="oldSymbol">Символ, который требуется заменить </param>
    /// <param name="newSymbol">Символ, на который требуется заменить </param>
    void Replace(char oldSymbol, char newSymbol) {
        char * newData = new char[Size() + 1];
        for (int i = 0; i < Size(); i++)
            if (Data[i] == oldSymbol)
                newData[i] = newSymbol;
            else
                newData[i] = Data[i];
        delete[] Data;
        Data = newData;
        Data[Size()] = '\0';
    }

    /// Функция возвращает длину строки
    /// <returns>Возвращаем длину строки</returns>
    size_t Size() const {
        int length = 0;
        while (Data[length] != '\0')
            length++;
        return length;
    }
    /// Функция для определения пуста ли строка
    bool Empty() const {
        return Size() == 0;
    }

    /// Оператор []
    /// <example>
    /// <code>
    /// My_string str = "some My_string";
    /// char symbol = str[2]; // symbol == 'm'
    /// </code>
    /// </example>
    /// <param name="index"> Индекс символа </param>
    /// <returns> Значение символа в строке с индексом index</returns>
    char operator[](size_t index) const {
        return Data[index];
    }

    /// Оператор []
    /// <example>
    /// <code>
    /// My_string str = "some My_string";
    /// str[0] = 'S'; // теперь переменная str равна "Some My_string"
    /// </code>
    /// </example>
    /// <param name="index"> Индекс символа </param>
    /// <returns> Ссылка на символ в строке с индексом index</returns>
    char &operator[](size_t index, char symbol) {
        char * newData = new char[Size() + 1];
        for (int i = 0; i < Size(); i++)
            if (i == index)
                newData[i] = symbol;
            else
                newData[i] = Data[i];
        delete[] Data;
        Data = newData;
        Data[Size()] = '\0';
        return Data[index];
    }

    /// Смотри пример
    /// <example>
    /// <code>
    /// My_string str = "___some My_string___";
    /// str.RTrim('_'); // теперь переменная str равна "___some My_string"
    /// </code>
    /// </example>
    /// <param name="symbol"> Значение символов, которе отрезаем </param>
    void RTrim(char symbol) {
        int count = 0;
        for (int i = Size(); i > 0; i--)
            if (Data[i] == symbol)
                count ++;
            else break;
        if (count == Size()){
            Data = nullptr;
            return;
        }
        char *newData = new char[Size() - count + 1];
        for (int i = 0; i < Size() - count; i++)
            newData[i] = Data[i];
        delete[] Data;
        Data = newData;
        Data[Size() - count] = '\0';
    }

    /// Смотри пример
    /// <example>
    /// <code>
    /// My_string str = "___some My_string___";
    /// str.LTrim('_'); // теперь переменная str равна "some My_string___"
    /// </code>
    /// </example>
    /// <param name="symbol"> Значение символов, которе отрезаем </param>
    void LTrim(char symbol) {
        int count = 0;
        for (int i = 0; i < Size(); i++)
            if (Data[i] == symbol)
                count ++;
            else break;
        if (count == Size()){
            Data = nullptr;
            return;
        }
        char *newData = new char[Size() - count + 1];
        for (int i = count; i < Size(); i++)
            newData[i - count] = Data[i];
        delete[] Data;
        Data = newData;
        Data[Size() - count] = '\0';
    }

    void swap(My_string &oth) {
        char * temp = new char[Size() + 1];
        for (int i = 0; i < Size(); i++)
            temp[i] = Data[i];
        delete[] Data;
        char * Data = new char[oth.Size() + 1];
        for (int i = 0; i < oth.Size(); i++)
            Data[i] = oth.Data[i];
        Data[oth.Size()] = '\0';

        delete[] oth.Data;
        oth.Data = new char[length(temp) + 1];
        for (int i = 0; i < length(temp); i++)
            oth.Data[i] = temp[i];
        oth.Data[length(temp)] = '\0';


    }

    friend std::ostream &operator<<(std::ostream & out, const My_string & str) {
        out << str.Data;
        return out;
    }

private:
    char *Data;

    int length(const char* data) {
        int length = 0;
        while (data[length] != '\0')
            length++;
        return length;
    }
};

/// Оператор +
/// <example>
/// <code>
/// My_string a = "Hello";
/// My_string b = "World";
/// My_string c = a + b; // c равна "HelloWorld"
/// </code>
/// </example>
/// <returns>Возвращаем строку равную a + b</returns>
My_string operator+(const My_string &a, const My_string &b) {
    return My_string(a) += b;
}

/// Оператор +
/// <example>
/// <code>
/// My_string a = "A";
/// My_string c = a * 5; // c равна "AAAAA"
/// </code>
/// </example>
My_string operator*(const My_string &a, unsigned int b) {
    return My_string(a) *= b;
}

/// Оператор !=
bool operator!=(const My_string &a, const My_string &b) {
    return !(a == b);
}

/// Оператор &gt;
bool operator>(const My_string &a, const My_string &b) {
    if (a == b) return false;
    return !(a < b);
}

/// Оператор вывода
/// <param name="out">Поток куда выводим строку </param>
/// <param name="str">Строка, которую выводим </param>
/// <returns>Возвращаем ссылку на поток</returns>
std::ostream &operator<<(std::ostream &out, const My_string &str);
