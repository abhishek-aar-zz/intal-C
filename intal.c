#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"

static void swapIt(char **arr,int largest,int i){
    char* temp = arr[largest];
    arr[largest] = arr[i];
    arr[i] = temp;
}

static void heapify(char **arr,int n,int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l<n && intal_compare(arr[l],arr[largest]) == 1){
        largest = l;
    }
    if(r<n && intal_compare(arr[r],arr[largest]) == 1){
        largest = r;
    }
    if (largest != i){
        swapIt(arr,largest,i);
        heapify(arr,n,largest);
    }
}

static void strRev(char *a){
    int n = strlen(a);
    for (int i = 0; i < n / 2; i++){
        char b = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = b;
    }
}

char* intal_add(const char* intal1,const  char* intal2){
    int len1=strlen(intal1);
    int len2=strlen(intal2);
    int max = len1>len2?len1:len2;
    int leng=max+2;
    if(intal_compare(intal1,"0")==0){
        char* ret = (char*)malloc(sizeof(char)*strlen(intal2));
        strcpy(ret,intal2);
        return ret;
    }
    if(intal_compare(intal2,"0")==0){
        char* ret = (char*)malloc(sizeof(char)*strlen(intal1));
        strcpy(ret,intal1);
        return ret;
    }
    char* result=(char*)malloc(leng*sizeof(char));
    result[leng-1]='\0';
    int sum=0;
    int ind=0;
    int carry=0;
    while(len1-ind-1 >=0 && len2-ind-1>=0){
        sum=(intal1[len1-ind-1]-'0') + (intal2[len2-ind-1]-'0') + carry;
        result[leng-ind-2]=(char)sum%10+'0';
        carry=sum/10;
        ind++;
    }
    for(;ind<len1 && len1-ind-1>=0;ind++){
        sum=(intal1[len1-ind-1]-'0') + carry;
        result[leng-ind-2]=(char)sum%10+'0';
        carry=sum/10;
    }
    for(;ind<len2 && len2-ind-1>=0;ind++){
        sum=(intal2[len2-ind-1]-'0') + carry;
        result[leng-ind-2]=(char)sum%10+'0';
        carry=sum/10;
    }
    if(carry>0){
        result[0]=(char)carry+'0';
    }else{
        for(int ind=0;ind<leng-1;ind++){
            result[ind]=result[ind+1];
        }
        result[leng-1]='\0';
    }
    return result;
}

char *intal_diff(const char *intal1, const char *intal2){
    int len1 = strlen(intal1);
    int len2 = strlen(intal2);
    char *ch1 = (char*)malloc(sizeof(char) * (len1+ 1));
    strcpy(ch1, intal1);
    char *ch2 = (char*)malloc(sizeof(char) * (len2 + 1));
    strcpy(ch2, intal2);
    ch1[len1] = '\0';
    ch2[len2] = '\0';
    int comp = intal_compare(ch2, ch1);
    if (comp == 0){
        char *result = malloc(sizeof(char) * 2);
        strcpy(result, "0\0");
        return result;
    }
    if (comp == 1){
        char *temp = ch1;
        ch1 = ch2;
        ch2 = temp;
    }
    int n = len1 > len2 ? len1 : len2;
    char *result = (char *)malloc(sizeof(char) * (n + 2));
    int min = (n == len1) ? len2 : len1;
    strRev(ch1);
    strRev(ch2);
    int c = 0;
    int m = 0;
    for (int i = 0; i < min; i++){
        int s = (ch1[i] - '0') - (ch2[i] - '0') - c;
        if (s < 0){
            s += 10;
            c = 1;
        }
        else{
            c = 0;
        }
        result[m++] = '0' + s;
    }
    for (int i = min; i < n; i++){
        int s = (ch1[i] - '0') - c;
        if (s < 0){
            s += 10;
            c = 1;
        }
        else{
            c = 0;
        }
        result[m++] = '0' + s;
    }
    m--;
    while (result[m] == '0'){
        m--;
    }
    m++;
    result[m] = '\0';
    strRev(result);
    free(ch1);
    free(ch2);
    return result;
}

