#include <iostream>
using namespace std;

struct score_record{
  string name;
  unsigned long score;
  unsigned short month;
  unsigned short day;
  unsigned short year;
};

score_record *create_record(string person_name,unsigned long person_score, unsigned short date_month, unsigned short date_day, unsigned short date_year){
  score_record *score_ptr = nullptr;
  score_ptr = new score_record;
  score_ptr->name = person_name;
  score_ptr->score = person_score;
  score_ptr->month = date_month;
  score_ptr->day = date_day;
  score_ptr->year = date_year;
  return score_ptr;
}

int main() {
  // Current 10 high scores
string names[]          = {"Mic",   "ALD",   "BUT",   "Xav",   "KAT",   "sup",   "KAT",   "AAA",   "Jos",   "KAT"};
unsigned long scores[]  = {1321000, 1320950, 1318700, 1305500, 1228750, 1197050, 1188850, 1188800, 1148200, 1112100};
unsigned short months[] = {8,       8,       3,       7,       3,       10,      3,       3,       11,      2};
unsigned short days[]   = {30,      28,      10,      3,       19,      11,      12,      12,      16,      12};
unsigned short years[]  = {2010,    2010,    1988,    2001,    2022,    1994,    2022,    2022,    2021,    2022};

cout << "           TOP  10 SCORES         " << endl;
cout << "##################################" << endl;
cout << "  NAME         SCORE        DATE  " << endl;

score_record* high_scores[10];
  
for(int i = 0; i < 10; i++){
  high_scores[i] = create_record(names[i], scores[i], months[i], days[i], years[i]);
  
  cout << "   " << high_scores[i]->name << "      " << high_scores[i]->score << "     " << high_scores[i]->month << "/" << high_scores[i]->day << "/" << high_scores[i]->year << endl;
}
cout << "##################################" << endl;
return 0;
}