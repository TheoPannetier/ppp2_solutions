#include "std_lib_facilities.h"
// Exercise 5.13

bool is_bull(int answ, int i, vector<int> the_solution)
{
    return answ == the_solution[i];
}

bool is_cow(int answ, vector<int> the_solution)
{
    bool it_is = true;
    for (int sol:the_solution)
        if (answ == sol) it_is = true;
    return it_is;
}

int main()
{
    int seed = 1;
    vector<int> the_solution(4);
    vector<int> the_answer(4);
    
    int nb_bulls = 0;
    int nb_cows = 0;
    bool has_won = false;
    
    try {
        cout << "Enter a seed to play that isn't zero:";
        cin >> seed;
        if (!cin || seed == 0) throw logic_error("only enter a single integer that isn't zero.\n");
        
        while (seed != 0) {
            // Roll the solution
            seed_randint(seed); // srand() fails to seed the RNG
            for (int i = 0; i < the_solution.size(); ++i)
            {
                the_solution[i] = randint(9);
                cout << the_solution[i] << " ";
            }
            cout << "\n";
            
            has_won = false;
            while(!has_won)
            {
                cout << "Enter a sequence of 4 digits:";
                for (int i = 0; i < the_answer.size(); i++)
                {
                    cin >> the_answer[i];
                    if (!cin) throw logic_error("wrong input, only enter 4 digits\n");
                }
                if (the_answer.size() != the_solution.size()) throw logic_error("the solution has a different length than the solution.\n");
                
                for (int i = 0; i < the_answer.size(); ++i)
                {
                    if (is_bull(the_answer[i], i, the_solution))
                    {
                        ++nb_bulls;
                    } else if (is_cow(the_answer[i], the_solution)) {
                        ++nb_cows;
                    }
                }
                
                cout << nb_bulls << " bulls\t" << nb_cows << " cows.\n";
                
                if (nb_bulls == the_solution.size())
                {
                    cout << "You guessed correctly, victory!\n";
                    has_won = true;
                    cout << "Play again? Enter a new seed, or zero to terminate:";
                    cin >> seed;
                    if (!cin) throw logic_error("only enter a single integer.\n");
                } else if (nb_bulls > the_solution.size() || nb_cows > the_solution.size() || nb_bulls + nb_cows > the_solution.size()) {
                    throw runtime_error("the number of bulls and cows exceeds the length of the solution.\n");
                }
                // Reset counters
                nb_bulls = 0;
                nb_cows = 0;
                
            }
        }
    }
    catch (logic_error& e) {
        cout << "Logic error: " << e.what();
    }
    catch (runtime_error& e) {
        cout << "Runtime error: " << e.what();
    }
}
