#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

// Octal to Binary
void oct_to_bin(const char *oct, char *out) {
    int len = strlen(oct);
    int pos = 0;
    for (int i = 0; i < len; i++) {
        int digit = oct[i] - '0';
        out[pos++] = ((digit >> 2) & 1) ? '1' : '0';
        out[pos++] = ((digit >> 1) & 1) ? '1' : '0';
        out[pos++] = ((digit >> 0) & 1) ? '1' : '0';
    }
    out[pos] = '\0';
}

// Octal to Hex 
void oct_to_hex(const char *oct, char *out) {
    char bin[200];
    oct_to_bin(oct, bin);

    int len = strlen(bin);
    int pad = (4 - (len % 4)) % 4;
    char padded[200];
    for (int i = 0; i < pad; i++) padded[i] = '0';
    strcpy(padded + pad, bin);

    int padded_len = strlen(padded);
    int pos = 0;
    for (int i = 0; i < padded_len; i += 4) {
        int val = 0;
        for (int j = 0; j < 4; j++) {
            val = (val << 1) | (padded[i + j] - '0');
        }
        if (val < 10) out[pos++] = '0' + val;
        else out[pos++] = 'A' + (val - 10);
    }
    out[pos] = '\0';
}

// Hex to Binary
void hex_to_bin(const char *hex, char *out) {
    int pos = 0;
    for (int i = 0; hex[i] != '\0'; i++) {
        char c = hex[i];
        int val;
        if (c >= '0' && c <= '9') val = c - '0';
        else if (c >= 'A' && c <= 'F') val = 10 + (c - 'A');
        else if (c >= 'a' && c <= 'f') val = 10 + (c - 'a');
        else continue;

        out[pos++] = (val & 8) ? '1' : '0';
        out[pos++] = (val & 4) ? '1' : '0';
        out[pos++] = (val & 2) ? '1' : '0';
        out[pos++] = (val & 1) ? '1' : '0';
    }
    out[pos] = '\0';
}

// Convert uint32_t to 32-bit binary string
void to_32bit_binary(uint32_t value, char *out) {
    for (int i = 31; i >= 0; i--) {
        out[31 - i] = ((value >> i) & 1) ? '1' : '0';
    }
    out[32] = '\0';
}

// Sign Magnitude
void to_sign_magnitude(int32_t n, char *out) {
    if (n >= 0) {
        to_32bit_binary((uint32_t)n, out);
    } else {
        uint32_t mag = (uint32_t)(-n);
        to_32bit_binary(mag, out);
        out[0] = '1'; // set sign bit
    }
}

//  One Complement
void to_ones_complement(int32_t n, char *out) {
    if (n >= 0) {
        to_32bit_binary((uint32_t)n, out);
    } else {
        uint32_t mag = (uint32_t)(-n);
        to_32bit_binary(mag, out);
        for (int i = 0; i < 32; i++) {
            out[i] = (out[i] == '0') ? '1' : '0';
        }
    }
}

// Two's Complement
void to_twos_complement(int32_t n, char *out) {
    uint32_t val = (uint32_t)n;
    to_32bit_binary(val, out);
}
