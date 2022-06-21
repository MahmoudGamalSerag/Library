#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NULL 0
#define MAX 60
struct book { int id;
      char name[100];
      int cuantity;};
       struct book arr[10];
  int id,cuantity;
      char name[50];
void create_library();
void insert();
void present();
void search_by_id();
void search_by_name();
void del();
void sorted_by_name();
int main()
{
char c;int menuo;
do
{
    printf("enter 1 to create new library(it will delete this library)\n");
    printf("enter 2 to add a book\nenter 3 to delete a book\n");
    printf("enter 4 to search for a book by id\nenter 5 to search for a book by name\n");
    printf("enter 6 to present library\nenter 7 to present library sorted by name:\n");
    scanf("%d",&menuo);
    switch(menuo){
    case 1:
        create_library();
        break;
    case 2:
        insert();
        break;
    case 3:
        del();
        break;
    case 4:
        search_by_id();
        break;
    case 5:
        search_by_name();
        break;
    case 6:
        present();
        break;
    case 7:
        sorted_by_name();
        break;
    default:
        printf("sorry wrong number\n");
    }
    printf("\n\nenter 'Y' to choose again or 'N' to end:");
    scanf(" %c",&c);
}while(c=='y'||c=='Y');
printf("you ended the program");
    return 0;
}
create_library()
{
    FILE* library;
    library=fopen("library.text","w");
    if (library==NULL)
        printf("cant create library");
    else
    {
            printf("enter eof or enter id, name and cuantity:\n");
            scanf("%d %s %d",&id,name,&cuantity);
        while(!feof(stdin))
        {
            fprintf(library,"%d %s %d\n",id,name,cuantity);
            printf("enter id name cuantity");
            scanf("%d %s %d",&id,name,&cuantity);
        }
    }
    fclose(library);
}
void insert()
{
FILE* insert;
 insert=fopen("library.text","a");
 if (insert== NULL)
    printf("error to create file");
 else {
        printf("enter id  name  cuantity\n");
        scanf("%d", &id);
        scanf("%s",name);
        scanf("%d", &cuantity);
        fprintf(insert,"%d %s %d\n",id,name,cuantity);
    }
    fclose(insert);
}
void present()
{
    FILE* library;
         if ( ( library = fopen( "library.text", "r" ) ) == NULL )
            printf("couldnt find file");
         else
         {printf("the list in not order:\n");
         fscanf(library,"%d%s%d",&id,name,&cuantity);
           while(!feof(library))
              {
                  printf("%d %s %d\n",id,name,cuantity);
                  fscanf(library,"%d%s%d",&id,name,&cuantity);

              }
              fclose(library);
         }
}

void del()
    {
        int i=0,m;
    FILE* library;
         if ( ( library = fopen( "library.text", "r" ) ) == NULL )
            printf("couldnt find file");
         else
         {
             printf("this is the library\n\n");
         fscanf(library,"%d%s%d",&id,name,&cuantity);
           while(!feof(library))
              {
                  arr[i].id=id;
                  strcpy(arr[i].name,name);
                  arr[i].cuantity=cuantity;
                  printf("%d %s %d\n",id,name,cuantity);
                  fscanf(library,"%d%s%d",&id,name,&cuantity);
                  i++;

              }
              fclose(library);
              printf("\nenter the book id to delete:");
              scanf("%d",&m);
         }
         library=fopen("library.text","w");
         for (int k=0;k<i;k++)
         {
             if (arr[k].id!=m)
                fprintf(library,"%d %s %d\n",arr[k].id,arr[k].name,arr[k].cuantity);
         }
         fclose(library);
    }
    void search_by_id()
    {
        int i=0,m,search=0;
    FILE* library;
         if ( ( library = fopen( "library.text", "r" ) ) == NULL )
            printf("couldnt find file");
         else
         {
         fscanf(library,"%d%s%d",&id,name,&cuantity);
           while(!feof(library))
              {
                  arr[i].id=id;
                  strcpy(arr[i].name,name);
                  arr[i].cuantity=cuantity;
                  fscanf(library,"%d%s%d",&id,name,&cuantity);
                  i++;

              }
              fclose(library);
              printf("enter the book id to search:");
              scanf("%d",&m);
         }
         for (int k=0;k<6;k++)
         {
             if (arr[k].id==m)
             {
                printf("%d %s %d\n",arr[k].id,arr[k].name,arr[k].cuantity);
                search++;
                break;
             }

         }
         if (search==0)
            printf("not found");


    }
    void sorted_by_name()
    {
        int i=0,pass,tempid=0,tempcuantity=0;
char temp[20];

    FILE* library;
         if ( ( library = fopen( "library.text", "r" ) ) == NULL )
            printf("couldnt find file");
         else
         {
         fscanf(library,"%d%s%d",&id,name,&cuantity);
           while(!feof(library))
              {
                  arr[i].id=id;
                  strcpy(arr[i].name,name);
                  arr[i].cuantity=cuantity;
                  fscanf(library,"%d%s%d",&id,name,&cuantity);
                  i++;

              }
         }
          for (pass=1;pass<i;pass++)
          {
              for (int k=0;k<i-pass;k++)
                if (strcmp(arr[k].name,arr[k+1].name)>0)
              {
                strcpy(temp,arr[k].name);tempid=arr[k].id;tempcuantity=arr[k].cuantity;
                strcpy(arr[k].name,arr[k+1].name);arr[k].id=arr[k+1].id;arr[k].cuantity=arr[k+1].cuantity;
                strcpy(arr[k+1].name,temp);arr[k+1].id=tempid;arr[k+1].cuantity=tempcuantity;
              }
          }
          printf("the list sorted by name:\n");
          for (int m=0;m<i;m++)
          {
              printf("%d %s %d\n",arr[m].id,arr[m].name,arr[m].cuantity);
          }
          fclose(library);
}
void search_by_name()
{
    int i=0,pass,tempid=0,tempcuantity=0,ctr=0;
char searc[20];
char temp[20];

    FILE* library;
         if ( ( library = fopen( "library.text", "r" ) ) == NULL )
            printf("couldnt find file");
         else
         {
         fscanf(library,"%d%s%d",&id,name,&cuantity);
           while(!feof(library))
              {
                  arr[i].id=id;
                  strcpy(arr[i].name,name);
                  arr[i].cuantity=cuantity;
                  fscanf(library,"%d%s%d",&id,name,&cuantity);
                  i++;

              }
              fclose(library);
         }
          for (pass=1;pass<i;pass++)
          {
              for (int k=0;k<i-pass;k++)
                if (strcmp(arr[k].name,arr[k+1].name)>0)
              {
                strcpy(temp,arr[k].name);tempid=arr[k].id;tempcuantity=arr[k].cuantity;
                strcpy(arr[k].name,arr[k+1].name);arr[k].id=arr[k+1].id;arr[k].cuantity=arr[k+1].cuantity;
                strcpy(arr[k+1].name,temp);arr[k+1].id=tempid;arr[k+1].cuantity=tempcuantity;
              }
          }
          int low=0,high=i-1,middle;
          printf("enter name of book:");scanf("%s",searc);

          while(low<=high)
          {
              middle=(low+high)/2;
              if(strcmp(searc,arr[middle].name)==0)
              {
                  printf("the book you search for is:\n");
                  printf("%d %s %d",arr[middle].id,arr[middle].name,arr[middle].cuantity);
                  ctr++;
                  break;
              }
              else if (strcmp(searc,arr[middle].name)<0)
                      {
                         high=middle-1;
                      }
              else
                {
                    low=middle+1;
                }
          }
          if(ctr==0)
            printf("not found");
}
