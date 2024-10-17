#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// پروتوتایپ توابع
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // گرفتن متن از کاربر
    string text = get_string("Text: ");

    // شمارش تعداد حروف، کلمات و جملات در متن
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // محاسبه شاخص Coleman-Liau
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // چاپ سطح کلاس
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(index));
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1; // شروع از 1 برای شمارش اولین کلمه
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
