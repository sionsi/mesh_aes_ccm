#include <assert.h>
#include <string.h>

#include "aes.h"
#include "common.h"

#define NONCE_LEN 13

void test_encrypt_rfc3610_data_1(void) {

    uint8_t nonce[13] = {0x00, 0x00, 0x00, 0x03, 0x02, 0x01, 0x00, 0xA0, 0xA1,
                         0xA2, 0xA3, 0xA4, 0xA5};
    mesh_print_array("nonce: ", nonce, 13);

    // sample data session key:
    uint8_t sk[16] = {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8,
                      0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF};
    mesh_print_array("sk: ", sk, 16);

    // sample data message

    uint8_t pbuf[32] = {0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10,
                        0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,
                        0x1A, 0x1B, 0x1C, 0x1D, 0x1E};
    mesh_print_array("plaintext: ", pbuf, 32);



    // sample data MAC
    uint8_t adata[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};

    uint8_t out[32];
#define MAC_LENGH 8
    uint8_t auth_out[MAC_LENGH] = { 0x00};

    MESH_DEBUG("%s, start", __func__);
    int r = aes_ccm_ae(sk, 16, nonce,
                   MAC_LENGH, pbuf, 23,
                   adata, 8, out, auth_out);
    // b5e5bfdacbaf6cb7fb6bff871f
    MESH_DEBUG("r=%d", r);
    mesh_print_array("out: ", out, 23);
    mesh_print_array("auth_out: ", auth_out, MAC_LENGH);
}


void test_encrypt_mesh(void) {
#define PLAIN_TEXT_LEN 11
#define MAC_LENGH 8
#define AAD_LENGTH 0
    char *nonce_str = "00800148202345000012345678";
    uint8_t nonce[13] = {0};
    string2digit_no_reverse(nonce_str, nonce);
    mesh_print_array("nonce= ", nonce, 13);

    // sample data session key:
    char *sk_str = "0953fa93e7caac9638f58820220a398e";
    uint8_t sk[16] = {0};
    string2digit_no_reverse(sk_str, sk);
    mesh_print_array("sk= ", sk, 16);

    // sample data message

    char *pbuf_str = "120104320308ba072f";
    uint8_t plain_len = strlen(pbuf_str)/2;
    uint8_t pbuf[32] = {0};
    string2digit_no_reverse(pbuf_str, pbuf);
    mesh_print_array("pbuf= ", pbuf, plain_len);



    // sample data MAC
    uint8_t adata[16] = {0};
    uint8_t out[32];
    uint8_t auth_out[MAC_LENGH] = { 0x00};

    MESH_DEBUG("%s, start", __func__);
    int r = aes_ccm_ae(sk, 16, nonce,
                   MAC_LENGH, pbuf, plain_len,
                   adata, AAD_LENGTH, out, auth_out);
    MESH_DEBUG("r=%d", r);
    mesh_print_array("out= ", out, plain_len);
    mesh_print_array("auth_out: ", auth_out, MAC_LENGH);
}


int main(void) {
//    test_encrypt_rfc3610_data_1();    // verified ok based on rfc3610 test vector #1
    test_encrypt_mesh();
    return 0;
}
