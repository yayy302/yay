#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

string trim (const string& s)
{
  int start = 0;
  int end = s.length()-1;
  while (start<=end && isspace(s[start])) start ++;
  while (end>=start && isspace(s[end])) end--;
  return s.substr(start,end-start+1);
}

int main()
{
	string username = "nausheen";
	string username1;
	string password;
	string inputPassword;
	int attempts = 3;
	ifstream file ("password.txt");
	if (!file)
	{
		cout<<"Error"<<endl;
		return 1;
	}
	
	getline(file,password);
	password=trim(password);
	file.close();

	// login 
	cout<<"Enter username";
	cin>>username1;
 	
	while (attempts>0)
	{
		cout<<"Enter password";
		cin>>inputPassword;
		
		if (inputPassword == password && username == username1)
		{
			cout<<"Login successful!"<<endl;
			break;
		}
		else
		{
			attempts--;
			cout<<"incorrect password or username"<<endl;
		}
	}
	if (attempts == 0)
	{
		cout<<"Account blocked due to failed attempts"<<endl;
		return 0;
	}
	
	//update password
	cout << "Update password"<<endl;
	string newPassword;
	
	while (true)
	{
		cout<<"Enter new password (minimum 8 characters)";
		cin>> newPassword;
		if (newPassword.length()>=8)
		{
			password = newPassword;
			ofstream outFile("password.txt");
			outFile << password;
			outFile.close();
			cout<<"Password updated"<<endl;
			break;
		}
		else
		{
			cout << "password too short" <<endl;
		}
	}

	// login again 
	attempts = 3;
	while (attempts>0)
	{
		cout<<"Enter password";
		cin>>inputPassword;
		if (inputPassword == password)
		{
			cout <<"Login successful"<<endl;
			return 0;
		}
		else
		{
			attempts-=1;
		}
	}
	
	cout <<"incorrect attempts too many"<<endl;
	return 0;
}

		
		
	