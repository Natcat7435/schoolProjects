#include <iostream>
#include <string>
using namespace std;

// functions that define the operations available to the user
void add_name_to_roster();
void save_roster_to_file();
void read_in_existing_roster();
void display_roster_in_alphabetical_order();
void search_roster_for_name();
void delete_current_roster();


int main() {
  string name;
  int user_choice;          

  // constants for menu choices
  const int ADD_NAME = 1,
  SAVE_TO_FILE = 2,
  READ_IN = 3,
  DISPLAY = 4,
  SEARCH = 5,
  DELETE = 6,
  QUIT = 7;

  // display the menu and get a choice
  do
    {
      cout << "Main Roster Menu"
           << "Please enter a number from the options below:"
           << "1. Add names to the roster"
           << "2. Save the roster to a text file" 
           << "3. Read in an existing roster from a text file"
           << "4. Display all names"
           << "5. Search the roster for a specific name"
           << "6. Delete the current roster"
           << "7. Quit";
      cin >> user_choice;

      switch(user_choice)
        {
          case ADD_NAME: add_name_to_roster();
                    break;
          case SAVE_TO_FILE: save_roster_to_file();
                    break;
          case READ_IN: read_in_existing_roster();
                    break;
          case DISPLAY: display_roster_in_alphabetical_order();
                    break;
          case SEARCH: search_roster_for_name();
                    break;
          case DELETE: delete_current_roster();
                    break;
          case QUIT: return 0;
        }
  
      cout << "Make another choice? Type '1' for Yes and '0' for No.";
      cin >> user_choice;
    }
    while(user_choice == '1');
  
}