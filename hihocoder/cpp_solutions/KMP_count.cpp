#include <stdio.h>
#include <string.h>

/*
void GetNextval(char* p, int next[])
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        //p[k]表示前缀，p[j]表示后缀
        if (k == -1 || p[j] == p[k])
        {
            ++j;
            ++k;
            //较之前next数组求法，改动在下面4行
            if (p[j] != p[k])
                next[j] = k;   //之前只有这一行
            else
                //因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]
                next[j] = next[k];
        }
        else
        {
            k = next[k];
        }
    }
}

void GetNext(char* p,int* next)
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1)
    {
        //p[k]表示前缀，p[j]表示后缀
        if (k == -1 || p[j] == p[k])
        {
            ++k;
            ++j;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
    return;
}

int KmpSearch(char* s, char* p)
{
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    int* next = new int[pLen+1];
    GetNext(p, next);
    while (i < sLen && j < pLen)
    {
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
            //next[j]即为j所对应的next值
            j = next[j];
        }
    }
    if (j == pLen)
        return i - j;
    else
        return -1;
}
*/

char pattern[10005];
char str[1000005];

void getnext(char *pattern, int pattern_len, int *next){
    int i=0,j=-1;
    next[0]=j;
    while(i<pattern_len){
        while(j!=-1 && pattern[j] != pattern[i])
            j=next[j];
        i++,j++;
        // if(j>=pattern_len)
        //     next[i]=next[j-1];
        // else
        next[i]=j;
    }
}

int kmp(char *str, int str_len, char *pattern, int pattern_len)
{
    int next[10005];
    getnext(pattern, pattern_len, next);

    int i = 0;
    int j = 0;
    int count = 0;

    while(i < str_len){
        while(j != -1 && pattern[j] != str[i]){
            j = next[j];
        }
        i++,j++;

        if(j == pattern_len){
            count++;
            j=next[j];
        }
    }

    return count;
}

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {

        scanf("%s", pattern);
        scanf("%s", str);

        printf("%d\n",kmp(str, strlen(str), pattern, strlen(pattern)));
    }
    return 0;
}
// another solution
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using  namespace std;

const int mx = 1e6+5;
typedef long long ll;

int n;
int nxt[mx];
string s, p;

void getNxt() {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < p.size()) {
        if(j == -1 || p[i] == p[j]) {
            i ++;
            j ++;
            nxt[i] = j;
        }
        else
            j = nxt[j];
    }
}

int kmp() {
    getNxt();
    int i = 0, j = 0, ans = 0;
    while(i < s.size()) {
        if(j == -1 || s[i] == p[j]) {
            i ++;
            j ++;
        }
        else
            j = nxt[j];
        if(j == p.size())
            ans ++;
    }
    return ans;
}

int main() {
    cin >> n;
    while(n --) {
        cin >> p >> s;
        cout << kmp() << endl;
    }
    return 0;
}
