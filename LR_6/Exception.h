#pragma once
#include <cstdlib>
#include <cstdio>
#include <iostream>

//выход за границы
class indexoutofbounds : public std::invalid_argument
{
public:
    indexoutofbounds(const char *message) : std::invalid_argument(message)
    {
    }
};

//список пуст
class nostructure : public std::invalid_argument
{
public:
    nostructure(const char *message) : std::invalid_argument(message)
    {
    }
};

//деление на ноль
class difzero : public std::invalid_argument
{
public:
    difzero(const char *message) : std::invalid_argument(message)
    {
    }
};

//ошибка открытия файла
class fileopen : public std::invalid_argument
{
public:
    fileopen(const char *message) : std::invalid_argument(message)
    {
    }
};

//ошибка чтения файла
class fileread : public std::invalid_argument
{
public:
    fileread(const char *message) : std::invalid_argument(message)
    {
    }
};

//ошибка записи файла
class filewrite : public std::invalid_argument
{
public:
    filewrite(const char *message) : std::invalid_argument(message)
    {
    }
};