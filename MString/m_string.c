#include <stdio.h>
#include <stdlib.h>
#include "m_string.h"

int m_strcmp(const char *s1,const char *s2)
{
    if(!s1 || !s2)
        return 0;
    while(*s1 && *s2 && *s1 == *s2)
    {
        s1 ++;
        s2 ++;
    }

    return *s1 > *s2 ? 1: *s1 == *s2 ? 0 : -1 ;
}

int m_strcmpi(const char *s1,const char *s2)
{
    if(!s1 || !s2)
        return 0;

    while(*s1 && *s2 && A_MIN(*s1) == A_MIN(*s2))
    {
        s1 ++;
        s2 ++;
    }
    return A_MIN(*s1) - A_MIN(*s2);
}

int m_strncmp(const char *s1,const char *s2, size_t n)
{
    if(!s1 || !s2)
        return 0;
    if(n > 0)
        n --;
    while(*s1 && *s2 && *s1 == *s2 && n > 0)
    {
        s1 ++;
        s2 ++;
        n --;
    }

    return *s1 > *s2 ? 1: *s1 == *s2 ? 0 : -1 ;
}

char * m_strcpy(char *s1, const char *s2)
{
    if(!s1 || !s2)
        return NULL;
    char *ret = s1;
    while(*s2) *(s1 ++) = *(s2 ++);
    *s1 = '\0';
    return ret;
}

char * m_strncpy(char *s1, const char *s2, size_t n)
{
    if(!s1 || !s2)
        return NULL;
    if((long)n < 0)
        return s1;

    char *ret = s1;
    if(n > 0)
        n --;

    while(*s2 && n > 0)
    {
        *s1 = *s2;
        s1 ++;
        s2 ++;
        n --;
    }
    *s1 = '\0';
    return ret;
}

char * m_strcat(char * s1, const char *s2)
{
    if(!s1 || !s2)
        return NULL;
    char *ret = s1;
    while(*s1)
        s1 ++;
    while(*s2)
    {
        *s1 = *s2;
        s1 ++;
        s2 ++;
    }
    *s1 = *s2;
    return ret;
}

int m_strlen(const char * s)
{
    if(!s)
        return 0;
    int len = 0;
    while(*s)
    {
        len ++;
        s ++;
    }

    return len;
}

char * m_strchr(const char *s, const char c)
{
    if(!s && c == '\0')
        return NULL;
    char * aux = (char *)s;
    while(*aux && *aux != c)
        aux ++;
    return *aux == c ? aux : NULL;
}

char * m_strrchr(const char *s, const char c)
{
    if(!s && c == '\0')
        return NULL;
    char * aux = (char *)s;
    while(*aux) aux ++;
    aux --;
    while(aux != s && *aux != c)
        aux --;
    return *aux == c ? aux : NULL;
}

void * m_memcpy(void *e1, const void *e2,const size_t size)
{
    if(!e1 || !e2)
        return NULL;

    char * ele1 = (char *)e1;
    char * ele2 = (char *)e2;
    size_t s = size;

    while(s)
    {
        *ele1 = *ele2;
        ele1 ++;
        ele2 ++;
        s --;
    }
    return e1;
}

char * format_title(const char *s)
{
    if(!s)
        return NULL;

    char *desde = (char *)s;
    char *hasta = (char *)s;

    while(*hasta)
    {
        while(ES_BLANCO(*hasta))
            hasta ++;
        if(ES_MIN(*hasta))
            *hasta -= ' ';
        *desde = *hasta;
        desde ++;
        hasta ++;

        while(*hasta && !ES_BLANCO(*hasta))
        {
            if(ES_MAY(*hasta))
                *hasta += ' ';
            *desde = *hasta;
            desde ++;
            hasta ++;
        }
        if(ES_BLANCO(*hasta))
        {
            *desde = *hasta;
            desde ++;
            hasta ++;
        }
    }
    *desde = '\0';
    return (char *)s;
}
