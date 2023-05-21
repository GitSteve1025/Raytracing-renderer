#include"SVPNG.h"

inline void svpng(FILE* fp, unsigned w, unsigned h, const unsigned char* img)
{
	unsigned a = 1, b = 0, c, p = w * 3 + 1;
	static const unsigned t[] = { 0, 0x1db71064, 0x3b6e20c8, 0x26d930ac, 0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c, 0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c, 0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c };
	function<void(unsigned)> SVPNG_PUT = [&](unsigned u)
	{
		fputc(u, fp);
	};
	
	function<void(const char[], unsigned)> SVPNG_U8A = [&](const char ua[], unsigned l)
	{
		for (unsigned i = 0; i < l; i++)
		{
			SVPNG_PUT(ua[i]);
		}
	};

	function<void(unsigned)> SVPNG_U32 = [&](unsigned u)
	{
		SVPNG_PUT(u >> 24);
		SVPNG_PUT((u >> 16) & 255);
		SVPNG_PUT((u >> 8) & 255);
		SVPNG_PUT(u & 255);
	};

	function<void(unsigned)> SVPNG_U8C = [&](unsigned u)
	{
		SVPNG_PUT(u);
		c ^= u;
		c = (c >> 4) ^ t[c & 15];
		c = (c >> 4) ^ t[c & 15];
	};

	function<void(const char[], unsigned)> SVPNG_U8AC = [&](const char ua[], unsigned l)
	{
		for (unsigned i = 0; i < l; i++)
		{
			SVPNG_U8C(ua[i]);
		}
	};

	function<void(unsigned)> SVPNG_U16LC = [&](unsigned u)
	{
		SVPNG_U8C(u & 255);
		SVPNG_U8C((u >> 8) & 255);
	};

	function<void(unsigned)> SVPNG_U32C = [&](unsigned u)
	{
		SVPNG_U8C(u >> 24);
		SVPNG_U8C((u >> 16) & 255);
		SVPNG_U8C((u >> 8) & 255);
		SVPNG_U8C(u & 255);
	};

	function<void(unsigned)> SVPNG_U8ADLER = [&](unsigned u)
	{
		SVPNG_U8C(u);
		a = (a + u) % 65521;
		b = (b + a) % 65521;
	};

	function<void(const char[], unsigned)> SVPNG_BEGIN = [&](const char s[], unsigned l)
	{
		SVPNG_U32(l);
		c = ~0U;
		SVPNG_U8AC(s, 4);
	};

	function<void()> SVPNG_END = [&]()
	{
		SVPNG_U32(~c);
	};

	SVPNG_U8A("\x89PNG\r\n\32\n", 8);           
	SVPNG_BEGIN("IHDR", 13);                    
	SVPNG_U32C(w);
	SVPNG_U32C(h);               /*   Width & Height (8 bytes) */
	SVPNG_U8C(8);
	SVPNG_U8C(2);     
	SVPNG_U8AC("\0\0\0", 3);                    
	SVPNG_END();                                
	SVPNG_BEGIN("IDAT", 2 + h * (5 + p) + 4);   
	SVPNG_U8AC("\x78\1", 2);                    
	for (unsigned y = 0; y < h; y++) 
	{                   
		SVPNG_U8C(y == h - 1);                  
		SVPNG_U16LC(p);
		SVPNG_U16LC(~p);        
		SVPNG_U8ADLER(0);                      
		for (unsigned x = 0; x < p - 1; x++, img++)
		{
			SVPNG_U8ADLER(*img);
		}
	}
	SVPNG_U32C((b << 16) | a);                  
	SVPNG_END();                                
	SVPNG_BEGIN("IEND", 0);
	SVPNG_END();
}
