#include <iostream>
using namespace std;

void reverse() {
  int ch;
  cin.get(ch);
  if (ch != '\n')
      reverse();
  cout.put(ch);
}

int main()
{
    reverse();
}
