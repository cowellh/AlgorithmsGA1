#include <iostream>
#include <fstream>

using namespace std;

// int arrayCompare(ifstream* ) 

int main() {
  ifstream in_file;
  in_file.open("1.dat", ios::in | ios::binary);
  cout << in_file.read(in_file.seekg(0), sizeof( int)) << endl;
  int* test = in_file.seekg(0);
  cout << test << endl;
  int value;
  char* pmemory = ( char* ) &value;
  //char a[4];
  //in_file.read(a, 4);
  //cout << a << endl;


  in_file.read(pmemory, sizeof(int));
  cout << value << endl;
  in_file.read(pmemory, sizeof(int));
  cout << value << endl;
  in_file.read(pmemory, sizeof(int));
  cout << value << endl;
  in_file.read(pmemory, sizeof(int));
  cout << value << endl;
 //cout << a << endl;

//  in_file.get();
//  in_file.get();
//  int first = in_file.get();
//  int second = in_file.get();
//  int actual = first + second;
//  cout << actual << endl;

  cout << in_file.get() << endl;
  cout << in_file.get() << endl;
  cout << in_file.get() << endl;
  cout << in_file.get() << endl;
  cout << in_file.get() << endl;
  cout << in_file.get() << endl;
  cout << in_file.get() << endl;
  cout << in_file.get() << endl;
  cout << in_file.get() << endl;
  in_file.close();
  return 0;
}
