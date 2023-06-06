#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void sortByTitle(vector<pair<pair<string, string>, int>> Library)
{
	map<pair<string, string>, vector<int>> editions;
	for (int i = 0; i < Library.size(); i++)
	{
		editions[make_pair(Library[i].first.first, Library[i].first.second)].push_back(Library[i].second);
	}
	for (int i = 0; i < Library.size(); i++)
	{
		for (int j = 0; j < Library.size() - 1; j++)
		{
			if (Library[j].first.first > Library[j + 1].first.first)
			{
				swap(Library[j], Library[j + 1]);
			}
			if (Library[j].first.first == Library[j + 1].first.first)
			{
				if (Library[j].first.second > Library[j + 1].first.second)
				{
					swap(Library[j], Library[j + 1]);
				}
			}
		}
	}
	for (auto s : editions)
	{
		sort(s.second.begin(), s.second.end());
	}
	for (int i = 0; i < Library.size(); i++)
	{
		if (i == 0)
		{
			cout << "Title: " << Library[i].first.first << "\tAuthor: " << Library[i].first.second << "\tEdition: ";
			for (int j = 0; j < editions[make_pair(Library[i].first.first, Library[i].first.second)].size(); j++)
			{
				if (j != editions[make_pair(Library[i].first.first, Library[i].first.second)].size() - 1) cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << ", ";
				else cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << "";
			}
			cout << "\n";
		}
		else if (Library[i].first.first != Library[i - 1].first.first || Library[i].first.second != Library[i - 1].first.second)
		{
			cout << "Title: " << Library[i].first.first << "\tAuthor: " << Library[i].first.second << "\tEdition: ";
			for (int j = 0; j < editions[make_pair(Library[i].first.first, Library[i].first.second)].size(); j++)
			{
				if (j != editions[make_pair(Library[i].first.first, Library[i].first.second)].size() - 1) cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << ", ";
				else cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << "";
			}
			cout << "\n";
		}
	}
}

void sortByAuthor(vector<pair<pair<string, string>, int>> Library)
{
	map<pair<string, string>, vector<int>> editions;
	for (int i = 0; i < Library.size(); i++)
	{
		editions[make_pair(Library[i].first.first, Library[i].first.second)].push_back(Library[i].second);
	}
	for (int i = 0; i < Library.size(); i++)
	{
		for (int j = 0; j < Library.size() - 1; j++)
		{
			if (Library[j].first.second > Library[j + 1].first.second)
			{
				swap(Library[j], Library[j + 1]);
			}
			if (Library[j].first.second == Library[j + 1].first.second)
			{
				if (Library[j].first.first > Library[j + 1].first.first)
				{
					swap(Library[j], Library[j + 1]);
				}
			}
		}
	}
	for (auto s : editions)
	{
		sort(s.second.begin(), s.second.end());
	}
	for (int i = 0; i < Library.size(); i++)
	{
		if (i == 0)
		{
			cout << "Title: " << Library[i].first.first << "\tAuthor: " << Library[i].first.second << "\tEdition: ";
			for (int j = 0; j < editions[make_pair(Library[i].first.first, Library[i].first.second)].size(); j++)
			{
				if (j != editions[make_pair(Library[i].first.first, Library[i].first.second)].size() - 1) cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << ", ";
				else cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << "";
			}
			cout << "\n";
		}
		else if (Library[i].first.first != Library[i - 1].first.first || Library[i].first.second != Library[i - 1].first.second)
		{
			cout << "Title: " << Library[i].first.first << "\tAuthor: " << Library[i].first.second << "\tEdition: ";
			for (int j = 0; j < editions[make_pair(Library[i].first.first, Library[i].first.second)].size(); j++)
			{
				if (j != editions[make_pair(Library[i].first.first, Library[i].first.second)].size() - 1) cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << ", ";
				else cout << editions[make_pair(Library[i].first.first, Library[i].first.second)][j] << "";
			}
			cout << "\n";
		}
	}
}

