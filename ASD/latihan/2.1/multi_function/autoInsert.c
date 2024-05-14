#include "../head.h"

void autoInsert()
{
	char choice;
	Node *findKey;
	int index = 0;
	do
	{
		alokasi();
		if (head == NULL || current->data <= head->data)
			awal();
		else
		{
			findKey = head;
			while (findKey->next != NULL && findKey->next->data <= current->data)
				findKey = findKey->next;
			if (findKey->next == NULL)
				akhir();
			else
			{
				current->next = findKey->next;
				findKey->next = current;
			}
		}
		tampil();
		printf("lagi? : ");
		choice = getchar();
	} while (choice == 'y' || choice == 'Y');
}
