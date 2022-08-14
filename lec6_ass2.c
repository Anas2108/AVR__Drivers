#include <stdio.h>
int main (void){

int x=1,y=2,z=3;
int *p=&x, *q=&y , *r=&z;

printf("the value of x : %d\nthe value of y : %d\nthe value of z : %d\nthe value of p : %d\nthe value of q : %d\nthe value of r : %d\nthe value of *p : %d\nthe value of *q : %d\nthe value of *r : %d",x,y,z,p,q,r,*p,*q,*r);

printf("\nswapping pointers\n");
r = p; p = q; q = r;

printf("the value of x : %d\nthe value of y : %d\nthe value of z : %d\nthe value of p : %d\nthe value of q : %d\nthe value of r : %d\nthe value of *p : %d\nthe value of *q : %d\nthe value of *r : %d",x,y,z,p,q,r,*p,*q,*r);
}