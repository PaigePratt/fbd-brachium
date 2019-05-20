/* ========================================

util.h: misc utilites and preprocessor defs

 * ========================================
*/

#ifndef UTIL
#define UTIL
    
    //bytes to larger type conversions
    
    //bytes to int
    #define PACK_CHARS_INTO_INT(a, b, c, d) ((a << 24) | (b << 16) | (c << 8) | d)
    #define PACK_ARRAY_OFF_CHARS_INTO_INT(var, i) PACK_CHARS_INTO_INT(var[i], var[i+1], var[i+2], var[i+3])
    #define UNPACK_INT_INTO_CHARS(var, a, b, c, d) \
        a = (var << 24) & 0xFF;\
        b = (var << 16) & 0xFF;\
        c = (var << 8) & 0xFF; \
        d = var & 0xFF
    #define DUMP_INT_TO_CHAR_ARRAY(integer, arr, i) UNPACK_INT_INTO_CHARS(integer, arr[i], arr[i+1] arr[i+2], arr[i+3])
    
    //bytes to short
    #define PACK_CHARS_INT_SHORT(a, b) (short)PACK_CHARS_INTO_INT(0, 0, a, b)
    #define UNPACK_SHORT_INTO_CHARS(var, a, b) \
        a = (var << 8) & 0xFF;\
        b = var & 0xFF
    
    
    
#endif
/* [] END OF FILE */
