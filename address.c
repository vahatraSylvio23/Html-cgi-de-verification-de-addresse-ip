#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct ip
{
    int a,b,c,d;
}ip;

void get_ip(char *URL ,ip *ad);
void page_head();
void check_ip(ip *ad);
void page_foot();

int main()
{
    ip ad;
    char *address;
    get_ip(address ,&ad);
    check_ip(&ad);
    page_foot();
    return 0;
}
void page_head()
{
    printf("<html><head><title>Verification</title>");
    printf("<style>");
    printf("p{background-image:linear-gradient(blue , white);background-color:black;padding:200px;position:relative;text-align:center;border-radius:50px;font-size:50px;color:blue;text-shadow:3px 3px black}");
    printf("</style>");
    printf("</head>");
    printf("<body><p>");
}
void get_ip(char *URL ,ip *ad)
{
    char address1[100],address2[100],address3[100],address4[100];
    printf("Content-Type:Text/html\n\n");
    page_head();
    URL=getenv("QUERY_STRING");
    char *URL1;
    if(URL==NULL)
    {
        printf("ERROR!!! </body></html>\n");
        exit(EXIT_SUCCESS);
    }

    sscanf(URL,"ip=%d.%d.%d.%d",&ad->a,&ad->b,&ad->c,&ad->d);

    if(ad->a > 255 || ad->b > 255 || ad->c > 255 || ad->d < 0 ||ad->a < 0 || ad->b < 0 || ad->c < 0 || ad->d < 0)
    {
        printf("Ce n'est pas un addresse ip\n");
        exit(EXIT_SUCCESS);
    }

    URL1=getenv("QUERY_STRING");
    sscanf(URL1,"ip=%[^.].%[^.].%[^.].%[^.]",address1 ,address2 ,address3 ,address4);
    printf("%s",address1);
}
void check_ip(ip *ad)
{

    if(ad->a >= 0 && ad->a < 128)
    {
        printf("L'addresse ip %d.%d.%d.%d est de class A \n",ad->a,ad->b,ad->c,ad->d);
    }

    else if(ad->a >= 128 && ad->a < 192)
    {
        printf("L'addresse ip %d.%d.%d.%d est de class B \n",ad->a,ad->b,ad->c,ad->d);
    }

    else if(ad->a >= 192 && ad->a < 224)
    {
        printf("L'addresse ip %d.%d.%d.%d est de class C \n",ad->a,ad->b,ad->c,ad->d);
    }

    else if(ad->a >= 224 && ad->a < 240)
    {
        printf("L'addresse ip %d.%d.%d.%d est de class D \n",ad->a,ad->b,ad->c,ad->d);
    }

    else if(ad->a >= 240 && ad->a <= 255)
    {
        printf("L'addresse ip %d.%d.%d.%d est de class E \n",ad->a,ad->b,ad->c,ad->d);
    }
}
void page_foot()
{
    printf("</p></body>");
    printf("</html>");    
}