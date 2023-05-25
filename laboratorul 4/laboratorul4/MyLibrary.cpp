#define _CRT_SECURE_NO_WARNINGS
#include "MyLibrary.h"
#include <iostream>
#include <string.h>
#include <stdarg.h>

MyLibrary::~MyLibrary() {
    delete[] books;
}

 
MyLibrary::MyLibrary(std::ostream& output_stream): output_stream(output_stream)
{
    books = nullptr;
    books_count = 0;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books)
    : output_stream(output_stream), books_count(books_count), books(new int[books_count]) {
    for (unsigned i = 0; i < books_count; i++)
        this->books[i] = books[i];
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max)
    : output_stream(output_stream), books_count(books_count) {
    books = new int[books_count];
    for (unsigned i = 0; i < books_count; i++)
        books[i] = min + rand() % (max - min);
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream) {
    char sep[] = ";";
    char* p = new char[strlen(books_values) + 1];
    char* s = new char[strlen(books_values)];
    strcpy(p, books_values);
    s = strtok(p, sep);
    this->books_count = 0;

    while (s != nullptr)
    {
        s = strtok(NULL, sep);
        this->books_count += 1;
    }

    books = new int[books_count];
    strcpy(p, books_values);
    s = strtok(p, sep);

    for (unsigned i = 0; i < books_count; i++)
    {
        books[i] = 0;
        for (int j = 0; j < strlen(s); j++)
            books[i] = books[i] * 10 + (s[j] - '0');
        s = strtok(NULL, sep);
    }

    delete[] p;
    delete[] s;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream), books_count(books_count) {
    books = new int[books_count];
    va_list list;
    va_start(list, books_count);
    for (unsigned i = 0; i < books_count; i++)
        books[i] = va_arg(list, int);
    va_end(list);
}

MyLibrary::MyLibrary(std::initializer_list<int> v) : output_stream(std::cout) {
    this->books_count = (int)v.size();
    this->books = new int[books_count];
    const int* ptr = v.begin();
    for (unsigned i = 0; i < books_count; i++)
        books[i] = ptr[i];
}

MyLibrary::MyLibrary(const MyLibrary& copied_library)
    : output_stream(copied_library.output_stream), books_count(copied_library.books_count), books(new int[copied_library.books_count]) {
    for (unsigned i = 0; i < books_count; i++)
        this->books[i] = copied_library.books[i];
}

void MyLibrary::print_books() const {
    if (books_count == 0)
    {
        output_stream << "Found -1 books" << std::endl;
        return;
    }
    output_stream << "Found " << MyLibrary::get_books_count() << " books" << std::endl;
    for (unsigned i = 0; i < books_count; i++)
        output_stream << books[i] << " ";
    output_stream << std::endl;

}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) {
    this->books[book_index] = book_id;
}

unsigned MyLibrary::get_books_count() const {
    return books_count;
}

int MyLibrary::get_book_id_by_index(int index) const {
    if (index >= books_count)
        return -1;
    return books[index];
}