#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10000

int cmp(const void *a, const void *b){
    return *(int*)a-*(int *)b;
}

int main()
{
   // char *input=(char *)malloc(MAX * sizeof(char));
  //  if (NULL == input)
   // {
   //     return 0;
   // }
    char str[MAX];
    int sum[26]={0};
    int value[26];
    int i=0;
    int perfect = 0;
    int tmp;

    //gets(input);
    scanf("%s", str);

    for (;i<26;i++)
        value[i] = i+1;

    i = 0;
    while (str[i] != '\0')
    {
      //  sum[(int)*input-32]++;
        tmp = tolower(str[i])-97;
       // printf("%d\n",tmp);
        sum[tmp]++;
        i++;
        //input++;
    }
    
    qsort(sum, 26, sizeof(sum[0]), cmp);

    for (i=0;i<26;i++){
        //printf("%d\n ", sum[i]);
        perfect += value[i]*sum[i];
    }

    printf("%d\n", perfect);
  //  free(input);
  //  input = NULL;

    return 0;
}