#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	FILE *fp;
	fp=fopen("session1/task3/text.txt","r");
	if(fp!=NULL)
	{
		printf("404\n");
		return 1;
	}
	char buf[1];
	bool b=false; //break
	int lines=1;
	int words=1;
	int chars=0;
	//int a;
	//scanf(" %i ",&a);
	int i=0;
	while(true)
	{
		b=fgets(buf,sizeof(buf),fp)==NULL;
		if(b) break;
		for(int i=0;i<sizeof(buf);i++)
		{
			chars++;
			if(buf[i]==' '||buf[i]=='\n') words++;
			if(buf[i]=='\n') lines++;
		}
		printf("i: %i",i);
		i++;
	}
	printf("Characters: %i\nWords:      %i\nLines:      %i\n",chars,words,lines);
	fclose(fp);
}