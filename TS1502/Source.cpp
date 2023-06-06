//Name: ¼B®a¦¨
//Date: 2023/06/06
//Last Update: 2023/06/06
//Problem statement: demonstrating the basic library functions by using stl

#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

//function that sorts the library by title
void sortByTitle(vector<pair<pair<string, string>, int>> Library)
{
	map<pair<string, string>, vector<int>> editions; //map that stores the editions of each book
	for (int i = 0; i < Library.size(); i++)
	{
		//inserts the editions of each book into the map
		editions[make_pair(Library[i].first.first, Library[i].first.second)].push_back(Library[i].second);
	}
	
	for (int i = 0; i < Library.size(); i++)
	{
		for (int j = 0; j < Library.size() - 1; j++)
		{
			//sorts the library by title
			if (Library[j].first.first > Library[j + 1].first.first)
			{
				swap(Library[j], Library[j + 1]);
			}
			//if the titles are the same, sort by author
			if (Library[j].first.first == Library[j + 1].first.first)
			{
				if (Library[j].first.second > Library[j + 1].first.second)
				{
					swap(Library[j], Library[j + 1]);
				}
			}
		}
	}
	//prints the sorted library
	for (auto s : editions)
	{
		sort(s.second.begin(), s.second.end());
	}
	for (int i = 0; i < Library.size(); i++)
	{
		//if the seqences is the first, print out
		if (i == 0)
		{
			//print out title and author
			cout << "Title: " << Library[i].first.first << "\tAuthor: " << Library[i].first.second << "\tEdition: ";
			for (int j = 0; j < editions[make_pair(Library[i].first.first, Library[i].first.second)].size(); j++)
			{
				//if it is not the last edition, print out the edition and a comma
				if (j != editions[make_pair(Library[i].first.first, Library[i].first.second)].size() - 1) cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << ", ";
				else cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << "";
			}
			cout << "\n";
		}
		//else if the current seletion book is not equal to the first one, print out the book information
		else if (Library[i].first.first != Library[i - 1].first.first || Library[i].first.second != Library[i - 1].first.second)
		{
			//print out title and author
			cout << "Title: " << Library[i].first.first << "\tAuthor: " << Library[i].first.second << "\tEdition: ";
			for (int j = 0; j < editions[make_pair(Library[i].first.first, Library[i].first.second)].size(); j++)
			{
				//if it is not the last edition, print out the edition and a comma
				if (j != editions[make_pair(Library[i].first.first, Library[i].first.second)].size() - 1) cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << ", ";
				else cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << "";
			}
			cout << "\n";
		}
	}
}

//function that sorts the library by author
void sortByAuthor(vector<pair<pair<string, string>, int>> Library)
{
	map<pair<string, string>, vector<int>> editions; //map that stores the editions of each book
	for (int i = 0; i < Library.size(); i++)
	{
		//inserts the editions of each book into the map
		editions[make_pair(Library[i].first.first, Library[i].first.second)].push_back(Library[i].second);
	}
	//sorts the library by author
	for (int i = 0; i < Library.size(); i++)
	{
		for (int j = 0; j < Library.size() - 1; j++)
		{
			//sorts the library by author
			if (Library[j].first.second > Library[j + 1].first.second)
			{
				swap(Library[j], Library[j + 1]);
			}
			//if the authors are the same, sort by title
			if (Library[j].first.second == Library[j + 1].first.second)
			{
				if (Library[j].first.first > Library[j + 1].first.first)
				{
					swap(Library[j], Library[j + 1]);
				}
			}
		}
	}
	//sort the editions increasing
	for (auto s : editions)
	{
		sort(s.second.begin(), s.second.end());
	}
	for (int i = 0; i < Library.size(); i++)
	{
		//if the seqences is the first, print out
		if (i == 0)
		{
			//print out title and author
			cout << "Title: " << Library[i].first.first << "\tAuthor: " << Library[i].first.second << "\tEdition: ";
			for (int j = 0; j < editions[make_pair(Library[i].first.first, Library[i].first.second)].size(); j++)
			{
				//if it is not the last edition, print out the edition and a comma
				if (j != editions[make_pair(Library[i].first.first, Library[i].first.second)].size() - 1) cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << ", ";
				else cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << "";
			}
			cout << "\n";
		}
		//else if the current seletion book is not equal to the first one, print out the book information
		else if (Library[i].first.first != Library[i - 1].first.first || Library[i].first.second != Library[i - 1].first.second)
		{
			//print out title and author
			cout << "Title: " << Library[i].first.first << "\tAuthor: " << Library[i].first.second << "\tEdition: ";
			for (int j = 0; j < editions[make_pair(Library[i].first.first, Library[i].first.second)].size(); j++)
			{
				//if it is not the last edition, print out the edition and a comma
				if (j != editions[make_pair(Library[i].first.first, Library[i].first.second)].size() - 1) cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << ", ";
				else cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << "";
			}
			cout << "\n";
		}
	}
}

