// Exercise 4.1
#include "std_lib_facilities.h"

// ----- Part 1 ----- //
int main()
{
    // rates on the 03/03/2023 6PM GMT+1
    constexpr double usd_to_jpy = 136.09;
    constexpr double usd_to_eur = 0.94;
    constexpr double usd_to_gbp = 0.83;
    double amount = 0;
    string currency = " ";
    
    cout << "Please enter an amount of money followed by a currency (jpy, eur or gbp):\n";
    cin >> amount >> currency;
    
    if (currency == "jpy")
        cout << amount << " JPY == " << amount / usd_to_jpy << " USD\n";
    else if (currency == "eur")
        cout << amount << " EUR == " << amount / usd_to_eur << " USD\n";
    else if (currency == "gbp")
        cout << amount << " GBP == " << amount / usd_to_gbp << " USD\n";
    else
        cout << "Sorry, I don't know a currency called '" << currency << "'\n";
}

// ----- Part 2 ----- //
int main()
{
    // rates on the 03/03/2023 6PM GMT+1
    constexpr double usd_to_jpy = 136.09;
    constexpr double usd_to_eur = 0.94;
    constexpr double usd_to_gbp = 0.83;
    constexpr double usd_to_cny = 6.91;
    constexpr double usd_to_dkk = 7.01;

    double amount = 0;
    char currency = ' ';
    
    cout << "Please enter an amount of money followed by a currency (j for yen, e for euro, g for british pound, y for yuan, k for danish kroner):\n";
    cin >> amount >> currency;
    
    switch (currency) {
        case 'j':
            cout << amount << " JPY == " << amount / usd_to_jpy << " USD\n";
            break;
         case 'e':
            cout << amount << " EUR == " << amount / usd_to_eur << " USD\n";
            break;
         case 'g':
            cout << amount << " GBP == " << amount / usd_to_gbp << " USD\n";
            break;
         case 'y':
            cout << amount << " CNY  == " << amount / usd_to_cny << " USD\n";
            break;
         case 'k':
            cout << amount << " DKK == " << amount / usd_to_dkk << " USD\n";
            break;
            
        default:
            cout << "Sorry, I don't know a currency called '" << currency << "'\n";
            break;
    }
}

// ----- Part 3 ----- //
int main()
{
    char c = 'a';
    cout << c << "\t" << int(c) << "\n";
    while (c < 'z')
    {
        c = char(c + 1);
        cout << c << "\t" << int(c) << "\n";
    }
}

// ----- Part 4 ----- //
int main()
{
    char c = '0';
    cout << c << "\t" << int(c) << "\n";
    for (int i = 0; i < 74; ++i)
    {
        c = char(c + 1);
        cout << c << "\t" << int(c) << "\n";
    }
}

// ----- Part 5 ----- //
int get_square(int v)
{
    int sq = 0;
    for (int i = 0; i < v; i++)
    {
        sq += v;
    }
    return sq;
}

int main()
{
    for (int i = 0; i < 100; ++i) {
        cout << i << '\t' << get_square(i) << '\n';
    }
}

// ----- Part 6 ----- //

int main()
{
    const vector<string> forbidden_words{
        "mustard", "fish", "giraffe", "nobody", "warden" // whatever
    };
    
    vector<string> words;
    string a_word;
    
    cout << "Enter some words: ";
    while (cin >> a_word) {
        words.push_back(a_word);
    }
    for (int i = 0; i < words.size(); ++i)
    {
        for (string forbidden:forbidden_words)
        {
            if (words[i] == forbidden) words[i] = "BLEEP";
        }
    }
    
    for (int i = 0; i < words.size(); ++i) cout << words[i] << "\n";
}

