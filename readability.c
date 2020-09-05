#include <stdio.h>
#include <cs50.h>
#include <math.h>

//the prototype
int countLetters(string text);
int countWords(string text);
int countSentences(string text);

//the main function
int main()
{
    //user input
    string text = get_string("Text: ");

    int letters = countLetters(text);
    int words = countWords(text);
    int sentences = countSentences(text);

    //Coleman-Liau index test
    float L = (float)letters * 100 / (float) words;
    float S = (float) sentences * 100 / (float) words;

    int grade = round((0.0588 * L) - (0.296 * S) - 15.8);

    //printing the Grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", grade);
    }

}

//counting the letters
int countLetters(string text)
{
    int letters = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }

    return letters;
}

//counting the Words
int countWords(string text)
{
    int words = 1;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words;
}

//counting the Sentences
int countSentences(string text)
{
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    return sentences;
}
