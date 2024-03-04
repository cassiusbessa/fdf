#include "fdf.h"

void swap(int* a , int*b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
// returns absolute value of number 
/*float absolute(float x ) 
{ 
    if (x < 0) return -x; 
    else return x; 
}*/
  
//returns integer part of a floating point number 
int iPartOfNumber(float x) 
{ 
    return (int)x; 
} 
  
//rounds off a number 
int roundNumber(float x) 
{ 
    return iPartOfNumber(x + 0.5) ; 
} 
  
//returns fractional part of a number 
float fPartOfNumber(float x) 
{ 
    if (x>0) return x - iPartOfNumber(x); 
    else return x - (iPartOfNumber(x)+1); 
  
} 
  
//returns 1 - fractional part of number 
float rfPartOfNumber(float x) 
{ 
    return 1 - fPartOfNumber(x); 
} 
  
// draws a pixel on screen of given brightness 
// 0<=brightness<=1. We can use your own library 
// to draw on screen 
  
void drawAALine(t_mlx_data m, int x0 , int y0 , int x1 , int y1) 
{ 
    int steep = absolute(y1 - y0) > absolute(x1 - x0) ; 
  
    // swap the co-ordinates if slope > 1 or we 
    // draw backwards 
    if (steep) 
    { 
        swap(&x0 , &y0); 
        swap(&x1 , &y1); 
    } 
    if (x0 > x1) 
    { 
        swap(&x0 ,&x1); 
        swap(&y0 ,&y1); 
    } 
  
    //compute the slope 
    float dx = x1-x0; 
    float dy = y1-y0; 
    float gradient = dy/dx; 
    if (dx == 0.0) 
        gradient = 1; 
  
    int xpxl1 = x0; 
    int xpxl2 = x1; 
    float intersectY = y0; 
  
    // main loop 
    if (steep) 
    { 
        int x; 
        for (x = xpxl1 ; x <=xpxl2 ; x++) 
        { 
            // pixel coverage is determined by fractional 
            // part of y co-ordinate 
            draw_pixel(m, iPartOfNumber(intersectY), x, 
                        rfPartOfNumber(intersectY)); 
            draw_pixel(m, iPartOfNumber(intersectY)-1, x, 
                        fPartOfNumber(intersectY)); 
            intersectY += gradient; 
        } 
    } 
    else
    { 
        int x; 
        for (x = xpxl1 ; x <=xpxl2 ; x++) 
        { 
            // pixel coverage is determined by fractional 
            // part of y co-ordinate 
            draw_pixel(m, x, iPartOfNumber(intersectY), 
                        rfPartOfNumber(intersectY)); 
            draw_pixel(m, x, iPartOfNumber(intersectY)-1, 
                          fPartOfNumber(intersectY)); 
            intersectY += gradient; 
        } 
    } 
  
} 