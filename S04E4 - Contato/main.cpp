#include <iostream>
#include <sstream>


using namespace std;


int main()
{
  string line;
  getline(cin, line);

  stringstream ss(line);
  string palavra;
  ss >> palavra;
  ss << "joao";
  ss << "jose";
  cout << ss.str();
  return 0;
}

