#include <stdio.h>
#include <stdlib.h>
//#include <algorithm>
#include <string.h>
#include <stdbool.h>

#define MAX 10000

//typedef struct line
//{
//	int start;
//	int end;	
//};

//bool cmp(struct line a, struct line b)
//{
//	if (a.end < b.end)
//		return true;
//	else if (a.end == b.end && a.start > b.start)
//		return true;
//	return false;
//}

void sort(int *a, int l)
{
	int i,j;
	int v;
	for (i=0;i<l-1;i++)
		for(j=i+1;j<l;j++)
		{
			if(a[i]>a[j])
			{
				v=a[i];
				a[i]=a[j];
				a[j]=v;
			}
		}
}

int main()
{
	int num = 0;
	int i,j;
	int result = 0;
	//struct line lines[MAX];
	int begin[MAX];
	int end[MAX];

	scanf("%d",&num);
	for (i=0;i<num;i++){
		scanf("%d %d",&begin[i], &end[i]);
	}

	sort(end, num);

	//sort(lines, lines+num, cmp);

	for(i=0;i<num;i++)
		for (j=i+1;j<num;j++)
			if (end[i] > begin[j])
				result ++;

	printf("%d\n", result);

	return 0;
}