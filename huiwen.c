
#define MAX_SIZE 1000
char g_maxLongPalindrom[MAX_SIZE+1]= {0};
char g_tmpStr[MAX_SIZE+1]={0};

int isPalindrom(char *s) 
{
    char *p;
    p = s + strlen(s) - 1;
    do {
        if(*p == *s) {
            s++;
            p--;
            continue;
        } else {
            return 0;
        }
        
    } while(*s != '\0');
    return 1;
}

char * longestPalindrome(char * s){
    
    int i = 0;
    int j = 0;
    char *tmp;
    int maxlen = 0;
    
    do {
        for(j = 1; j <= strlen(s); j++) {
            memset(g_tmpStr, 0, sizeof(g_tmpStr));
            strncpy(g_tmpStr, s, j);
            if(isPalindrom(g_tmpStr)) {
                if(maxlen <= j) {
                    maxlen = j;
                    tmp = s;
                }
            }
        }
        s++;
    } while(*s != '\0') ;
    strncpy(g_maxLongPalindrom, tmp, maxlen);
    
    return g_maxLongPalindrom;
}

