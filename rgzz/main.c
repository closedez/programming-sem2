#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char rus[100];
    char eng[100];
} Word;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Использование: %s input.txt dict.txt output.txt\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Ошибка открытия входного файла\n");
        return 1;
    }

    FILE *dict = fopen(argv[2], "r");
    if (dict == NULL)
    {
        printf("Ошибка открытия словаря\n");
        fclose(input);
        return 1;
    }

    FILE *output = fopen(argv[3], "w");
    if (output == NULL)
    {
        printf("Ошибка создания выходного файла\n");
        fclose(input);
        fclose(dict);
        return 1;
    }

    Word *words = malloc(100 * sizeof(Word));
    if (words == NULL)
    {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    int count = 0;

    while (fscanf(dict, "%99s %99s", words[count].rus, words[count].eng) == 2)
    {
        count++;
    }

    char word[100];
    int len = 0;
    int c;

    while ((c = fgetc(input)) != EOF)
    {
        if (isalnum(c) || (unsigned char)c >= 128)
        {
            word[len++] = (char)c;
        }
        else
        {
            if (len > 0)
            {
                word[len] = '\0';

                int found = 0;

                for (int i = 0; i < count; i++)
                {
                    if (strcmp(word, words[i].rus) == 0)
                    {
                        fprintf(output, "%s", words[i].eng);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    fprintf(output, "%s", word);

                len = 0;
            }

            fputc(c, output);
        }
    }

    if (len > 0)
    {
        word[len] = '\0';

        int found = 0;

        for (int i = 0; i < count; i++)
        {
            if (strcmp(word, words[i].rus) == 0)
            {
                fprintf(output, "%s", words[i].eng);
                found = 1;
                break;
            }
        }

        if (!found)
            fprintf(output, "%s", word);
    }

    free(words);

    fclose(input);
    fclose(dict);
    fclose(output);

    return 0;
}