#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include "common.h"




void *GKI_getbuf (UINT16 size)
{
  UINT8 *header = malloc(size);
  return header;
}

void GKI_freebuf (void *p_buf)
{
  free(p_buf);
}


void printArrayBigEndian(uint8_t *array, uint8_t len)
{
    int pp_len = len * 3 + 1;
    int xx;
    char *pp = malloc(pp_len);
    memset(pp, 0, pp_len);
    for(xx = 0; xx < len; xx++) {
        snprintf(pp + 3*xx, pp_len, "%02x ", array[len - 1 -xx]);
    }
    MESH_PRINT("len=%d, pp=%s", len, pp);
    free(pp);
}

void printArrayLittleEndian(uint8_t *array, uint8_t len)
{
    int pp_len = len * 3 + 1;
    int xx;
    char *pp = malloc(pp_len);
    memset(pp, 0, pp_len);
    for(xx = 0; xx < len; xx++) {
        snprintf(pp + 3*xx, pp_len, "%02x ", array[xx]);
    }
    MESH_PRINT("len=%d, pp=%s", len, pp);
    free(pp);
}

void reverse_arrary(uint8_t *dig, int len)
{
    uint8_t tmp = 0;
    int xx = 0;
    int half = len/2;
    for(xx =0; xx < half; xx++) {
        tmp = dig[xx];
        dig[xx] = dig[len-xx-1];
        dig[len-xx-1] = tmp;
    }
}

void string2digit(char *hexstring, uint8_t *dig)
{
    char *pos = hexstring;
    int total_size = strlen(hexstring)/2;
    MESH_PRINT("total_size=%d", total_size);

    int count = 0;
    for(count = 0; count < total_size; count++) {
        sscanf(pos, "%2hhx", &dig[count]);
        pos += 2;
    }
    reverse_arrary(dig, total_size);
}

void string2digit_no_reverse(char *hexstring, uint8_t *dig)
{
    char *pos = hexstring;
    int total_size = strlen(hexstring)/2;
//    MESH_PRINT("total_size=%d", total_size);

    int count = 0;
    for(count = 0; count < total_size; count++) {
        sscanf(pos, "%2hhx", &dig[count]);
        pos += 2;
    }
}


void mesh_print_array_big(char *name, uint8_t *array, uint8_t len)
{
    uint8_t pp_len = len * 2 + 1;
    int xx;
    char *pp = malloc(pp_len);
    memset(pp, 0, pp_len);
    for(xx = 0; xx < len; xx++) {
        snprintf(pp + 2*xx, pp_len, "%02x", array[len - 1 - xx]);
    }
    MESH_PRINT("%s: %s", name, pp);
    free(pp);
}


void mesh_print_array(char *name, uint8_t *array, uint8_t len)
{
    uint8_t pp_len = len * 2 + 1;
    int xx;
    char *pp = malloc(pp_len);
    memset(pp, 0, pp_len);
    for(xx = 0; xx < len; xx++) {
        snprintf(pp + 2*xx, pp_len, "%02x", array[xx]);
    }
    MESH_PRINT("%s %s", name, pp);
    free(pp);
}
