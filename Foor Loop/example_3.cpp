#include <iostream>
using namespace std;

int main() {
  int numOfSheep=500;
  cout << "How many sheep do you need to count before falling asleep? (1-500):";
  scanf("%d", &numOfSheep);
  for (int i = 0; i <= numOfSheep; i++) {
    cout << "You have counted " << i << " sheep." << endl;
  } 
    cout << "Good night! Have a restful sleep." << endl; 
}
