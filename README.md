# mesh_aes_ccm
mesh aes ccm cryption sample code, based on mesh profile section 8.3.2 Message #2.

test logs as below
`make clean && make && ./test 
  rm -f test aes.o common.o aes-ccm.o aes-enc.o test.o
  gcc -Wall -g   -c -o aes.o aes.c
  gcc -Wall -g   -c -o common.o common.c
  gcc -Wall -g   -c -o aes-ccm.o aes-ccm.c
  gcc -Wall -g   -c -o aes-enc.o aes-enc.c
  gcc -Wall -g   -c -o test.o test.c
  gcc -Wall -g -o test aes.o common.o aes-ccm.o aes-enc.o test.o
  mesh_print_array nonce=  00800148202345000012345678
  mesh_print_array sk=  0953fa93e7caac9638f58820220a398e
  mesh_print_array pbuf=  120104320308ba072f
  test_encrypt_mesh, start
  aes_ccm_auth_start aad_len=0
  aes_ccm_auth_start b[0]=19
  aes_ccm_auth_start b[14]=00,   b[15]=09
  mesh_print_array b0= 19008001482023450000123456780009
  mesh_print_array x1= 3cb2d58e79a31aa98fbe4e410d2ba261
  aes_ccm_auth last=9
  mesh_print_array x: 2eb3d1bc7aaba0aea0be4e410d2ba261
  mesh_print_array x: bf5fc8010d268bff8bd2988e8244b060
  mesh_print_array out: 000000000000000020
  mesh_print_array a: 01008001482023450000123456780000
  mesh_print_array a: 01008001482023450000123456780001
  mesh_print_array out: 6bd6dff2cabc6e39c43794c4d4988d19
  mesh_print_array cyphered: 79d7dbc0c9b4d43eeb
  aes_ccm_encr aes_ccm_encr end
  mesh_print_array a: 01008001482023450000123456780000
  mesh_print_array tmp: 534d5521ab065be1c28da92b4458b211
  mesh_print_array x: bf5fc8010d268bff8bd2988e8244b060
  mesh_print_array auth: ec129d20a620d01e007a3a7cccb18a57
  r=0
  mesh_print_array out=  79d7dbc0c9b4d43eeb
  mesh_print_array auth_out:  ec129d20a620d01e`
