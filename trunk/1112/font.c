
#include <stdio.h>	


unsigned char three[]={
    /* 51 0x33 '3' */
    0x00, /*          */
    0x00, /*          */
    0x7c, /*  11111   */
    0xc6, /* 11   11  */
    0x06, /*      11  */
    0x06, /*      11  */
    0x3c, /*   1111   */
    0x06, /*      11  */
    0x06, /*      11  */
    0x06, /*      11  */
    0xc6, /* 11   11  */
    0x7c, /*  11111   */
    0x00, /*          */
    0x00, /* 00000000 */
    0x00, /* 00000000 */
    0x00, /* 00000000 */
};

void display_char (unsigned char c)
{
	int i;
	
	for (i = 7; i >= 0 ; i--)
	{
		if (c & (1<<i))
			printf("1");
		else 
			printf(" ");
	}
	printf("\n");
	
}

int main(int argc , char *argv[])	
{
	int i;

	for (i=0 ; i < sizeof(three);i++)	
			display_char (three[i]);
	return 0;
}

