//
// Created by hasee on 2019/10/22.
//

#include <math.h>
#include "PalindromeNum.h"


bool isPalindrome(int x){
    if (x < 0)
        return false;
    int srcNum = x;
    long long reversedNum = 0;
    int digit = 0;

    do{
        digit = srcNum % 10;
        reversedNum = reversedNum * 10 + digit;
        srcNum /= 10;
    }while (srcNum != 0);

    if (x == reversedNum)
        return true;
    else
        return false;
}

bool isPalindrome2( int x )
{
    if( x < 0) return 0;
    int size = (int) log10(x );
    int max = (int) pow(10, size );
    int offset = 1;
    for( int i = 0; i < ( size + 1 ) / 2; ++i )
    {
        if( x % (10 * offset ) / offset != x / ( max / offset ) % 10 )
            return 0;
        offset *= 10;
    }
    return 1;
}
