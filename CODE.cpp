
#include <iostream>
#include <iomanip>

using namespace std;

// Функция для определения високосного года
bool IsLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Функция для определения количества дней в месяце
int DaysInMonth(int month, int year) {
  if (month == 2) {
    return IsLeapYear(year) ? 29 : 28;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    return 30;
  } else {
    return 31;
  }
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
    int DayOfWeek = (1 + (13 * ( month + 12 * (month <= 2 ? 1 : 0) ) - 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;

    // Вывод дней месяца в календарь
    for (int SomeIndex = 0; SomeIndex < DayOfWeek; ++SomeIndex) {
      cout << "    ";
    }

    for (int day = 1; day <= DaysInMonth(month, year); ++day) {
      cout << setw(4) << day;
      if (++DayOfWeek > 6) {
        DayOfWeek = 0;
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
