/*
 * @Author: CQ
 * @Date: 2021-12-20 09:29:16
 * @LastEditors: CQ
 * @LastEditTime: 2021-12-20 20:33:52
 * @Description: file content
 * @FilePath: \C\Pointers On C\practice6.18.1.c
 */
#include <stdio.h>
#include <stdint.h>


/**
 * @description:在一个字符串中进行搜索，查找在一个给定字符集合中出现的字符  《 Pointers on C 》P115 
 * @param {source：给定字符串}  {chars：需要搜索的字符串}
 * @return {NULL:未找到}   {OTHER：符合字符的地址}
 */
char *find_char(char const *source,char const *chars)
{
    if(source == NULL || chars == NULL || *source == '\0' || *chars == '\0')    //检测形参是否有效
    {
        return NULL;
    }

    char const *chars_copy = chars;
    while(*source != '\0')
    {
        while(*chars_copy != '\0')
        {
            if(*source == *chars_copy)
            {
                return (char *)chars_copy;
            }
            chars_copy++;
        }
        chars_copy = chars;         //重新给chars_copy赋予chars的地址，因为chars_copy的地址自增导致了偏移
        source++;
    }
    return NULL;
}

/**
 * @description: 主函数
 * @param {*}
 * @return {*}
 */
int main(void)
{
    char ch[] = "RQWOA";
    char source[] = "ABCDEF";
    char *p = ch;

    while(*p != '\0')
    {
        printf("ch = %c,address = %p\r\n", *p, p);
        p++;
    }

    p = find_char(source,ch);

    if(p == NULL)
    {
        printf("not find\r\n");
    }
    else
    {
        printf("found! ch = %c ,address = %p\r\n", *p,p);
    }
    
}