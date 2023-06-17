/*
 Exercise 10.10
 /!\ /!\ UNFINISHED - ran out of time for this one
    Add a command from x to the calculator from Chapter 7 that makes it take input from a file x.
    Add a command to y to the calculator that makes it write its output (both standard output and error output) to file y.
    Write a collection of test cases based on ideas from §7.3 and use that to test the calculator.
    Discuss how you would use these commands for testing.
 
// Analysis
 precedence?
 if x contains several instructions, separated by ';', execute all
 if cin contains other instructions after, execute all instructions in file first;
 output is only written to file y after to y is met;
 if a second from x is met, if same file produce message and ignore, if different file read from that file instead
 if a second to y is met, if same file produce message and ignore, if different file write to that file instead
 
 That is:
 1*1; from x; 2+3;
    // with x{4+7; 3-1} should return 1, 11, 2, then 5
 7%6; to y; 5/2; from x;
    // should return 1, then in y {1, 2, 5} with x same as above

 Test abuse on file names:
 - file is not a filename
    does not end in .txt
    does not start with letter
    contains space
 - file does not exist (read, fine for write)
 
 
 All the use cases below from Chapter 07 should work as intended when written in x:
 // Use
     00000;
     0.00000000000001 * 2.0;
     4534333330894863873485468936946+1;
     q
     1+2;q;
     1+2q;
     .2;
     1+-1.2;
     1+--1.2;
     +3-1;
     (1+2)*3;q;
     let var=4;
     let z=y*3.2;
     5 % 2;
     3.2%3;
     ;
     k + 1; // should be 1001
     let krakow = 1.0;
     sqrt(5+(8-4));
     sqrt(9)*4+2;
     sqrt(-9);
     pow(4+2, 3*3);
  
     // Abuse
     3/0.0;
     .;
     $;
     1.+3;
     let =7+6;
     let y=4; let y=1;
     let var iable = 3;
     sol; // undefined
     (1+2*3;
     1+2*3);
     sqrt 9;
     sqrt(8 +3;
     pow(4);
     pow(4, -3);
     pow(4, 1.2);
*/

#include "std_lib_facilities.h"

// Both file streams need to be global
ifstream ifs;
ofstream ofs;
const string i_filename = "ex_10.10_input.txt";
const string o_filename = "ex_10.10_output.txt";

struct Token {
    // Logical units of the calculation:
    // numbers, operators, names and brackets
    char kind; // what type is it
    double value;
    string name; // only for variables
    Token(char ch) :kind(ch), value(0) { }
    Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, string n) :kind(ch), name(n) { }
};

class Token_stream {
    // Process input into tokens
    bool full;
    Token buffer;
public:
    Token_stream() :full(0), buffer(0) { }

    Token get();
    void unget(Token t) { buffer = t; full = true; }

    void ignore(char);
};

// Symbolic constants
const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char root = 'R';
const char power = 'P';
const char from = 'I';
const char to = 'O';

Token Token_stream::get()
{
    // Process input into tokens
    if (full) { full = false; return buffer; }
    char ch;
    if (ifs.is_open())
    {
        ifs >> ch;
    } else {
        cin >> ch;
    }
    switch (ch) {
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case ';':
    case '=':
    case ',':
        return Token(ch); // token is simply the input
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {
        double val;
        if (ifs.is_open())
        {
            ifs.unget(); // read full value
            ifs >> val;
        } else {
            cin.unget();
            cin >> val;
        }
        return Token(number, val);
    }
    case '#':
        return Token(let);
    default:
        // read words: that is, any continuous seq of letters and digits
        if (isalpha(ch)) {
            string s;
            s += ch;
            if (ifs.is_open())
            {
                while (ifs.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
                ifs.unget();
            } else {
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
                cin.unget();
            }
            if (s == "quit") return Token(quit);
            if (s == "k") return Token(number, 1000);
            if (s == "sqrt") return Token(root);
            if (s == "pow") return Token(power);
            if (s == "from") return Token(from);
            if (s == "to") return Token(to);
            return Token(name, s);
        }
        error("Bad token");
    }
    return Token('$', -1.0); // should never be called but compiler requires it
}

void Token_stream::ignore(char c)
{
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch;
    if (ifs.is_open())
    {
        while (ifs >> ch)
            if (ch == c) return;
    } else {
        while (cin >> ch)
            if (ch == c) return;
    }
    
}

struct Variable {
    string name;
    double value;
    Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
    for (int i = 0; i < names.size(); ++i)
        if (names[i].name == s) return names[i].value;
    error("get: undefined name ", s);
    return -1.0; // should never be called but compiler requires it
}

void set_value(string s, double d)
{
    for (int i = 0; i <= names.size(); ++i)
        if (names[i].name == s) {
            names[i].value = d;
            return;
        }
    error("set: undefined name ", s);
}

bool is_declared(string s)
{
    for (int i = 0; i < names.size(); ++i)
        if (names[i].name == s) return true;
    return false;
}

Token_stream ts;

double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
    }
    case '-': // a negative number
        return -primary();
    case '+': // also allowed for consistency
        return primary();
    case number:
        return t.value;
        // k is already handled in the token stream
    case name:
        return get_value(t.name);
    case root:
    {
        t = ts.get();
        if (t.kind != '(') error("'(' expected");
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        if (d < 0) error("no real root for negative numbers");
        return sqrt(d);
    }
    case power:
    {
        t = ts.get();
        if (t.kind != '(') error("'(' expected");
        double d = expression();
        t = ts.get();
        if (t.kind != ',') error("',' expected");
        double exponent = narrow_cast<int>(expression());
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        if (exponent < 0) error("exponent cannot be negative");
        return pow(d, exponent);
    }
    default:
        error("primary expected");
    }
    return -1.0; // should never be called but compiler requires it
}

double term()
{
    double left = primary();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case '*':
            left *= primary();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left /= d;
            break;
        }
        case '%':
        {
            double d = primary();
            if (d == 0) error("divide by zero");
            left = fmod(left,d);
            break;
        }
            default:
            ts.unget(t);
            return left;
        }
    }
}

double expression()
{
    double left = term();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.unget(t);
            return left;
        }
    }
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != name) error("name expected in declaration");
    string name = t.name;
    if (is_declared(name)) error(name, " declared twice");
    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", name);
    double d = expression();
    names.push_back(Variable(name, d));
    return d;
}

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.unget(t);
        return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
    while (true) try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t = ts.get();
        if (t.kind == quit) return;
        if (t.kind == from) {
            ifs.open(i_filename);
            if (!ifs)
                error("Could not open " + i_filename);
        }
        if (t.kind == to) {
            ofs.open(o_filename);
            if (!ofs)
                error("Could not open " + o_filename);
        }
        ts.unget(t); // put back into input queue to process in statement()
        cout << result << statement() << endl;
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}

int main()
{
    try {
        calculate();
        return 0;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << endl;
        char c;
        while (cin >> c && c != ';');
        return 1;
    }
    catch (...) {
        cerr << "exception\n";
        char c;
        while (cin >> c && c != ';');
        return 2;
    }
}
