#include<stdio.h>

int main(void)
{
    char file_name[10]; char action;
    
    printf("write file name: \n");

    if(fgets(file_name, 10, stdin) == NULL)
    {
        printf("That file doesn't seem to exist\n");
        return 1;
    }
    if (sscanf(file_name, "%10s", file_name) != 1) //
    {                                              //I STILL DON'T COMPLETELY UNDERSTAND THIS!
        printf("Invalid file name!\n");            //     
        return 1;                                  //             
    }

    printf("write course of action for file: \n");
    scanf_s(" %c", &action);

    if(action == 'r')
    {
    char text[100000] = {0}; 

    FILE * file = fopen(file_name, "r") ;
        if(file == NULL)
        {
            printf("Error in opening file!\n");
            return 1;
        }

        fgets(text, sizeof(text), file);
        printf("%s", text);
        fclose(file);
    }
    
    else if(action == 'w')
    {
        char str[1000] = {0};

        FILE * file = fopen(file_name, "w") ;

        if(file == NULL)
        {
            printf("Error in opening file!\n");
            return 1;
        }
            printf("what do you want to write? :\n");
            fgets(str, sizeof(str), stdin);
            fprintf(file, "%s", str);
            fclose(file);
    }

    else if(action == 'a')
    {
        char text[100000]; 

        FILE * file = fopen(file_name, "a");
        if(file == NULL)
        {
            printf("Error in opening file!\n");
            return 1;
        }
            printf("What do you want to append? :\n");
            fgets(text, sizeof(text), stdin);
            fprintf(file, "%s", text);
            fclose(file);
    }
    else
    {
        printf("wrong action!");
        return 1;
    }
    return 0;
}

