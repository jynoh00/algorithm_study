#include <stdio.h>

int main(){
    unsigned short IPv4_Pseudo_Header[] = {
        // IPv4 Header
        0xc0ff, 0xff32, // c0 ff ff 32 => Source IP Address : 192.255.255.50
        0xc0ff, 0xff33, // c0 ff ff 33 => Destination IP Address : 192.255.255.51
        0x0011,         // Zero(0x00), Protocol(0x11)
        0x000c,         // UDP Length

        // UDP Header
        0xa45c,         // a4 5c => Source Port : 0xa45c = 42076
        0x270f,         // 27 0f => Destination Port : 0x270f = 9999
        0x000c,         // UDP Length
        0x7465, 0x7374  // 74 65 73 74 => "test"
    };

    printf("IPv4 Header Checksum\n");

    // step 1. summation
    int sum = 0;
    for(int i = 0; i < sizeof(IPv4_Pseudo_Header) / 2; i++){
        sum += IPv4_Pseudo_Header[i];
    }

    printf("sum : %#x\n", sum);

    // step 2. bit[:15] + bit[16:19]
    int carry_bit = (sum & 0xF0000) >> 16;
    int result = (sum & 0xFFFF) + carry_bit;

    printf("result : %#x\n", result);

    // step 3. ones' complement
    int checksum = ~result;
    checksum &= 0xFFFF;
    printf("checksum : %#x\n", checksum);

    return 0;
}