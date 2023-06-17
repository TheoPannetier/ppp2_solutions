/*
 Chapter 10 - drill
 
 1. Start a program to work with points, discussed in §10.4. Begin by defining the data type Point that has two coordinate members x and y.
 
 2. Using the code and discussion in §10.4, prompt the user to input seven (x,y) pairs. As the data is entered, store it in a vector of Points called original_points.
 
 3. Print the data in original_points to see what it looks like.
 
 4. Open an ofstream and output each point to a file named mydata.txt. On Windows, we suggest the .txt suffix to make it easier to look at the data with an ordinary text editor (such as WordPad).
 
 5. Close the ofstream and then open an ifstream for mydata.txt. Read the data from mydata.txt and store it in a new vector called processed_points.
 
 6. Print the data elements from both vectors.
 
 7. Compare the two vectors and print Something's wrong! if the number of elements or the values of elements differ.
*/

#include "std_lib_facilities.h"

class Point {
public:
    Point(const double& x, const double& y): m_x{x}, m_y{y} {};
    void set_x(const double& x) { m_x = x; }
    void set_y(const double& y) { m_y = y; }
    double get_x() const { return m_x; }
    double get_y() const { return m_y; }
private:
    double m_x;
    double m_y;
};

bool operator!= (const Point& a, const Point& b)
{
    return a.get_x() != b.get_x() || a.get_y() != b.get_y();
}

istream& operator>> (istream& is, Point& p)
{
    char r_bracket; char sep; char l_bracket;
    double x; double y;
    
    if (is >> r_bracket && r_bracket != '(')
    {
        throw runtime_error("Wrong input: missing opening bracket.\n");
    }
    is >> x;
    if (is >> sep && sep != ',')
    {
        throw runtime_error("Wrong input: missing separator.\n");
    }
    is >> y;
    if (is >> l_bracket && l_bracket != ')')
    {
        throw runtime_error("Wrong input: missing closing bracket.\n");
    }
    if (!is && !is.eof())
        throw runtime_error("input went wrong.\n");
    p.set_x(x);
    p.set_y(y);
    return is;
}

ostream& operator<< (ostream& os, const Point& p)
{
    return os << '(' << p.get_x() << ',' << p.get_y() << ')' << '\n';
}

int main()
{
    try {
        // Read points from cin
        vector<Point> original_points;
        int i = 0;
        Point p{0.0, 0.0};
        cout << "Please enter 7 pairs of (x,y) values:\n";
        while (i < 7 && cin >> p) {
            original_points.push_back(p);
            ++i;
        }
        cout << "\n";

        // Print to cout
        cout << "These values were read from input:\n";
        for (Point p:original_points)
            cout << p;
        
        // Output to file
        const string filename = "my_data.txt";
        ofstream ost{filename};
        if (!ost)
            throw runtime_error("Could not open file for output.\n");
        for (Point p:original_points)
            ost << p;
        ost.close();
        
        // Read from file and print
        vector<Point> processed_points;
        ifstream ist{filename};
        if (!ist)
            throw runtime_error("Could not open file for input.\n");
        while (ist >> p) {
            processed_points.push_back(p);
        }
        cout << "These values were read from output file:\n";
        for (Point p:processed_points)
            cout << p;
        
        // Compare vectors
        if (original_points.size() != processed_points.size())
            throw runtime_error("Something's wrong!\n");
        for (int i = 0; i < original_points.size(); i++)
        {
            if (original_points[i] != processed_points[i])
                throw runtime_error("Something's wrong!\n");
        }
    }
    catch (runtime_error& e) {
        cout << "Runtime error: " << e.what();
    }
    return 0;
}
