#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <math.h>

void convert_length();
void convert_weight();
void convert_temperature();
void convert_speed();
void convert_volume();

int Lire_int(int *result);
int Lire_double(double *result);
int Lire_str(char *str, size_t N);

int strcmp_ignoring_case(const char *, const char *);

int main()
{

    int choice, Lire_res;

    char border[100] = {0};
    memset(border, 254, sizeof(char) * 100);

    do
    {

        border[19] = '\0';
        printf("\n%c%sConvertisseur d'unites%s%c\n", 219, border, border, 219);
        printf("%c1. Longueur (m, cm, km, inch, ft, yd, mile)                 %c\n", 219, 219);
        printf("%c2. Masse/Poids (g, kg, t, lb, oz)                           %c\n", 219, 219);
        printf("%c3. Temperature (C, F, K)                                    %c\n", 219, 219);
        printf("%c4. Vitesse (m/s, km/h, mph, knot)                           %c\n", 219, 219);
        printf("%c5. Volume/Capacite (L, mL, gal, cup, fl oz)                 %c\n", 219, 219);
        printf("%c0. Quitter                                                  %c\n", 219, 219);
        border[19] = 254;
        border[60] = '\0';
        printf("%c%s%c\n", 219, border, 219);
        do
        {
            printf("Votre choix :");
            Lire_res = Lire_int(&choice);
        } while (Lire_res == 0 || (choice < 1 || choice > 5));

        // scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            convert_length();
            break;
        case 2:
            convert_weight();
            break;
        case 3:
            convert_temperature();
            break;
        case 4:
            convert_speed();
            break;
        case 5:
            convert_volume();
            break;
        case 0:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide !\n");
            break;
        }
    } while (choice != 0);

    return 0;
}

// ==== LONGUEUR ====
void convert_length()
{
    int exist;
    int Lire_res;
    char str_units[5];
    double val;
    int from, to;
    const char *units[] = {"m", "cm", "km", "inch", "ft", "yd", "mile"};
    double factor[] = {1, 0.01, 1000, 0.0254, 0.3048, 0.9144, 1609.34};

    printf("Unites: m\tcm\tkm\tinch\tft\tyd\tmile\n");
    do
    {
        printf("Entrer valeur: ");
        Lire_res = Lire_double(&val);

    } while (Lire_res == 0);

    do
    {
        printf("De: (unite) ");
        Lire_res = Lire_str(str_units, 5);
        exist = 0;
        from = -1;
        for (int i = 0; i < 7; i++)
        {
            if (strcmp_ignoring_case(str_units, units[i]) == 0)
            {
                from = i;
                exist = 1;
                break;
            }
        }
        if (exist == 0)
        {
            printf("invalid Unites  : m\tcm\tkm\tinch\tft\tyd\tmile\n");
        }

    } while (Lire_res == 0 || exist == 0);

    do
    {
        printf("Vers: (unite)  ");

        Lire_res = Lire_str(str_units, 5);
        exist = 0;
        to = -1;
        for (int i = 0; i < 7; i++)
        {
            if (strcmp_ignoring_case(str_units, units[i]) == 0)
            {
                to = i;
                exist = 1;
                break;
            }
        }
        if (exist == 0)
        {
            printf("invalid Unites  : m\tcm\tkm\tinch\tft\tyd\tmile\n");
        }

    } while (Lire_res == 0 || exist == 0);

    double result = val * factor[from] / factor[to];

    printf("%.4lf %s = %.4lf %s\n", val, units[from], result, units[to]);
}

