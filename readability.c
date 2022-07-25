#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    //Prompt user for an input
    string inputText = get_string("Text:");
    //Initialize variables
    int numOfCharacters = 0;
    int numOfWords = 0;
    int numOfSentences = 0;

    for (int i = 0; i <= strlen(inputText); i++)
    {
        if (inputText[i] >= 'A'
            && inputText[i] <= 'Z')                               //if it is an uppercase character, add to the number of characters
        {
            numOfCharacters = numOfCharacters + 1;
        }
        else if (inputText[i] >= 'a'
                 && inputText[i] <= 'z')                          //if it is a lowercase character, add it to number of characters also
        {
            numOfCharacters = numOfCharacters + 1;
        }
        else if (inputText[i] == '!' || inputText[i] == '?' || inputText[i] == '.')   //If it is !, ?, or . then add to number of spaces
        {
            numOfSentences = numOfSentences + 1;
        }
        else if (inputText[i] == 32)                                                  //For spaces, add to number of words
        {
            numOfWords = numOfWords + 1;
        }
        else                                                                         //Or else, do nothing
        {

        }
    }
    float gradeLevel = 0.0588 * (100 * round(numOfCharacters) / round(numOfWords)) - 0.296 * (100 * round(numOfSentences) / round(
                           numOfWords)) - 15.8; // formula
    if (gradeLevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(gradeLevel));
    }
}
