/************************************
 * Выполнил: Чепуштанов Е.П.        *
 * Группа: ПИ-231                   *
 * Блок 4, задание 2                *
 * https://onlinegdb.com/5G8Z5is8F  *
*************************************/

#include <iostream>
#include <iomanip>

using namespace std;

// Функция для определения високосного года
bool IsYearLeap(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Функция для определения количества дней в месяце
int DaysInMonth(int month, int year) {
  if (month == 2) {
    return IsYearLeap(year) ? 29 : 28;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    return 30;
  } else {
    return 31;
  }
}

// Skamoto's algorithm
// (If weeks were eight days, for example, what would change in this formula? Well, it would be mod 8, obviously.
// Also the y would need to be 5*y, because 365 % 8 == 5. Also the month table t[] would need adjusting. That's it.)
int DayOfWeek(int day, int month, int year) { 
  static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
  
  year -= month < 3;
  
  return ( year + year / 4 - year / 100 + year / 400 + t[month - 1] ) % 7; 
}

// Функция для вывода календаря на экран
void PrintCalendar(int year) {
  const string months[] = {
                           "January", "February", "March", "April", "May", "June", "July",
                           "August", "September", "October", "November", "December"
                          };

  cout << "Calendar for " << year << " year:" << endl;

  for (int month = 1; month <= 12; ++month) {
    cout << "\n-----------------------------\n"
         << "           " << months[month - 1] << "\n"
         << "-----------------------------\n"
         << " Mon Tue Wed Thu Fri Sat Sun\n";

    // Определение дня недели для 1 числа месяца
    int DayOfWeekTemp = DayOfWeek (1, month, year);

    // Monday - 0
    // Tuesday - 1
    // Wednesday - 2
    // Thursday - 3
    // Friday - 4
    // Saturday - 5
    // Sunday - 6

    // Вывод дней месяца в календарь
    for (int SomeIndex = 0; SomeIndex < DayOfWeekTemp; ++SomeIndex) {
      cout << "    ";
    }

    for (int day = 1; day <= DaysInMonth(month, year); ++day) {
      cout << setw(4) << day;
      
      if (++DayOfWeekTemp > 6) {
        DayOfWeekTemp = 0;
        
        cout << "\n";
      }
    }

    cout << "\n";
  }
}

int main() {
  int year;

  cout << "Enter the year: ";
  cin >> year;

  PrintCalendar(year);

  return 0;
}
