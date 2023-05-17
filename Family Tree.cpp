#include <iostream>
#include <string>
using namespace std;

int MaxFamilyMemmbers = 10; 

int main() {
string familyMembers[MaxFamilyMemmbers];
string relationship[MaxFamilyMemmbers];

    int numFamilyMembers;
  printf ("Enter the number of family members you want to add: ");
  cin >> numFamilyMembers;

  if (numFamilyMembers > MaxFamilyMemmbers) {
    printf ("10 is the maximum number of family members allowed. \n");
    }
  for (int i = 0; i < numFamilyMembers; i++) {
    cout << "Enter the name of family member " << i + 1 << ": ";
    cin >> familyMembers[i];
    cout << "Enter the relationship to you: ";
    cin >> relationship[i];
  }
  
  printf("\nFamily Tree:\n");
    for (int i = 0; i < numFamilyMembers; i++) {
      cout << familyMembers[i] << " - " << relationship[i] << endl;
    }
}
