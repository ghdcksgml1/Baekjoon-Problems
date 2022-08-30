#include  <iostream>
using namespace std;

int main()
{
int ryt[8];
int asc = 0;
int des = 0;

for (int i = 0; i < 8; i++)
{
cin >> ryt[i];

if (ryt[i] == i + 1)
asc++;

else if (ryt[i] == 8 - i)
des++;

}

if (asc == 8)
cout << "ascending" << endl;
else if (des == 8)
cout << "descending" << endl;
else 
cout << "mixed" << endl;

return 0;
}