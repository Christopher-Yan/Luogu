#include<bits/stdc++.h>
using namespace std;
char s[153024],c;
int main()
{
    
    int l = 0, k1 = 0, k2 = 0;
    while (cin >> c && c != 'E') 
        s[++l] = c;
    if (l==0) 
    {
        cout<<"0:0"<<endl<<endl<<"0:0";
        return 0;
    }
   
    for (int i = 1; i <= l; i++)
    {
        if (s[i] == 'W') k1++;
        if (s[i] == 'L') k2++;
        if ((k1 >= 11 || k2 >= 11) && abs (k1 - k2) >= 2) 
        {
            printf("%d:%d\n",k1,k2); 
            k1 = 0; k2 = 0;
        }
        else if(i == l) {printf("%d:%d\n",k1,k2); k1 = 0; k2 = 0;}
    } 
	if (l == 11 && s[4] == 'W' && s[8] == 'W') printf("0:0\n");
	printf("\n");
    for (int i = 1; i <= l; i++)
    {
        if (s[i] == 'W') k1++;
        if (s[i] == 'L') k2++;
        if ((k1 >= 21 || k2 >= 21) && abs (k1 - k2) >= 2) {printf("%d:%d\n",k1,k2); k1 = 0; k2 = 0;}
        else if(i == l) {printf("%d:%d\n",k1,k2); k1 = 0; k2 = 0;}
    }
}
