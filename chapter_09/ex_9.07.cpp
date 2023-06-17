/*
 Chapter 09 - Exercise 07
 Create an enumerated type for the Book class called Genre. Have the types be fiction, nonfiction, periodical, biography, and children. Give each book a Genre and make appropriate changes to the Book constructor and member functions.
 */

#include "std_lib_facilities.h"
#include "date.hpp"

enum class Genre{
    fiction, nonfiction, periodical, biography, children
};

class Book {
public:
    Book(const string& title,
         const string& author,
         const int& isbn_n1,
         const int& isbn_n2,
         const int& isbn_n3,
         const char& isbn_x,
         const Date& copyright,
         const Genre& genre);
    string get_title() const { return m_title; }
    string get_author() const { return m_author; }
    Date get_copyright() const { return m_copyright; }
    string get_isbn() const { return m_isbn; }
    Genre get_genre() const { return m_genre; }
    void check_in();
    void check_out();
private:
    string m_isbn;
    string m_title;
    string m_author;
    Date m_copyright;
    Genre m_genre;
    bool is_checked_in = true;
};

Book::Book(const string& title,
           const string& author,
           const int& isbn_n1,
           const int& isbn_n2,
           const int& isbn_n3,
           const char& isbn_x,
           const Date& copyright,
           const Genre& genre) :
m_title{title}, m_author{author}, m_copyright{copyright}, m_genre{genre}
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
        Book ballad{
            "The Ballad of Reading Gaol",
            "Oscar Wilde",
            978, 0, 394, 'n',
            Date{1897, Month::may, 19},
            Genre::fiction
        };
        cout << ballad << '\n';
    }
    catch (runtime_error& e) {
        cout << "Runtime error: " << e.what();
    }
    return 0;
}
