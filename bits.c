/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~((~x)|(~y));
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return (~(x&y)&~((~x)&(~y)));
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if((x)&&(!y))return 0;
    if((!x)&&(y))return 0;
    else{
    x=x>>31;
    y=y>>31;
    return !(x^y);
    }
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int x=(v>>16);
    int panduan16=(x>0)<<4;v=(v>>panduan16);
    x=(v>>8);
    int panduan8=(x>0)<<3;v=(v>>panduan8);
    x=(v>>4);
    int panduan4=(x>0)<<2;v=(v>>panduan4);
    x=(v>>2);
    int panduan2=(x>0)<<1;v=(v>>panduan2);
    x=(v>>1);
    int panduan1=(x>0);
    return (panduan16|panduan8|panduan4|panduan2|panduan1);
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2   
 */
int byteSwap(int x, int n, int m) {
    int y=x,jump_lo=n<<3,jump_hi=m<<3,clear_hi,clear_lo;
    int lo=y&(clear_hi=(0xFF<<jump_lo)),hi=y&(clear_lo=(0xFF<<jump_hi));
    y=y^lo^hi;
    y=y|((lo>>jump_lo<<jump_hi)&clear_lo)|((hi>>jump_hi<<jump_lo)&clear_hi);
    return y;
} 
 
/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    unsigned int hi=(1<<31),lo=1,pianyiliang=15;
    for(int i=16;i;i--){
        unsigned int x=((v&hi)>>(i+pianyiliang));
        unsigned int y=((v&lo)<<(i+pianyiliang));
        v=v&(~(hi+lo));
        v=v|x|y;
        hi=hi>>1;
        lo=lo<<1;
        pianyiliang--;
    }
    return v;
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int yanma1=((1<<31)&x)>>n;
    int pianyiliang=32+(~n);
    int yanma2=((x>>31)&1)<<pianyiliang;
    int raw=x>>n;
    return (raw^yanma1)|yanma2;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int v=x;
    int panduan16=(v>>16),bit_num=((!!(~panduan16))<<4);
    v=v>>bit_num;
    int panduan8=v>>8;bit_num+=((!!(~panduan8))<<3);
    v=v>>((!!(~panduan8))<<3);
    int panduan4=v>>4;bit_num+=((!!(~panduan4))<<2);
    v=v>>((!!(~panduan4))<<2);
    int panduan2=v>>2;bit_num+=((!!(~panduan2))<<1);
    v=v>>((!!(~panduan2))<<1);
    bit_num+=!!(~(v>>1));
    int n=32+(~bit_num);
    int yanma=1&x;
    n+=(!bit_num)&yanma;
    return n;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    int sign=(1<<31)&x;
    int v=x;
    int mi_of_2=0;
    int jieduan=0;
    if(sign)v=(~x)+1;
    if(v==0)return 0;
    while(!(v&0x80000000)){
        v=v<<1;
        mi_of_2++;
    }
    mi_of_2=31-mi_of_2;
    int jiema=(mi_of_2+127)<<23;
    int jingdu=(0x7FFFFF00&v)>>8;
    int raw_float=sign|jiema|jingdu;
    jieduan=0xFF&v;
    if(jieduan<0x80){
       return raw_float;
    }
    else if(jieduan>0x80){
        return raw_float+1;
    }
    else{
        if((raw_float&1)==1)return raw_float+1;
        else return raw_float;
    }
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    int yima=(0x7f800000&uf)>>23;
    int sign=(1<<31)&uf;
    int weishu=0x7fffff&uf;
    if(!yima){
        if(weishu==0){
            return uf;
        }
        else{
            weishu=weishu<<1;
            return sign|yima|weishu;
        }
    }
    if(yima==0xff)return uf;
    yima++;
    yima=yima<<23;
    int outcome=sign|yima|weishu;
    return outcome;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    int sign=(uf2>>31)&1;
    int yima=(0x7ff00000&uf2)>>20;
    int yuanma=yima-1023;
    int weishu2=0x000fffff&uf2,weishu1=uf1;
    int n_part;
    if(!~yima)return 0x80000000;
    if(!yima){
        return 0;
    }
    if(!(sign-1)){
        if(!(yuanma-63)){
            if(!weishu1)if(!weishu2)return 0x80000000;
        }
    }
    if(yuanma<0)return 0;
    else if(yuanma>=0)if(yuanma<=20){
        n_part=(weishu2|0x001fffff)>>(20-yuanma);
    }
    else if(yuanma>20)if(yuanma<31){
        yuanma-=20;
        weishu1=weishu1>>(32-yuanma);
        weishu2=weishu2<<yuanma;
        n_part=weishu1|weishu2;
    }
    else if(yuanma>=31)return 0x80000000;
    
    if(sign)return -n_part;
    else return n_part;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    int yima;
    int weishu;
    if(x<-149)return 0;
    else if(x>127)return 0x7f800000;
    if((x<=-127)){
        yima=0;
        int shuwei=-126-x;
        weishu=1<<(23-shuwei);
        return weishu;
    }
    yima=x+127;
    return yima<<23; 
}
