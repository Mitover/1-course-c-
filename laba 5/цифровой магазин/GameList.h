#define _CRT_SECURE_NO_WARNINGS
#include"Game.h"
using namespace std;

struct Node
{
	Node *next, *prev;
	Game data;
};

class List
{
private:
	Node *Head, *Tail;
public:
	List()
	{
		Head = nullptr;
	}
	void ShowAll(bool por)
	{
		if (por)
		{
			Node *tmp = Head;
			while (tmp != nullptr)
			{
				tmp->data.ShortInfo();
				tmp = tmp->next;
			}
		}
		else
		{
			Node *tmp = Tail;
			while (tmp != nullptr)
			{
				tmp->data.ShortInfo();
				tmp = tmp->prev;
			}
		}
	}


	Game FindGame(char* FGame)
	{
		Node *tmp = Head;
		while (tmp != nullptr)
		{
			if (strcmp(tmp->data.GetName(),FGame) == 0)
			{
				return tmp->data;
			}
			else
			{
				tmp = tmp->next;
			}
		}
	}
	
	void AddNewGame()
	{
		Node *tmp = new Node;
		tmp->next = nullptr;
		tmp->data.SetName();
		tmp->data.SetPrice();
		tmp->data.SetDevname();
		tmp->data.SetRelease();
		tmp->data.SetTags();
		tmp->data.SetLanguage();
		tmp->data.SetDescription();
		if (Head != nullptr)
		{
			tmp->prev = Tail;
			Tail->next = tmp;
			Tail = tmp;
		}
		else
		{
			tmp->prev = nullptr;
			Head = Tail = tmp;
		}
	}
	
	void Sort_by_Name()
	{
		Node *tmp = Head;
		bool relocate = true;
		while (relocate)
		{
			relocate = false;
			while (tmp->next != nullptr)
			{
				if (strcmp(tmp->data.GetName(), tmp->next->data.GetName()) > 0)
				{
					relocate = true;
					swap(tmp->data, tmp->next->data);
				}
				tmp = tmp->next;
			}
		}
		tmp = Head;
	}
	
	void Sort_by_Price()
	{
		Node *tmp = Head;
		bool relocate = true;
		while (relocate)
		{
			relocate = false;
			while (tmp->next != nullptr)
			{
				if (tmp->data.GetPrice() > tmp->next->data.GetPrice())
				{
					relocate = true;
					swap(tmp->data, tmp->next->data);

				}
				tmp = tmp->next;
			}
		}
		tmp = Head;

	}
	
	void Sort_by_date()
	{
		Node *tmp = Head;
		bool relocate = true;
		while (relocate)
		{
			relocate = false;
			while (tmp->next != nullptr)
			{
				if (tmp->data.GetRelease() > tmp->next->data.GetRelease())
				{
					relocate = true;
					swap(tmp->data, tmp->next->data);
				}
				tmp = tmp->next;
			}
		}
		tmp = Head;
	}

	void Show_by_Lang(int len, bool por)
	{
		if (por)
		{
			Node *tmp = Head;
			while (tmp != nullptr)
			{
				if (tmp->data.IsHereLang(len))
				{
					tmp->data.ShortInfo();
				}
				tmp = tmp->next;
			}
		}
		else
		{
			Node *tmp = Tail;
			while (tmp != nullptr)
			{
				if (tmp->data.IsHereLang(len))
				{
					tmp->data.ShortInfo();
				}
				tmp = tmp->prev;
			}
		}
		
	}

	void Show_by_Tag(int tag, bool por)
	{
		if (por)
		{
			Node *tmp = Head;
			while (tmp != nullptr)
			{
				if (tmp->data.IsHereTag(tag))
				{
					tmp->data.ShortInfo();
				}
				tmp = tmp->next;
			}
		}
		else
		{
			Node *tmp = Tail;
			while (tmp != nullptr)
			{
				if (tmp->data.IsHereTag(tag))
				{
					tmp->data.ShortInfo();
				}
				tmp = tmp->prev;
			}
		}
		
	}
};

