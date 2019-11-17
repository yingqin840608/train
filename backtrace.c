#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char digit;
    char alphas[5];
}DigitAlpha;

DigitAlpha g_alphaList[8] = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

DigitAlpha *getCurrent(char digit)
{
    int i;
    for(i = 0; i < 8; i++)
    {
        if(digit == g_alphaList[i].digit) 
        {
            return &g_alphaList[i];
        }
    }
    return NULL;
}

void backtrack(char **output, char *str, char *nextstr)
{
    char digit;
    DigitAlpha *digitInfo;
    char *alphastr;
    static int index = 0;
    char conbinestr[8] = {0};

    int i = 0;
    if(strlen(nextstr) == 0) {
        /*字符串添加到数组中*/
        strncpy(output[index++], str, strlen(str));
    } else {
        digit = nextstr[0];
        digitInfo = getCurrent(digit);
        
        if(digitInfo != NULL) {
            alphastr = digitInfo->alphas;
            strncpy(conbinestr, str, strlen(str));
            for (i = 0; i < strlen(alphastr); i++) {
                conbinestr[strlen(str)] = alphastr[i];
                backtrack(output, conbinestr, nextstr++);
            }
        } 
    }
}

char **letterCombinations(char *digits, int *returnSize) 
{
    
    int num = strlen(digits);
    int outputSize = 1;
    int i;
    char **outputStr;

    for(i = 0; i < num; i++) {
        outputSize = outputSize * strlen(g_alphaList[i].alphas);
    }
    
    *returnSize = outputSize;

    outputStr = (char **)malloc( sizeof(char *) * outputSize);

    for (int i = 0; i < outputSize; i++) {
        outputStr[i] = (char *)malloc(sizeof(char) * (num + 1));
    }

    if(num > 0) {
        backtrack(outputStr, "", digits);
    }

    return outputStr;
}

int main()
{
    int mallocSize = 0;
    letterCombinations("23", &mallocSize);
    return 0;

}