int main()
{
	vector<pair<pair<string, string>, int>> Library;
	set<pair<pair<string, string>, int>> Books_in_Lib;
	string command;
	while (getline(cin, command))
	{
		string command1;
		stringstream ss(command);
		ss >> command1;
		if (command1 == "Insert")
		{
			string title = "", author = "";
			int edition = -1;
			string readcomm;
			do
			{
				ss >> readcomm;
				title += readcomm + " ";
			} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"');
			do
			{
				ss >> readcomm;
				author += readcomm + " ";
			} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"');
			ss >> edition;
			if (title == "" || author == "" || edition == -1)
			{
				cout << "Incomplete Command." << "\n";
				continue;
			}
			title.erase(0, 1);
			title.erase(title.length() - 2, 2);
			author.erase(0, 1);
			author.erase(author.length() - 2, 2);
			if (Books_in_Lib.find(make_pair(make_pair(title, author), edition)) == Books_in_Lib.end())
			{
				Library.push_back(make_pair(make_pair(title, author), edition));
				Books_in_Lib.insert(make_pair(make_pair(title, author), edition));
				cout << "Insert " << author << "'s " << title << ", Edition: " << edition << "." << "\n";
			}
			else
			{
				cout << "Datum already exist." << "\n";
			}
		}
		else if (command1 == "Delete")
		{
			string command2 = "";
			string title = "", author = "";
			int edition = -1;
			ss >> command2;
			string readcomm;
			do
			{
				ss >> readcomm;
				title += readcomm + " ";
			} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"');
			do
			{
				ss >> readcomm;
				author += readcomm + " ";
			} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"');
			ss >> edition;
			if (title == "" || author == "")
			{
				cout << "Incomplete Command." << "\n";
				continue;
			}
			title.erase(0, 1);
			title.erase(title.length() - 2, 2);
			author.erase(0, 1);
			author.erase(author.length() - 2, 2);
			if (command2 == "Edition")
			{
				if (edition == -1)
				{
					cout << "Incomplete Command." << "\n";
				}
				if (Books_in_Lib.find(make_pair(make_pair(title, author), edition)) != Books_in_Lib.end())
				{
					for (int i = 0; i < Library.size(); i++)
					{
						if (Library[i].first.first == title && Library[i].first.second == author && Library[i].second == edition)
						{
							Library.erase(Library.begin() + i);
							Books_in_Lib.erase(make_pair(make_pair(title, author), edition));
							cout << "Delete " << author << "'s " << title << ", Edition: " << edition << "." << "\n";
							break;
						}
					}
				}
				else
				{
					cout << "Datum doesn't exist." << "\n";
				}
			}
			else if (command2 == "Book")
			{
				bool book_exists = false;
				for (int i = 0; i < Library.size(); i++)
				{
					if (Library[i].first.first == title && Library[i].first.second == author)
					{
						book_exists = true;
						Books_in_Lib.erase(make_pair(make_pair(title, author), Library[i].second));
						Library.erase(Library.begin() + i);
						i--;
					}
				}
				if (!book_exists)
				{
					cout << "Book doesn't exist." << "\n";
				}
				else
				{
					cout << "Delete " << author << "'s " << title << "." << "\n";
				}
			}
			else
			{
				cout << "Unknown Command." << "\n";
			}
		}
		else if (command1 == "Find")
		{
			string command2 = "";
			string title = "", author = "";
			vector<int> editions;
			ss >> command2;
			if (command2 == "")
			{
				cout << "Incomplete Command." << "\n";
				continue;
			}
			if (command2 == "Book")
			{
				string title = "", author = "";
				string readcomm;
				do
				{
					ss >> readcomm;
					title += readcomm + " ";
				} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"');
				do
				{
					ss >> readcomm;
					author += readcomm + " ";
				} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"');
				if (title == "" || author == "")
				{
					cout << "Incomplete Command." << "\n";
					continue;
				}
				title.erase(0, 1);
				title.erase(title.length() - 2, 2);
				author.erase(0, 1);
				author.erase(author.length() - 2, 2);
				bool book_exists = false;
				for (int i = 0; i < Library.size(); i++)
				{
					if (Library[i].first.first == title && Library[i].first.second == author)
					{
						book_exists = true;
						editions.push_back(Library[i].second);
					}
				}
				if (book_exists)
				{
					cout << "Title: " << title << "\t" << "Author: " << author << "\t" << "Edition: ";
					sort(editions.begin(), editions.end());
					for (int i = 0; i < editions.size(); i++)
					{
						if (i != editions.size() - 1) cout << editions[i] << ", ";
						else cout << editions[i];
					}
					cout << "\n";
				}
				else
				{
					cout << "Book doesn't exist." << "\n";
					continue;
				}
			}
			else if (command2 == "Author")
			{
				string readcomm;
				do
				{
					ss >> readcomm;
					author += readcomm + " ";
				} while (!ss.eof() && readcomm[readcomm.length() - 1] != '\"');
				vector<string> titles;
				if (author == "")
				{
					cout << "Incomplete Command." << "\n";
					continue;
				}
				author.erase(0, 1);
				author.erase(author.length() - 2, 2);
				bool author_exists = false;
				for (int i = 0; i < Library.size(); i++)
				{
					if (Library[i].first.second == author)
					{
						author_exists = true;
						titles.push_back(Library[i].first.first);
					}
				}
				if (author_exists)
				{
					cout << author << "'s Books: ";
					sort(titles.begin(), titles.end());
					for (int i = 0; i < titles.size(); i++)
					{
						if (i != titles.size() - 1) cout << titles[i] << ", ";
						else cout << titles[i];
					}
					cout << "\n";
				}
				else
				{
					cout << "No book found." << "\n";
				}
			}
			else
			{
				cout << "Unknown Command." << "\n";
			}
		}
		else if (command1 == "Sort")
		{
			string command2 = "", command3 = "";
			ss >> command2 >> command3;
			if (command2 != "by")
			{
				cout << "Unknown Command." << "\n";
				continue;
			}
			else
			{
				if (command3 == "Title")
				{
					sortByTitle(Library);
				}
				else if (command3 == "Author")
				{
					sortByAuthor(Library);
				}
				else
				{
					cout << "Unknown Command." << "\n";
					continue;
				}
			}
		}
		else
		{
			cout << "Unknown Command." << "\n";
		}
	}
}