#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };

int maxDepth(struct TreeNode* root) {

    if (root == NULL) {
        return 0;
    }
    
    if ((root->left == NULL) && (root->right == NULL)) {
        return 1;
    }
    
    if ((root->left != NULL) && (root->right == NULL)) {
        return maxDepth(root->left) + 1;
    } else if ((root->right != NULL) && (root->left == NULL)) {
        return maxDepth(root->right) + 1;
    } else {
        return (maxDepth(root->left) + 1) > (maxDepth(root->right) + 1) 
            ? (maxDepth(root->left) + 1) : (maxDepth(root->left) + 1);
    }
}

void createTree(struct TreeNode** root)
{

}

void split(char *src,const char *separator,char **dest,int *num) {
	/*
		src 源字符串的首地址(buf的地址) 
		separator 指定的分割字符
		dest 接收子字符串的数组
		num 分割后子字符串的个数
	*/
     char *pNext;
     int count = 0;
     if (src == NULL || strlen(src) == 0) //如果传入的地址为空或长度为0，直接终止 
        return;
     if (separator == NULL || strlen(separator) == 0) //如未指定分割的字符串，直接终止 
        return;
     pNext = (char *)strtok(src,separator); //必须使用(char *)进行强制类型转换(虽然不写有的编译器中不会出现指针错误)
     while(pNext != NULL) {
          *dest++ = pNext;
          ++count;
         pNext = (char *)strtok(NULL,separator);  //必须使用(char *)进行强制类型转换
    }  
    *num = count;
} 


int main()
{
    char *text1 = "3,9,20,null,null,15,7";
    //splitStr(text1);
    //sscanf("");
    //char buf[]="www.baidu.com,www.taobao.com,www.csdn.com,www.python.org";
	//用来接收返回数据的数组。这里的数组元素只要设置的比分割后的子字符串个数大就好了。
	char *revbuf[8] = {0}; //存放分割后的子字符串 
	
	//分割后子字符串的个数
	int num = 0;
	
	split(text1,",",revbuf,&num); //调用函数进行分割 
	
	//输出返回的每个内容 
	for(int i = 0;i < num; i ++) {
		//lr_output_message("%s\n",revbuf[i]);
		printf("%s\n",revbuf[i]);
	}
    return 0;
}