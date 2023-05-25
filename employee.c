#include<stdio.h>

typedef struct
{
	char ename[20];
	int eage;
	char designation[20];
}employee;

int main()
{
	int n,i,nage,q=0;
	char filename[10],t;
	FILE *fp;
	char cname[10],addr[10];
	int cage,p;
	
	struct student *s;
	printf("\nEnter the number of student records:\n");
	scanf("%d",&n);
	
	s=(struct student*)malloc(n*sizeof(struct student));
	
	printf("\nEnter the student details:\n");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the filename to create: ");
		scanf("%s",filename);
		
		fp=fopen(filename,"w");
		
		printf("\nEnter student name :");
		scanf("%s",s[i].name);
		printf("\nEnter student age :");
		scanf("%d",&s[i].age);
		
		fprintf(fp,"%s %d",s[i].name,s[i].age);
		
		printf("\nContents written to file successfully.....\n");
		printf("\n-----------------------------------\n");
		fclose(fp);
	}
	
	do
	{
	printf("\nEnter filename to read contents: ");
	scanf("%s",filename);
	
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("\nSorry filename does not exits...");
		goto p;
	}
	printf("\n----------------------------");
	printf("\nStudent details is as follows:\n");
	if(q==0)
	{
	fscanf(fp,"%s %d",cname,&cage);
	printf("\nName:=%s  Age:=%d",cname,cage);
	}
	else
	{
		fscanf(fp,"%s %d %s",cname,&cage,addr);
		printf("\nName:=%s  Age:=%d Address=%s",cname,cage,addr);
	}
	fclose(fp);

	printf("\n------------------------------------");
	printf("\n\nEnter filename to update age: ");
	scanf("%s",filename);
	
	fp=fopen(filename,"r");
	fscanf(fp,"%s %d",cname,&cage);
	printf("\nEnter new age: ");
	scanf("%d",&nage);
	cage=nage;
	fclose(fp);
	
	fp=fopen(filename,"w");
	fprintf(fp,"%s %d",cname,cage);
	printf("\nContent updated to file successfully.....");
	fclose(fp);


	printf("\n------------------------------------");
	printf("\n\nEnter filename to append address: ");
	scanf("%s",filename);
	
	fp=fopen(filename,"a");
	printf("\nEnter address to append to the file: ");
	scanf("%s",addr);
	fprintf(fp," %s",addr);
	printf("\nAddress appended to file successfully.........");
	q++;t
	fclose(fp);


	p: fflush(stdin);  // clears the standard i/o buffer
	
	printf("\n----------------------------");
	printf("\n\nEnter y to continue or n to quit\n");
	scanf("%c",&t);
	}while(t!='n');
	return 0;
}
