#include <iostream> 
#include <fstream>
#include <string> 
using namespace std; 


void add_name_to_roster(string name, string *roster_ptr, int &size)
{
  string * new_ptr = nullptr;
  new_ptr = new string[size + 1];
  if (size == 0)
  {
    new_ptr[0] = name;
  }
  else
  {
    int i = 0;
    for(i = 0; i < size; i++)
    {
      new_ptr[i] = roster_ptr[i];
    }
    new_ptr[i] = name;
  }
  roster_ptr = new_ptr;
  size += 1;
  delete [] new_ptr;
  new_ptr = nullptr;
}


void save_roster_to_file(string *ptr, int size)
{
  string fileName;
  cout << "Enter file name: ";
  cin >> fileName;
  
  ofstream output_file;
  output_file.open(fileName);

  cout << "Now writing data to the file.\n";

  // Save roster to the file
  for(int i = 0; i < size; i++)
    {
      output_file << ptr[i] << endl;
    }
  output_file.close();
}


void read_in_existing_roster(string *roster_ptr, int &size)
{
  string name;
  string fileName;
  cout << "Enter file name: ";
  cin >> fileName;
  

  ifstream input_file;
  input_file.open(fileName);
  if(input_file)
  {
    cout << "Reading data from the file.\n";
    while(input_file >> name)
      {
        size++;
        add_name_to_roster(name, roster_ptr, size);
      }   
  }
  else
    cout << "Error opening file.\n";    // display error message 
}


void display_roster_in_alphabetical_order(string *ptr, int size)
{
  int min_index;
  string min_value;
  
  for(int start = 0; start < size - 1; start++)
    {
      min_index = start;
      min_value = ptr[start];
      for(int i = start + 1; i < size; i++)
    {
      if(ptr[i] < min_value)
      {
        min_value = ptr[i];
        min_index = i;
      }
    }
      swap(ptr[min_index], ptr[start]);
    }
}


void swap(string *ptr1, string *ptr2)
{
  string temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}


int search_roster_for_name(string name, string *roster_ptr, int size)
{
  display_roster_in_alphabetical_order(roster_ptr, size);
  int first = 0,
      last = size - 1,
     middle,
     position = -1;
  bool found = false;

  while (!found && first <= last)
    {
      middle = (first + last) / 2;
      if (roster_ptr[middle] == name)
      {
        found = true;
        position = middle;
      }
      else if(roster_ptr[middle] > name)
        last = middle - 1;
      else
        first = middle + 1;
    }
  return position;
}


void delete_current_roster(string *roster_ptr, int &size)
{
   size = 0;
   string *delete_ptr = nullptr;
   delete_ptr = new string[size];
   roster_ptr = delete_ptr;
  
   delete [] delete_ptr;
   delete_ptr = nullptr;
  
}
  

int main() { 
  string name;
  int user_choice,
      size = 0,
      position = 0;                        
  string *roster_ptr = nullptr;     // to dynamically allocate the roster array

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
      cout << "Main Roster Menu\n" 
           << "Please enter a number from the options below:\n" 
           << "1. Add names to the roster\n" 
           << "2. Save the roster to a text file\n"  
           << "3. Read in an existing roster from a text file\n" 
           << "4. Display all names\n" 
           << "5. Search the roster for a specific name\n" 
           << "6. Delete the current roster\n" 
           << "7. Quit\n"; 
      cin >> user_choice; 
       while(user_choice != 1 && user_choice != 2 && user_choice != 3 && user_choice != 4 && user_choice != 5 && user_choice != 6 && user_choice != 7)
      {
        cout << "Invalid input. Please enter a number from 1 to 7";
        cin >> user_choice;   
      }

      switch(user_choice) 
        { 
          case ADD_NAME: cout << "Enter name: \n";
                         cin >> name;
                         add_name_to_roster(name, roster_ptr, size); 
                    break; 
          case SAVE_TO_FILE: save_roster_to_file(roster_ptr, size); 
                    break; 
          case READ_IN: read_in_existing_roster(roster_ptr, size); 
                    break;
          case DISPLAY: display_roster_in_alphabetical_order(roster_ptr, size); 
                    break; 
          case SEARCH: cout << "Enter a name to search for: ";
                       cin  >> name;
                       position = search_roster_for_name(name, roster_ptr, size);
                       cout << "That name is found at position " << position << endl;
                    break; 
          case DELETE: delete_current_roster(roster_ptr, size); 
                    break; 
          case QUIT: cout << "Quitting program";
                    return 0; 
          default: cout << "Invalid input.";
        } 
      
         cout << "Select another option? Please enter 0 for no and 1 for yes.\n";
         cin >> user_choice;
      
    } while(user_choice != 0);

  
  // free dynamically allocated memory and set pointer to 0
  delete [] roster_ptr;
  roster_ptr = nullptr;
  return 0;
} 