int main()
{
	vector<pair<pair<string, string>, int>> Library; //vector that stores the books in the library
	set<pair<pair<string, string>, int>> Books_in_Lib; //set that stores the books in the library
	string command; //string that stores the command
	while (getline(cin, command)) //while loop that reads in the commands line by line
	{
		string command1; //string that stores the first word of the command
		stringstream ss(command); //stringstream that stores the command
		ss >> command1; //reads in the first word of the command
		//if the command is Insert
		if (command1 == "Insert")
		{
			string title = "", author = ""; //strings that store the title and author of the book
			int edition = -1; //int that stores the edition of the book
			string readcomm; //string that stores the read in command
			do
			{
				ss >> readcomm; //reads in the next word of the command
				title += readcomm + " "; //adds the word to the title
			} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"'); //while loop that reads in the title
			do
			{
				ss >> readcomm; //reads in the next word of the command
				author += readcomm + " "; //adds the word to the author
			} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"'); //while loop that reads in the author
			ss >> edition; //reads in the edition
			if (title == "" || author == "" || edition == -1) //if the command is incomplete
			{
				cout << "Incomplete Command." << "\n"; //print out incomplete command
				continue; //continue to the next command
			}
			title.erase(0, 1); //erases the first character of the title
			title.erase(title.length() - 2, 2); //erases the last two characters of the title
			author.erase(0, 1); //erases the first character of the author
			author.erase(author.length() - 2, 2); //erases the last two characters of the author
			//if the book is not in the library
			if (Books_in_Lib.find(make_pair(make_pair(title, author), edition)) == Books_in_Lib.end())
			{
				//insert the book into the library
				Library.push_back(make_pair(make_pair(title, author), edition));
				//insert the book into the set
				Books_in_Lib.insert(make_pair(make_pair(title, author), edition));
				//print out the book information
				cout << "Insert " << author << "'s " << title << ", Edition: " << edition << "." << "\n";
			}
			//if the book is already in the library
			else
			{
				//print out the book information
				cout << "Datum already exist." << "\n";
			}
		}
		//else if the command is Delete
		else if (command1 == "Delete")
		{
			string command2 = ""; //string that stores the second word of the command
			string title = "", author = ""; //strings that store the title and author of the book
			int edition = -1; //int that stores the edition of the book
			ss >> command2; //reads in the second word of the command
			string readcomm; //string that stores the read in command
			do
			{
				ss >> readcomm; //reads in the next word of the command
				title += readcomm + " "; //adds the word to the title
			} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"'); //while loop that reads in the title
			do
			{
				ss >> readcomm; //reads in the next word of the command
				author += readcomm + " "; //adds the word to the author
			} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"'); //while loop that reads in the author
			ss >> edition; //reads in the edition
			if (title == "" || author == "") //if the command is incomplete
			{
				//print out incomplete command
				cout << "Incomplete Command." << "\n";
				continue; //continue to the next command
			}
			title.erase(0, 1); //erases the first character of the title
			title.erase(title.length() - 2, 2); //erases the last two characters of the title
			author.erase(0, 1); //erases the first character of the author
			author.erase(author.length() - 2, 2); //erases the last two characters of the author
			if (command2 == "Edition") //if the command is Delete Edition
			{
				if (edition == -1) //if the command is incomplete
				{
					cout << "Incomplete Command." << "\n"; //print out incomplete command
					continue;
				}
				//if the book is in the library
				if (Books_in_Lib.find(make_pair(make_pair(title, author), edition)) != Books_in_Lib.end())
				{
					//delete the book from the library
					for (int i = 0; i < Library.size(); i++)
					{
						//if the book is found
						if (Library[i].first.first == title && Library[i].first.second == author && Library[i].second == edition)
						{
							//delete the book from the library
							Library.erase(Library.begin() + i);
							//delete the book from the set
							Books_in_Lib.erase(make_pair(make_pair(title, author), edition));
							//print out the book information
							cout << "Delete " << author << "'s " << title << ", Edition: " << edition << "." << "\n";
							break; //break out of the for loop
						}
					}
				}
				else //if the book is not in the library
				{
					cout << "Datum doesn't exist." << "\n"; //print out the book information
				}
			}
			else if (command2 == "Book") //if the command is Delete Book
			{
				bool book_exists = false; //bool that stores whether the book exists
				for (int i = 0; i < Library.size(); i++) //for loop that goes through the library
				{
					if (Library[i].first.first == title && Library[i].first.second == author) //if the book is found
					{
						book_exists = true; //set book_exists to true
						Books_in_Lib.erase(make_pair(make_pair(title, author), Library[i].second)); //delete the book from the set
						Library.erase(Library.begin() + i); //delete the book from the library
						i--; //decrement i
					}
				}
				if (!book_exists) //if the book is not in the library
				{
					//print out the book information
					cout << "Book doesn't exist." << "\n";
				}
				else
				{
					//print out the book information
					cout << "Delete " << author << "'s " << title << "." << "\n";
				}
			}
			else //if the command is invalid
			{
				//print out unknown command
				cout << "Unknown Command." << "\n";
			}
		}
		//else if the command is Find
		else if (command1 == "Find")
		{
			string command2 = ""; //string that stores the second word of the command
			string title = "", author = ""; //strings that store the title and author of the book
			vector<int> editions; //vector that stores the editions of the book
			ss >> command2; //reads in the second word of the command
			if (command2 == "") //if the command is incomplete
			{
				cout << "Incomplete Command." << "\n";
				continue;
			}
			if (command2 == "Book") //if the command is Find Book
			{
				string title = "", author = ""; //strings that store the title and author of the book
				string readcomm; //string that stores the read in command
				do
				{
					ss >> readcomm; //reads in the next word of the command
					title += readcomm + " "; //adds the word to the title
				} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"'); //while loop that reads in the title
				do
				{
					ss >> readcomm; //reads in the next word of the command
					author += readcomm + " "; //adds the word to the author
				} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"'); //while loop that reads in the author
				if (title == "" || author == "") //if the command is incomplete
				{
					//print out incomplete command
					cout << "Incomplete Command." << "\n";
					continue; //continue to the next command
				}
				title.erase(0, 1); //erases the first character of the title
				title.erase(title.length() - 2, 2); //erases the last two characters of the title
				author.erase(0, 1); //erases the first character of the author
				author.erase(author.length() - 2, 2); //erases the last two characters of the author
				bool book_exists = false; //bool that stores whether the book exists
				for (int i = 0; i < Library.size(); i++) //for loop that goes through the library
				{
					//if the book is found
					if (Library[i].first.first == title && Library[i].first.second == author)
					{
						book_exists = true; //the book exists
						editions.push_back(Library[i].second); //push the book into editions
					}
				}
				if (book_exists) //if the book exists
				{
					//print out the book information
					cout << "Title: " << title << "\t" << "Author: " << author << "\t" << "Edition: ";
					sort(editions.begin(), editions.end()); //sort editions
					for (int i = 0; i < editions.size(); i++) //for loop that goes through editions
					{
						//if it is not the last edition, print out the edition and a comma
						if (i != editions.size() - 1) cout << editions[i] << ", ";
						else cout << editions[i]; //else print out the edition
					}
					cout << "\n";
				}
				else //if the book does not exist
				{
					//print out the book information
					cout << "Book doesn't exist." << "\n";
				}
			}
			else if (command2 == "Author") //if the command is Find Author
			{
				string readcomm; //string that stores the read in command
				do
				{
					ss >> readcomm; //reads in the next word of the command
					author += readcomm + " "; //adds the word to the author
				} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"'); //while loop that reads in the author
				vector<string> titles; //vector that stores the titles of the books
				if (author == "") //if the command is incomplete
				{
					cout << "Incomplete Command." << "\n"; //print out incomplete command
					continue; //continue to the next command
				}
				author.erase(0, 1); //erases the first character of the author
				author.erase(author.length() - 2, 2); //erases the last two characters of the author
				bool author_exists = false; //bool that stores whether the author exists
				for (int i = 0; i < Library.size(); i++) //for loop that goes through the library
				{
					if (Library[i].first.second == author) //if the author is found
					{
						author_exists = true; //the author exists
						titles.push_back(Library[i].first.first); //push the title into titles
					}
				}
				if (author_exists) //if the author exists
				{
					cout << author << "'s Books: "; //print out the author's books
					sort(titles.begin(), titles.end()); //sort titles
					for (int i = 0; i < titles.size(); i++) //for loop that goes through titles
					{
						//if it is not the last title, print out the title and a comma
						if (i != titles.size() - 1) cout << titles[i] << ", ";
						else cout << titles[i]; //else print out the title
					}
					cout << "\n";
				}
				else //if the author does not exist
				{
					cout << "No book found." << "\n";
				}
			}
			else //if the command is not Find Book or Find Author
			{
				cout << "Unknown Command." << "\n"; //print out unknown command
			}
		}
		else if (command1 == "Sort") //if the command is Sort
		{
			string command2 = "", command3 = ""; //strings that store the second and third words of the command
			ss >> command2 >> command3; //reads in the second and third words of the command
			if (command2 != "by") //if the second word is not by
			{
				//print out unknown command
				cout << "Unknown Command." << "\n";
				continue; //continue to the next command
			}
			else //if the second word is by
			{
				if (command3 == "Title") //if the third word is Title
				{
					sortByTitle(Library); //sort the library by title
				}
				else if (command3 == "Author") //if the third word is Author
				{
					sortByAuthor(Library); //sort the library by author
				}
				else //if the third word is not Title or Author
				{
					cout << "Unknown Command." << "\n"; //print out unknown command
					continue; //continue to the next command
				}
			}
		}
		else
		{
			cout << "Unknown Command." << "\n"; //print out unknown command
		}
	}
}