#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Global variables
time_t t;

//Main Function
int main()
{
    char question[100];
    char response[1000];


    printf("Welcome to the Magic 8 Ball!\n");
    printf("What's your quandary?\n");

    scanf("%s", question);

    printf("Hmmm.... let's see.\n");

    //Bucket of answers
    FILE *possibles;
    int responseNo;

    //Get number
    responseNo = randomMaker();

    //Retrieves line
    int count = 0;
    char line[1000];

    possibles = fopen("responses.txt", "r");

    if (!possibles){
        return 1;
    }

    while (fgets(line,1000, possibles)!=NULL){
        if (count == responseNo){
            printf("%s",line);
            return 0;
        }
        else {
            count++;
        }
    }

    fclose(possibles);
    return 0;
}

//Generates the random number
int randomMaker()
{
    int number;

    srand((unsigned) time(&t));
    number = rand()%(10 - 0 + 1);

    return number;
}

