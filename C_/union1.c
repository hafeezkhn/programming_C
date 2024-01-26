#include<stdio.h>
typedef struct full{
	unsigned char x:2;
        unsigned char y:2;
        unsigned char z:2;

}Complete_t;
typedef struct half{
	unsigned char x1:1;
	unsigned char x2:1;
	unsigned char y1:1;
	unsigned char y2:1;
	unsigned char z1:1;
	unsigned char z2:1;
}section_t;

typedef union {
	section_t *coord;
	Complete_t *co;
}uni;

Complete_t A={0,1,2};
uni Ax = {.co=&A};

int main()
{
printf("%u",Ax.coord->x1);
printf("%u",Ax.coord->x2);
printf("%u",Ax.coord->y1);
printf("%u",Ax.coord->y2);
printf("%u",Ax.coord->z1);
printf("%u",Ax.coord->z2);

	return 0;
}


