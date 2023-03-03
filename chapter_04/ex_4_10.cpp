// Exercise 4.10
#include "std_lib_facilities.h"

string int_to_sign(const int choice) // looking forward to enum classes
{
    switch (choice) {
        case 1:
            return "rock";
            break;
        case 2:
            return "paper";
            break;
        case 3:
            return "scissor";
            break;
        default:
            simple_error("Invalid choice; please pick among 1, 2, 3.");
            return "no"; // never called
    }
}

int main()
{
    int user_choice;
    int which_seq;
    int which_sign;
    
    cout << "Choose among 1 = rock, 2 = paper, 3 = scissor: ";
    cin >> user_choice;
    if (user_choice > 3 || user_choice < 1) {
        simple_error("Invalid choice; please pick among 1, 2, 3.");
    }
    cout << "Choose a digit among 1, 2, 3: ";
    cin >> which_seq;
    if (which_seq > 3 || which_seq < 1) {
        simple_error("Invalid choice; please pick among 1, 2, 3.");
    }
    cout << "Finally choose a digit between 1 and 9: ";
    cin >> which_sign;
    if (which_seq > 9 || which_seq < 1) {
        simple_error("Invalid choice; please pick between 1 and 9.");
    }
    
    // Each "random" vector has all three signs appearing three times
    const vector< vector<int> > rand_matrix {
        // 2d vector aka matrix
        {2, 3, 1, 3, 2, 1, 2, 3, 1},
        {1, 1, 2, 3, 1, 2, 3, 3, 2},
        {3, 1, 3, 1, 2, 3, 1, 2, 2}
    };
    
    const int ai_choice = rand_matrix[which_seq - 1][which_sign - 1];
    cout << "I have picked " << int_to_sign(ai_choice) << ".\n";
    
    switch (user_choice) {
        case 1: // rock
            switch (ai_choice) {
                case 1:
                    cout << "That's a draw...\n";
                    break;
                case 2:
                    cout << "I've won!\n";
                    break;
                case 3:
                    cout << "You've won!\n";
                    break;
                default:
                    break;
            }
        case 2: // paper
            switch (ai_choice) {
                case 1:
                    cout << "You've won!\n";
                    break;
                case 2:
                    cout << "That's a draw...\n";
                    break;
                case 3:
                    cout << "I've won!\n";
                    break;
                default:
                    break;
            }
        case 3: // scissor
            switch (ai_choice) {
                case 1:
                    cout << "I've won!\n";
                    break;
                case 2:
                    cout << "You've won!\n";
                    break;
                case 3:
                    cout << "That's a draw...\n";
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    
    return 0;
}
