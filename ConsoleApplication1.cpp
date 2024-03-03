#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


void listElements(vector<string> vector ) 
{
	int i =1;
	
	for (auto element : vector)
	{
		cout << i++ << "-)" << element << endl;
	}
}
bool IsInteger(string str)
{
	size_t len = str.length();
	for (size_t i = 0; i < len; i++)
	{
		if (isdigit(str[i]) == false)
		{
			return false;
		}
	}
	return true;
}
string taskgirdisi;
int main()
{
   cout << "----------------" << endl;
   cout << "    To do app   " << endl;
   cout << "----------------" << endl;
   cout << "" << endl;
   cout << "1-) Create a new task" << endl;
   cout << "2-) Delete a task" << endl;
   cout << "3-) Update a task" << endl;
   cout << "4-) Show curennt task" << endl;
   cout << "5-) End Program" << endl;
   cout << "" << endl;

   vector<string> taskgirdileri;
   fstream file;
   file.open("MyTodoList.txt", ios::in);
   if(file.is_open())
   {
	   string line;
	   while(getline(file,line))
	   {
		   taskgirdileri.push_back(line);
	   }
	   file.close();
   }
   

  while (true)
  {
	  
   cout << "" << endl;
   cout << "Please choose the process u want to do by number." << endl;
   cout << "" << endl;

   string secimstr;
   getline(cin, secimstr);
   if (IsInteger(secimstr) == false)
   {
	   cout << "Please enter a number.";
	   continue;
   }
   int secim = stoi(secimstr);

   if (secim == 1) // Bir task oluşturma
   {
	   cout << "Write your new task: " ;
	   getline(cin, taskgirdisi);
	   taskgirdileri.push_back(taskgirdisi);
	   continue;
   }
   if (secim == 2) // Bir task'i silme
   {
	   listElements(taskgirdileri);
	   cout << "Choose the task u want to delete by number:";
	   string silmesecimistr;
	   getline(cin, silmesecimistr);
	   if (IsInteger(silmesecimistr) == false)
	   {
		   cout << "Please Enter a number.";
		   continue;
	   }
	   int silmesecimi = stoi(silmesecimistr);
	   if (silmesecimi <1 || silmesecimi>taskgirdileri.size())
	   {
		   cout << "Invalid option." << endl;
		   continue;
	   }
	   taskgirdileri.erase(taskgirdileri.begin() + silmesecimi - 1);

	   continue;
   }
   if (secim == 3) // Bir task'i güncelleme
   {
	   cout << "Choose the task u want to update by number:" <<endl; 
	   listElements(taskgirdileri);
	   string updatesecimistr;
	   getline(cin, updatesecimistr);
	   if (IsInteger(updatesecimistr) == false)
	   {
		   cout << "Please Enter a number.";
		   continue;
	   }

	   int updatesecimi = stoi(updatesecimistr);
	   if (updatesecimi <1 || updatesecimi>taskgirdileri.size())
	   {
		   cout << "Invalid option." << endl;
		   continue;
	   }
	   cout << "Update task:";
	   string updatedtask;
	   getline(cin,updatedtask);
	   taskgirdileri[updatesecimi - 1 ] = updatedtask;
	   cout << "Successfully updated.";
	   continue;
   }	   
   if (secim == 4) //Taskleri görüntüleme
   {
	   listElements(taskgirdileri);
	   continue;
   }
   if (secim == 5) // Programı bitirme & çıkış
   {
	   cout << "Program kapaniyor \n";
	   file.open("MyTodoList.txt", ios::out); //out override için, app eklemek için
	   if (file.is_open())
	   {
		   int i = 0;
		   while (i < taskgirdileri.size())
		   {
			   file << taskgirdileri[i] << endl;
			   i++;


		   }
		   file.close();
		   return 0;
	   }
   }  
   

   cout << "Invalid option.";
   continue;

  }
}