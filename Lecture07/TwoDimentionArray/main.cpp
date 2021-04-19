#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class array_init_exception : public exception
{
public:
    array_init_exception(const std::string& message, const std::exception& inner)
        : _message(message), _inner(inner) { }

    virtual const char* what() const noexcept override
    {
        return _message.c_str();
    }

    const std::exception& inner_exception() const { return _inner; }

private:
    std::string _message;
    const std::exception _inner;
};

class array_index_exception : public exception
{
public:
    array_index_exception(const std::string& message)
        : _message(message) { }

    virtual const char* what() const noexcept override
    {
        return _message.c_str();
    }

private:
    std::string _message;
};

class TwoDimentionIntArray
{
public:
    TwoDimentionIntArray(size_t h, size_t w)
    {
        _array = new int*[w];
        try
        {
            for (size_t i = 0; i < w; i++)
            {
                _array[i] = new int[h];
            }
        }
        catch (const bad_alloc& e)
        {
            for (size_t i = 0; i < w; i++)
            {
                if (_array[i])
                {
                    delete[] _array[i];
                    _array[i] = nullptr;
                }
            }
            delete[] _array;
            _array = nullptr;

            throw array_init_exception("배열 초기화에 실패했습니다.", e);
        }

        _height = h, _width = w;
    }

    ~TwoDimentionIntArray()
    {
        if (_array)
        {
            for (size_t i = 0; i < _width; i++)
            {
                if (_array[i])
                {
                    delete[] _array[i];
                    _array[i] = nullptr;
                }
            }
            delete[] _array;
            _array = nullptr;
        }
    }

    void Set(size_t i, size_t j, int value)
    {
        if (i >= _height || j >= _width) throw array_index_exception("배열의 범위를 벗어났습니다.");

        _array[i][j] = value;
    }

    int Peek(size_t i, size_t j) const
    {
        if (i >= _height || j >= _width) throw array_index_exception("배열의 범위를 벗어났습니다.");

        return _array[i][j];
    }

    size_t Size() const { return _height * _width; }
    size_t Height() const { return _height; }
    size_t Width() const { return _width; }

private:
    int** _array;
    size_t _height, _width;
};

int main()
{
    try
    {
        TwoDimentionIntArray arr(10, 10);

        cout << "size: " << arr.Size() << endl;

        try
        {
            arr.Set(0, 0, 100);
            arr.Set(9, 9, 1);

            cout << arr.Peek(0, 0) << endl;
            cout << arr.Peek(10, 10) << endl; // error
        }
        catch (const array_index_exception& e)
        {
            cout << e.what() << endl;
        }

        arr.~TwoDimentionIntArray();
    }
    catch (const array_init_exception& e)
    {
        cout << e.what() << endl;
        cout << e.inner_exception().what() << endl;
    }
}
