#ifndef SVPNG_H
#define SVPNG_H
#include<stdio.h>
#include<functional>
using std::function;

/*
������д���ļ����PNGͼƬ

https://github.com/miloyip/svpng
*/

inline void svpng(FILE* fp, unsigned w, unsigned h, const unsigned char* img);

#endif
