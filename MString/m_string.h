#ifndef M_STRING_H_INCLUDED
#define M_STRING_H_INCLUDED

#define ES_BLANCO(X)((X) == ' ' || (X) == '\t')
#define ES_MAY(X)((X) >= 'A' && (X) <= 'Z')
#define ES_MIN(X)((X) >= 'a' && (X) <= 'z')
#define A_MAY(X)(ES_MIN((X)) ? (X) - ' ': (X))
#define A_MIN(X)(ES_MAY((X)) ? (X) + ' ': (X))



int m_strcmp(const char *s1,const char *s2);
int m_strcmpi(const char *s1,const char *s2);
int m_strncmp(const char *s1,const char *s2, size_t n);

char * m_strcpy(char *s1, const char *s2);
char * m_strncpy(char *s1, const char *s2, size_t n);

char * m_strcat(char * s1, const char *s2);
int m_strlen(const char * s);
char * m_strchr(const char *s, const char c);
char * m_strrchr(const char *s, const char c);


void * m_memcpy(void *e1, const void *e2,const size_t size);
char * format_title(const char *s);

#endif // M_STRING_H_INCLUDED
