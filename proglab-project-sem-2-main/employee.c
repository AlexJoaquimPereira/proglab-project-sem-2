#include<stdio.h>

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
	char filename[24], t;
	FILE *fp;
	char ename[20], address[20], designation[20];
	int eage, p, s;

	employee *e;
	printf("Enter the number of employee records:\n");
	scanf("%d", &n);

	e = (employee *)malloc(n*sizeof(employee));

	printf("Enter the employee details:\n");
	for (i = 0; i < n; i++)
	{
		printf("Enter the filename to create: ");
		scanf("%s", filename);

		fp = fopen(filename, "w");
		printf("File created: %s\n", filename);
		printf("Enter employee name :");
		scanf("%s", e[i].ename);
		printf("Enter employee age :");
		scanf("%d", &e[i].eage);
		printf("Enter employee designation: ");
		scanf("%s", e[i].designation);

		fprintf(fp, "%s %d %s", e[i].ename, e[i].eage, e[i].designation);
		
		printf("Contents written to file successfully.....\n");
		printf("-----------------------------------\n");

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
					printf("Sorry filename does not exits...\n");
					goto p;
				}
				
				printf("Employee details is as follows:\n");
				if (q == 0)
				{
					fscanf(fp, "%s %d %s", ename, &eage, designation);
					printf("Name:=%s  Age:=%d  Designation:=%s\n", ename, eage, designation);
				}
				else
				{
					fscanf(fp, "%s %d %s %s", ename, &eage, designation, address);
					printf("Name:=%s  Age:=%d  Designation:=%s  Address:=%s\n", ename, eage, designation, address);
				}
				fclose(fp);
				printf("------------------------------------\n");
				break;
			}
			case 2:
			{
				printf("Enter filename to update age: ");
				scanf("%s", filename);

				fp = fopen(filename, "r");
				fscanf(fp, "%s %d", ename, &eage);
				printf("Enter new age: ");
				scanf("%d", &nage);
				eage = nage;
				fclose(fp);

				fp = fopen(filename, "w");
				fprintf(fp, "%s %d", ename, eage);
				printf("Content updated to file successfully.....\n");
				fclose(fp);
				printf("------------------------------------\n");
				break;
			}
			case 3:
			{
				printf("Enter filename to append address: ");
				scanf("%s", filename);

				fp = fopen(filename, "a");
				printf("Enter address to append to the file: ");
				scanf("%s", address);
				fprintf(fp, " %s", address);
				printf("Address appended to file successfully.........\n");
				q++;
				fclose(fp);
				break;
			}
		}
	p: fflush(stdin);

		printf("----------------------------\n");
		printf("Enter y to continue or n to quit\n");
		scanf("%c", &t);
	} while (t != 'n');

	return 0;
}

