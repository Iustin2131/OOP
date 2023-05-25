#include "Hash.h"
#include <cstdio>

int CountAsciiHash::calcHash(const char* s) {
    int nr = 0;
    for (int i = 0; s[i] != '\0'; i++)
        nr += (int)s[i];
    return nr; 
}

Hash*& HashManager::operator[](const char* s) {
    list[count].nume = s;
    return list[count++].hash;

}

void HashManager::print_hashes(const char* s) {
    for (int i = 0; i < count; i++) {
        printf("%s, %d\n", list[i].nume, list[i].hash->calcHash(s));
    }
}

HashManager::HashManager()
{
    count = 0;
}



int EasyHash::calcHash(const char* s)
{
    int nr = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'q' || s[i] == 'w' || s[i] == 'r' || s[i] == 't' || s[i] == 'y' || s[i] == 'p' || s[i] == 's' || s[i] == 'd' || s[i] == 'f' || s[i] == 'g' || s[i] == 'h' || s[i] == 'j' || s[i] == 'k' || s[i] == 'l' || s[i] == 'z' || s[i] == 'x' || s[i] == 'c' || s[i] == 'v' || s[i] == 'b' || s[i] == 'n' || s[i] == 'm' || s[i] == 'Q' || s[i] == 'W' || s[i] == 'R' || s[i] == 'T' || s[i] == 'Y' || s[i] == 'P' || s[i] == 'S' || s[i] == 'D' || s[i] == 'F' || s[i] == 'G' || s[i] == 'H' || s[i] == 'J' || s[i] == 'K' || s[i] == 'L' || s[i] == 'Z' || s[i] == 'X' || s[i] == 'C' || s[i] == 'V' || s[i] == 'B' || s[i] == 'N' || s[i] == 'M')
            nr += 11 * (int)s[i];
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            nr += 10 * (int)s[i];
        else
            nr += 12 * (int)s[i];
    }
    return nr;
}

int CountConsonantHash::calcHash(const char* s)
{
    int nr = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {  
        if (s[i] == 'q' || s[i] == 'w' || s[i] == 'r' || s[i] == 't' || s[i] == 'y' || s[i] == 'p' || s[i] == 's' || s[i] == 'd' || s[i] == 'f' || s[i] == 'g' || s[i] == 'h' || s[i] == 'j' || s[i] == 'k' || s[i] == 'l' || s[i] == 'z' || s[i] == 'x' || s[i] == 'c' || s[i] == 'v' || s[i] == 'b' || s[i] == 'n' || s[i] == 'm' || s[i] == 'Q' || s[i] == 'W' || s[i] == 'R' || s[i] == 'T' || s[i] == 'Y' || s[i] == 'P' || s[i] == 'S' || s[i] == 'D' || s[i] == 'F' || s[i] == 'G' || s[i] == 'H' || s[i] == 'J' || s[i] == 'K' || s[i] == 'L' || s[i] == 'Z' || s[i] == 'X' || s[i] == 'C' || s[i] == 'V' || s[i] == 'B' || s[i] == 'N' || s[i] == 'M')
            nr++;
    }
    return nr;
}

int CountVowelsHash::calcHash(const char* s)
{
    int nr = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            nr++;
    }
    return nr;
}
