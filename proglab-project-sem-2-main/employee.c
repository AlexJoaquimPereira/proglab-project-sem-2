#include <stdio.h>

typedef struct
{
	char ename[20];
	int eage;
	char designation[20];
	char address[50];
} employee;

int main()
{
	int n, i, nage, q = 0;
	char filename[20], t;
	FILE *fp;
	char ename[20], address[20], designation[20];
	int eage, p, s;

	employee *e;
	printf("\nEnter the number of employee records:\n");
	scanf("%d", &n);

	e = (employee *)malloc(n * sizeof(employee));

	printf("\nEnter the employee details:\n");
	for (i = 0; i < n; i++)
	{
		printf("\nEnter the filename to create: ");
		scanf("%s", filename);

		fp = fopen(filename, "w");

		printf("\nEnter employee name :");
		scanf("%s", e[i].ename);
		printf("\nEnter employee age :");
		scanf("%d", &e[i].eage);

		fprintf(fp, "%s %d", e[i].ename, e[i].eage);

		printf("\nContents written to file successfully.....\n");
		printf("\n-----------------------------------\n");
		fclose(fp);
	}

	do
	{
		printf("Enter your choice\n");
		printf("1. Enter employee details and display\n");
		printf("2. Edit eage and display the updated content\n");
		printf("3. Append address to a file & display appended content on screen\n");
		scanf("%d", &s);

		switch (s)
		{
			case 1:
			{
				printf("\nEnter filename to read contents: ");
				scanf("%s", filename);

				fp = fopen(filename, "r");
				if (fp == NULL)
				{
					printf("\nSorry filename does not exits...");
					goto p;
				}
				printf("\n----------------------------");
				printf("\nEmployee details is as follows:\n");
				if (q == 0)
				{
					fscanf(fp, "%s %d %s", ename, &eage, designation);
					printf("\nName:=%s  Age:=%d  Designation:=%s", ename, eage, designation);
				}
				else
				{
					fscanf(fp, "%s %d %s %s", ename, &eage, designation, address);
					printf("\nName:=%s  Age:=%d  Designation:=%s  Address=%s", ename, eage, designation, address);
				}
				fclose(fp);
				printf("\n------------------------------------");
				break;
			}
			case 2:
			{
				printf("\n\nEnter filename to update age: ");
				scanf("%s", filename);

				fp = fopen(filename, "r");
				fscanf(fp, "%s %d", ename, &eage);
				printf("\nEnter new age: ");
				scanf("%d", &nage);
				eage = nage;
				fclose(fp);

				fp = fopen(filename, "w");
				fprintf(fp, "%s %d", ename, eage);
				printf("\nContent updated to file successfully.....");
				fclose(fp);
				printf("\n------------------------------------");
				break;
			}
			case 3:
			{
				printf("\n\nEnter filename to append address: ");
				scanf("%s", filename);

				fp = fopen(filename, "a");
				printf("\nEnter address to append to the file: ");
				scanf("%s", address);
				fprintf(fp, " %s", address);
				printf("\nAddress appended to file successfully.........");
				q++;
				fclose(fp);
				break;
			}
		}
	p: fflush(stdin); // clears the standard i/o buffer

		printf("\n----------------------------");
		printf("\n\nEnter y to continue or n to quit\n");
		scanf("%c", &t);
	} while (t != 'n');

	return 0;
}