// ==== MASSE/POIDS ====
void convert_weight()
{

    int exist;
    int Lire_res;
    char str_units[5];
    double val;
    int from, to;
    const char *units[] = {"g", "kg", "t", "lb", "oz"};
    double factor[] = {1, 1000, 1000000, 453.592, 28.3495};

    printf("Unites: g\tkg\tt\tlb\toz\n");
    do
    {
        printf("Entrer valeur: ");
        Lire_res = Lire_double(&val);
    } while (Lire_res == 0);
    // scanf("%lf", &val);
    do
    {
        printf("De: ");
        Lire_res = Lire_str(str_units, 5);
        exist = 0;
        from = -1;
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(str_units, units[i]) == 0)
            {
                from = i;
                exist = 1;
                break;
            }
        }
        if (exist == 0)
        {
            printf("invalid Unites: g\tkg\tt\tlb\toz\n");
        }
    } while (Lire_res == 0 || exist == 0);
    // scanf("%d", &from);

    do
    {
        printf("Vers: ");
        Lire_res = Lire_str(str_units, 5);
        exist = 0;
        to = -1;
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(str_units, units[i]) == 0)
            {
                to = i;
                exist = 1;
                break;
            }
        }
        if (exist == 0)
        {
            printf("invalid Unites: g\tkg\tt\tlb\toz\n");
        }
    } while (Lire_res == 0 || exist == 0);

    // scanf("%d", &to);

    double result = val * factor[from] / factor[to];
    printf("%.4f %s = %.4f %s\n", val, units[from], result, units[to]);
}

// ==== TEMPERATURE ====
void convert_temperature()
{
    int exist;
    int Lire_res;
    char str_units[5];
    double val, result;
    int from, to;
    const char *units[] = {"C", "F", "K"};
    printf("Unites: C\tF\tK\n");
    do
    {
        printf("Entrer valeur: ");
        Lire_res = Lire_double(&val);

    } while (Lire_res == 0);

    do
    {
        printf("De: (unite) ");
        Lire_res = Lire_str(str_units, 5);
        exist = 0;
        from = -1;
        for (int i = 0; i < 3; i++)
        {
            if (strcmp(str_units, units[i]) == 0)
            {
                from = i;
                exist = 1;
                break;
            }
        }
        if (exist == 0)
        {
            printf("invalid Unites  :  C\tF\tK\n");
        }

    } while (Lire_res == 0 || exist == 0);

    do
    {
        printf("Vers: (unite)  ");

        Lire_res = Lire_str(str_units, 5);
        exist = 0;
        to = -1;
        for (int i = 0; i < 3; i++)
        {
            if (strcmp(str_units, units[i]) == 0)
            {
                to = i;
                exist = 1;
                break;
            }
        }
        if (exist == 0)
        {
            printf("invalid Unites  : C\tF\tK\n");
        }

    } while (Lire_res == 0 || exist == 0);

    if (from == to)
        result = val;
    else if (from == 0 && to == 1)
        result = val * 9 / 5 + 32;
    else if (from == 0 && to == 2)
        result = val + 273.15;
    else if (from == 1 && to == 0)
        result = (val - 32) * 5 / 9;
    else if (from == 1 && to == 2)
        result = (val - 32) * 5 / 9 + 273.15;
    else if (from == 2 && to == 0)
        result = val - 273.15;
    else if (from == 2 && to == 1)
        result = (val - 273.15) * 9 / 5 + 32;

    printf("%.2f %s = %.2f %s\n", val, units[from], result, units[to]);
}

// ==== VITESSE ====
void convert_speed()
{
    int exist;
    int Lire_res;
    char str_units[5];
    double val;
    int from, to;
    const char *units[] = {"m/s", "km/h", "mph", "knot"};
    double factor[] = {1, 0.277778, 0.44704, 0.514444};

    printf("Unites: m/s\tkm/h\tmph\tknot\n");

    do
    {
        printf("Entrer valeur: ");
        Lire_res = Lire_double(&val);

    } while (Lire_res == 0);

    do
    {
        printf("De: (unite) ");
        Lire_res = Lire_str(str_units, 5);
        exist = 0;
        from = -1;
        for (int i = 0; i < 4; i++)
        {
            if (strcmp(str_units, units[i]) == 0)
            {
                from = i;
                exist = 1;
                break;
            }
        }
        if (exist == 0)
        {
            printf("invalid Unites  : m/s\tkm/h\tmph\tknot\n");
        }

    } while (Lire_res == 0 || exist == 0);

    do
    {
        printf("Vers: (unite)  ");

        Lire_res = Lire_str(str_units, 5);
        exist = 0;
        to = -1;
        for (int i = 0; i < 4; i++)
        {
            if (strcmp(str_units, units[i]) == 0)
            {
                to = i;
                exist = 1;
                break;
            }
        }
        if (exist == 0)
        {
            printf("invalid Unites  : m/s\tkm/h\tmph\tknot\n");
        }

    } while (Lire_res == 0 || exist == 0);

    double result = val * factor[from] / factor[to];
    printf("%.4f %s = %.4f %s\n", val, units[from], result, units[to]);
}

