#ifndef SVPNG_H
#define SVPNG_H
#include<stdio.h>
#include<functional>
using std::function;

/*
将数组写入文件变成PNG图片

https://github.com/miloyip/svpng
*/

inline void svpng(FILE* fp, unsigned w, unsigned h, const unsigned char* img);

#endif
