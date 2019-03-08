#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define oops(m) {perror(m); exit(1);}
#define BIT_HEADER_SIZE 14
#define BMP_HEADER_SIZE_SIZE 4
#define uint8_t unsigned char
typedef unsigned long int  uint64_t;
typedef unsigned int       uint32_t;

typedef long LONG;
typedef unsigned long DWORD;
typedef unsigned short WORD;



typedef struct bmpInfo {
	uint8_t type;
	int img_width;
	int img_height;
	uint8_t * rgbData;
} BmpInfo;


typedef struct
{
	WORD    bfType;
	DWORD   bfSize;
	WORD    bfReserved1;
	WORD    bfReserved2;
	DWORD   bfOffBits;
} BMPFILEHEADER_T;


typedef struct
{
	DWORD      biSize;
	LONG       biWidth;
	LONG       biHeight;
	WORD       biPlanes;
	WORD       biBitCount;
	DWORD      biCompression;
	DWORD      biSizeImage;
	LONG       biXPelsPerMeter;
	LONG       biYPelsPerMeter;
	DWORD      biClrUsed;
	DWORD      biClrImportant;
} BMPINFOHEADER_T;


BmpInfo * readBmp(char * path);

void readBmpHeader(FILE * bmpfile);
void readBmpInfoHeader(FILE * bmpfile);
uint8_t * getRgbData(FILE * bmpfile);
uint8_t * getRgbaData(FILE * bmpfile);