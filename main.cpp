// Author: Fransiskus Agapa

// ======================
// simple program to learn and understand how strings can be compared
// user input whether they are an adult of not
// and input their gender and the continent they live in
// compare user input and default-expected values
// ======================

#include <iostream>
#include "string"

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

string eight_teen_older(int valid_resp)
{
    string is_adult;

    if(valid_resp > 0)                  // meaning user input valid response
    {
        is_adult = "adult";
    } else if(valid_resp <= 0)
    {
        is_adult = "child";
    }

    return is_adult;
}

int main()
{
    char user_choice;                                   // only accept an alphabet

    cout << "\n== Simple Information ==" << endl;
    cout << "1. Input Gender" << endl;
    cout << "2. Input Continent" << endl;
    cout << "e. Exit" << endl;
    cout << "choice: ";
    cin >> user_choice;

    bool is_adult = false;                              // assume user is not an adult
    string user_gender = "Gender is Unknown";           // default value
    string user_continent= "Continent is Unknown";

    while(user_choice != 'e' and user_choice != 'E')    // as long as user wants to 'play' | not enter 'e' or 'E'
    {
        if(user_choice == '1')
        {
            int valid_response = 0;                     // indicate user input is valid before ask if they are older of not
            bool valid_info = false;
            cout << "\n== Gender ==\n\nWhat is your gender (male/female/non-binary(nb)): ";   // instead of non-binary, user can put nb to shorten the input
            cin >> user_gender;

            if(user_gender == "male" or user_gender == "MALE")
            {
                user_gender = "male";                  // overwrite value
                valid_info = true;
            }

            else if(user_gender == "female" or user_gender == "FEMALE")
            {
                user_gender = "female";
                valid_info = true;
            }

            else if(user_gender == "non-binary" or user_gender == "Non-binary" or user_gender == "NON-BINARY" or user_gender == "nb")
            {
                user_gender = "non-binary";
                valid_info = true;
            }

            else
            {
               valid_info = false;
            }

            if(valid_info)
            {
                string young_or_old;
                cout << "Are you 18 years old or older (yes/no)? ";
                cin >> young_or_old;

                if(young_or_old == "yes" or young_or_old == "YES")
                {
                    valid_response += 1;
                }
                else if(young_or_old == "no" or young_or_old == "NO")
                {
                    valid_response = 0;
                } else                            // any unexpected input would be counted as invalid response
                {
                    valid_response = -1;
                }

              if(valid_response >= 0)
              {
                  string adult_or_not = eight_teen_older(valid_response);
                  cout << "\n[ Your are an/a " << adult_or_not << ' ' << user_gender << " ]" << endl;
              } else
              {
                  cout << "\n[ Invalid response ]" << endl;
              }

            } else
            {
                cout << "\n[ Invalid response ]" << endl;
            }

        }

        else if(user_choice == '2')
        {
            string user_cont;
            string temp_cont;                      // some continents have space in them - catch this with getline(cin, temp_cont)
            cout << "\n== Continent ==\n\nWhat continent are you from ?";
            cin >> user_cont;
            getline(cin, temp_cont);

            if(user_cont == "asia" or user_cont == "Asia" or user_cont == "ASIA")
            {
                user_continent = "asia";
            }

            else if(user_cont == "africa" or user_cont == "Africa" or user_cont == "AFRICA")
            {
                user_continent = "africa";
            }

            else if(user_cont + temp_cont == "north america" or user_cont + temp_cont == "North america" or user_cont + temp_cont == "North America" or user_cont + temp_cont == "NORTH AMERICA")
            {
                user_continent = "North America";
            }

            else if(user_cont + temp_cont == "south america" or user_cont + temp_cont == "South america" or user_cont + temp_cont == "South America" or user_cont + temp_cont == "SOUTH AMERICA")
            {
                user_continent = "South America";
            }

            else if(user_cont == "antarctica" or user_cont == "Antarctica" or user_cont == "ANTARCTICA")
            {
                user_continent = "Antarctica";
            }

            else if(user_cont == "europe" or user_cont == "Europe" or user_cont == "EUROPE")
            {
                user_continent = "Europe";
            }

            else if(user_cont == "australia" or user_cont == "Australia" or user_cont == "AUSTRALIA")
            {
                user_continent = "Australia";
            }

            else
            {
                user_continent = "";                             // make empty to indicate invalid response
            }


            if(user_continent.length() <= 3)                     // invalid response
            {
                cout << "\n[ Invalid response ]" << endl;
            } else
            {
                cout << "\n[ The continent you are from is " << user_continent << " ]" << endl;
            }

        }

        else
        {
            cout << "\n[ Invalid choice ]" << endl;
        }

        cout << "\n== Simple Information ==" << endl;
        cout << "1. Input Gender" << endl;
        cout << "2. Input Continent" << endl;
        cout << "e. Exit" << endl;
        cout << "choice: ";
        cin >> user_choice;

    }

    if(user_choice == 'e' or user_choice == 'E')
    {
        cout << "\n== Exit Program ==" << endl;
    }

    return 0;
}
