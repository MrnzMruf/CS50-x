#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_key(string key);
char substitute(char c, string key);

int main(int argc, string argv[])
{
    // بررسی تعداد آرگومان‌ها
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // بررسی اعتبار کلید
    string key = argv[1];
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // دریافت متن از کاربر
    string plaintext = get_string("plaintext: ");

    // رمزگذاری متن
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", substitute(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

bool is_valid_key(string key)
{
    // بررسی طول کلید
    if (strlen(key) != 26)
    {
        return false;
    }

    // بررسی حروف الفبایی و یکتا بودن حروف
    bool seen[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        int index = toupper(key[i]) - 'A';
        if (seen[index])
        {
            return false;
        }
        seen[index] = true;
    }
    return true;
}

char substitute(char c, string key)
{
    if (isupper(c))
    {
        return toupper(key[c - 'A']);
    }
    else if (islower(c))
    {
        return tolower(key[c - 'a']);
    }
    else
    {
        return c;
    }
}