// ==== VOLUME ====
void convert_volume()
{
    int exist;
    int Lire_res;
    char str_units[5];
    double val;
    int from, to;
    const char *units[] = {"L", "mL", "gal", "cup", "fl-oz"};
    double factor[] = {1, 0.001, 3.78541, 0.236588, 0.0295735};

    printf("Unites: L\tmL\tgal\tcup\tfl-oz\n");
    do
    {
        printf("Entrer valeur: ");
        Lire_res = Lire_double(&val);

    } while (Lire_res == 0);

    do
    {
        printf("De: (unite) ");
        Lire_res = Lire_str(str_units, 5);
        exist = 0;
        from = -1;
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(str_units, units[i]) == 0)
            {
                from = i;
                exist = 1;
                break;
            }
        }
        if (exist == 0)
        {
            printf("invalid Unites  : L\tmL\tgal\tcup\tfl-oz\n");
        }

    } while (Lire_res == 0 || exist == 0);

    do
    {
        printf("Vers: (unite)  ");

        Lire_res = Lire_str(str_units, 5);
        exist = 0;
        to = -1;
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(str_units, units[i]) == 0)
            {
                to = i;
                exist = 1;
                break;
            }
        }
        if (exist == 0)
        {
            printf("invalid Unites  : L\tmL\tgal\tcup\tfl-oz\n");
        }

    } while (Lire_res == 0 || exist == 0);

    double result = val * factor[from] / factor[to];
    printf("%.4f %s = %.4f %s\n", val, units[from], result, units[to]);
}

int Lire_int(int *result)
{
    char buffer[256];
    char *endptr;
    long value;

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return 0;
    }

    errno = 0;
    value = strtol(buffer, &endptr, 10);

    if (errno == ERANGE && (value == LONG_MAX || value == LONG_MIN))
    {
        return 0;
    }

    if (endptr == buffer || *endptr != '\n')
    {
        return 0;
    }

    if (value < INT_MIN || value > INT_MAX)
    {
        return 0;
    }

    *result = (int)value;
    return 1;
}

int Lire_double(double *result)
{
    char buffer[256];
    char *endptr;
    double value;

    // Read the line
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return 0; // Error or EOF
    }

    errno = 0;

    value = strtod(buffer, &endptr); // Convert text to double

    if (errno == ERANGE && (value == DBL_MAX || value == -DBL_MAX))
    {
        return 0; // overflow/underflow
    }

    // Skip white spaces after the number
    while (isspace((unsigned char)*endptr))
        endptr++;

    if (*endptr != '\0' && *endptr != '\n')
    {
        return 0; // There are additional characters that are not accepted.
    }

    *result = value;
    return 1; // Successful input
}

int Lire_str(char *str, size_t N)
{
    if (str == NULL || N <= 0)
    {
        return 0; // Invalid parameters
    }

    if (fgets(str, N, stdin) == NULL)
    {
        return 0; // End of input or error
    }

    size_t len_str = strlen(str);

    // Remove trailing newline if present
    if (len_str > 0 && str[len_str - 1] == '\n')
    {
        str[len_str - 1] = '\0';
    }
    else
    {
        // Flush the remaining input
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }

    return 1; // Successful input
}

int strcmp_ignoring_case(const char *str1, const char *str2)
{
    unsigned char c1, c2;

    while (*str1 && *str2)
    {
        c1 = (unsigned char)tolower((unsigned char)*str1);
        c2 = (unsigned char)tolower((unsigned char)*str2);

        if (c1 != c2)
        {
            return c1 - c2;
        }

        str1++;
        str2++;
    }

    // If one string ended
    return (unsigned char)tolower((unsigned char)*str1) - (unsigned char)tolower((unsigned char)*str2);
}