int intal_compare(const char* intal1, const char* intal2){
    int len1 = strlen(intal1);
    int len2 = strlen(intal2);
    if (len1>len2){
        return 1;
    }else if (len2>len1){
        return -1;
    }else if (len1==len2){
        for(int i = 0;i!=len2;i++){
            if (intal1[i] > intal2[i]){
                return 1;
            }
            else if (intal2[i] > intal1[i]){
                return -1;
            }
        }
    }
    return 0;
}

char* intal_multiply(const char* intal1,const  char* intal2)
{ 
    int len1=strlen(intal1);
    int len2=strlen(intal2);
    int leng=len1+len2;
    if(intal_compare("0",intal1)==0 || intal_compare("0",intal2)==0){
        char *finalResult=(char*)malloc(2*sizeof(char));
        finalResult[0]='0'; finalResult[1]='\0';
        return finalResult;
    }
    int *result=(int*)malloc(leng*sizeof(int));
    for(int i=0;i<leng;i++){
        result[i]=0;
    }
    int ind1=0;
    int ind2=0;
    for(int i=len1-1;i>=0;i--){
        int x=intal1[i] - '0';
        int carry=0;
        ind2=0;
        for(int j=len2-1;j>=0;j--){
            int y=intal2[j] - '0';
            int sum=x*y + result[ind1 + ind2] + carry;
            carry=sum/10;
            result[ind1 + ind2]=sum%10;
            ind2++;
        }
        if(carry>0){
            result[ind1 + ind2]+=carry;
        }
        ind1++;
    }
    int xx1;
    for(xx1 = leng - 1;xx1>=0 && result[xx1] == 0;xx1--){}
    char *finalResult=(char*)malloc((xx1+2)*sizeof(char));
    int xx2 = 0;
    for(;xx2<=xx1;xx2++){
        finalResult[xx2]=result[xx1-xx2]+'0';
    }
    finalResult[xx1+1]='\0';
    free(result);
    return finalResult;
}

char *intal_gcd(const char *intal1, const char *intal2){
    if (intal1[0] == '0' && intal2[0] == '0'){
        char *result = malloc(sizeof(char) * 2);
        strcpy(result, "0\0");
        return result;
    }
    if (intal2[0] == '0'){
        char *result = (char*)malloc(sizeof(char)*(1+strlen(intal1)));
        strcpy(result, intal1);
        result[strlen(intal1)]='\0';
        return result;
    }else{
        return intal_gcd(intal2, intal_mod(intal1, intal2));
    }
}

char *intal_mod(const char *intal1, const char *intal2){
    int len1 = strlen(intal1);
    int len2 = strlen(intal2);
    if (intal_compare(intal1, intal2) == -1){
        char *l = (char*)malloc(sizeof(char)*(len1+1));
        strcpy(l, intal1);
        l[len1]='\0';
        return l;
    }
    int d = len1 - len2;
    int r =0;
    for (int i = 0; i < strlen(intal2); i++){
        if (intal2[i] > intal1[i]){
            r= 1;
            break;
        }
        else if(intal2[i] < intal1[i]){
            r= 0;
            break;
        }
    }
    d -= r;
    if (d > 0){
        char *e = malloc(sizeof(char) * (len2 + d + 1));
        for (int i = 0; i < len2; i++){
            e[i] = intal2[i];
        }
        int m = len2;
        for (int i = 0; i < d; i++){
            e[i + m] = '0';
        }
        e[d + m] = '\0';
        e = intal_diff(intal1, e);
        return intal_mod(e, intal2);
    }
    return intal_mod(intal_diff(intal1, intal2), intal2);
}

char* intal_pow(const char* intal1, unsigned int n)
{
    if(intal_compare(intal1,"0") == 0){
        char* temp_pow = (char*)malloc(sizeof(char)*2);
        temp_pow[0] = '0';temp_pow[1] = '\0';
        return temp_pow;
    }
    char* x = (char*)malloc(sizeof(char)*strlen(intal1));
    strcpy(x,intal1);
    int y=n;
    char* temp_x_1;
    char* temp_res;
    char* result = (char*)malloc(sizeof(char)*2);
    result[0] = '1';result[1] = '\0';
    while(y>0){
        temp_x_1 = x;
        if ((y%2) == 1){
            temp_res = result;
            result = intal_multiply(result,x);
            free(temp_res);
        }
        y = y/2;
        x = intal_multiply(x,x);
        free(temp_x_1);
    }
    free(x);
    return result;
}

