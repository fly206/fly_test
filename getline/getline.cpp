#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>

using namespace std;

int main()
{
  string buff;
  ifstream infile;
  ofstream outfile;
  cout<<"Input file name"<<endl;
  //cin>>buff;
  getline(cin,buff);
  infile.open(buff.c_str());
  if(!infile)
    cout<<"error"<<buff<<endl;
  cout<<"Input outfile name"<<endl;
  cin>>buff;
  outfile.open(buff.c_str());
  while(getline(infile,buff))
    outfile<<buff<<endl;
  infile.close();
  outfile.close();
  return 0;
}
