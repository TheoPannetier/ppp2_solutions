/*
 Chapter 09 - Exercise 06
 Add operators for the Book class. Have the == operator check whether the ISBN numbers are the same for two books. Have != also compare the ISBN numbers. Have a << print out the title, author, and ISBN on separate lines.
 */

#include "std_lib_facilities.h"
#include "date.hpp"

class Book {
public:
    Book(const string& title,
         const string& author,
         const int& isbn_n1,
         const int& isbn_n2,
         const int& isbn_n3,
         const char& isbn_x,
         const Date& copyright);
    string get_title() const { return m_title; }
    string get_author() const { return m_author; }
    Date get_copyright() const { return m_copyright; }
    string get_isbn() const { return m_isbn; }
    void check_in();
    void check_out();
private:
    string m_isbn;
    string m_title;
    string m_author;
    Date m_copyright;
    bool is_checked_in = true;
};

Book::Book(const string& title,
           const string& author,
           const int& isbn_n1,
           const int& isbn_n2,
           const int& isbn_n3,
           const char& isbn_x,
           const Date& copyright) :
m_title{title}, m_author{author}, m_copyright{copyright}
{
    // i should also check for author and title format
    // but without regex its tedious and I don't have that time
    
    if (!isalpha(isbn_x) && !isdigit(isbn_x))
        throw logic_error("Last element of ISBN must be a letter or digit");
    m_isbn = to_string(isbn_n1) + '-' +
             to_string(isbn_n2) + '-' +
             to_string(isbn_n3) + '-' +
             isbn_x;
}

void Book::check_in()
{
    if (is_checked_in) throw runtime_error("Book is already checked in!");
    else is_checked_in = true;
}

void Book::check_out()
{
    if (!is_checked_in) throw runtime_error("Book is already checked out!");
    else is_checked_in = false;
}

bool operator== (const Book& b1, const Book& b2)
{
    return b1.get_isbn() == b2.get_isbn();
}

bool operator!= (const Book& b1, const Book& b2)
{
    return b1.get_isbn() != b2.get_isbn();
}

ostream& operator<< (ostream& os, const Book& b)
{
    return os << b.get_title() << '\n'
        << b.get_author() << '\n'
        << b.get_isbn();
}

int main()
{
    try {
        Book ballad{"The Ballad of Reading Gaol", "Oscar Wilde", 978, 0, 394, 'n', Date{1897, Month::may, 19}};
        cout << ballad << '\n';
    }
    catch (runtime_error& e) {
        cout << "Runtime error: " << e.what();
    }
    return 0;
}