char* intal_fibonacci(unsigned int n){
    char* a = (char*)malloc(sizeof(char)*2);
    strcpy(a,"0\0");
    char* b = (char*)malloc(sizeof(char)*2);
    strcpy(b,"1\0");
    if (n == 0){
        free(b);
        return a;
    }
    if (n == 1){ 
        free(a);  
        return b;
    }
    char* temp_a;
    char* temp_res;
    for(int fib_i = 2;fib_i<=n;fib_i++){
        temp_a = a;
        temp_res = intal_add(a,b);
        a = b;
        b = temp_res;
        free(temp_a);
    }
    free(a);
    return temp_res;
}

char* intal_factorial(unsigned int n){
    char* temp = (char*)malloc(sizeof(char)*2);
    char* temp1;
    strcpy(temp, "1\0");
    char* result = (char*)malloc(sizeof(char)*2);
    strcpy(result, "1\0");
    char* temp_result_1;
    for(int fact_i = 1;fact_i<=n;fact_i++){
        temp_result_1 = result;
        temp1 = temp;
        result = intal_multiply(temp,result);
        free(temp_result_1);
        temp = intal_add(temp,"1");
        free(temp1);
    }
    free(temp);
    return result;
}

int intal_max(char **arr, int n){
    int max = 0;
    int comp;
    for(int i = 1;i<n;i++){
        comp = intal_compare(arr[i],arr[max]);
        if (comp == 1)
            max = i;
    }
    return max;
}

int intal_min(char **arr, int n){
    int min = 0;
    int comp;
    for(int i = 1;i<n;i++){
        comp = intal_compare(arr[min],arr[i]);
        if (comp == 1)
            min = i;
    }
    return min;
}

int intal_search(char **arr, int n, const char* key){
    int comp;
    for(int i=0;i<n;i++){
        comp = intal_compare(key,arr[i]);
        if (comp == 0)
            return i;
    }
    return -1;
}

int intal_binsearch(char **arr, int n, const char* key){
    int low = 0;
    int high = n - 1;
    int comp;
    int mid;
    while(low<=high){
        mid = (low + high)/2;
        comp = intal_compare(arr[mid],key);
        if (comp == 0)
            return mid;
        if (comp == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

char* intal_bincoeff(unsigned int n, unsigned int k)
{
    int i,j;
    int kk =k;
    if(n-k<k){
        kk=n-k;
    }

    char arr[kk+1][1001];
    for(i = 1; i < (kk+1); i++){
        strcpy(arr[i],"0");
    }
    strcpy(arr[0],"1");
    for(i=1;i<=n;i++){
        for(j=((i<kk)?i:kk);j>0;j--){
            char *result=intal_add(arr[j],arr[j-1]);
            strcpy(arr[j],result);
            free(result);
        }
    }
    char *res1=(char*)malloc(1001*sizeof(char));
    strcpy(res1,arr[kk]);
    return res1;
}  

void intal_sort(char **arr, int n){
    for(int i = (n/2 - 1);i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        swapIt(arr,0,i);
        heapify(arr,i,0);
    }
}

char* coin_row_problem(char **arr, int n){
    int comp;
    char* add;
    char *temp;
    char *cur,*prev,*next;
    prev = (char*)malloc(sizeof(char)*2);
    strcpy(prev,"0\0");
    cur = (char*)malloc(sizeof(char)*strlen(arr[0]));
    strcpy(cur,arr[0]);
    for(int coin_i=2;coin_i<=n;coin_i++){
        temp = prev;
        add = intal_add(arr[coin_i - 1],prev);
        comp = intal_compare(add,cur);
        if(comp == 1){
            next = add;
        }else{
            next = cur;
            free(add);
        }
        prev = cur;
        cur = next;
    }
    return cur;
}