#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Forward declarations
void oct_to_bin(const char *oct, char *out);
void oct_to_hex(const char *oct, char *out);
void hex_to_bin(const char *hex, char *out);
void to_sign_magnitude(int32_t n, char *out);
void to_ones_complement(int32_t n, char *out);
void to_twos_complement(int32_t n, char *out);

typedef struct {
    char function[50];
    char input1[100];
    char expected[100];
} TestCase;

int run_test(int index, TestCase t) {
    char actual[200];
    if (strcmp(t.function, "oct_to_bin") == 0) {
        oct_to_bin(t.input1, actual);
    } else if (strcmp(t.function, "oct_to_hex") == 0) {
        oct_to_hex(t.input1, actual);
    } else if (strcmp(t.function, "hex_to_bin") == 0) {
        hex_to_bin(t.input1, actual);
    } else if (strcmp(t.function, "to_sign_magnitude") == 0) {
        int32_t n = atoi(t.input1);
        to_sign_magnitude(n, actual);
    } else if (strcmp(t.function, "to_ones_complement") == 0) {
        int32_t n = atoi(t.input1);
        to_ones_complement(n, actual);
    } else if (strcmp(t.function, "to_twos_complement") == 0) {
        int32_t n = atoi(t.input1);
        to_twos_complement(n, actual);
    } else {
        printf("Unknown function: %s\n", t.function);
        return 0;
    }

    int pass = strcmp(actual, t.expected) == 0;
    printf("Test %d: %s(%s) -> Expected: \"%s\", Got: \"%s\" [%s]\n",
           index, t.function, t.input1, t.expected, actual,
           pass ? "PASS" : "FAIL");
    return pass;
}

int main() {
    FILE *f = fopen("a2_test.txt", "r");
    if (!f) {
        printf("Could not open test file.\n");
        return 1;
    }

    char line[300];
    int test_num = 1, passed = 0, total = 0;
    while (fgets(line, sizeof(line), f)) {
        if (line[0] == '#' || strlen(line) < 2) continue;
        TestCase t;
        strcpy(t.input1, "");
        strcpy(t.expected, "");

        char input2[100]; // not used but matches format
        int count = sscanf(line, "%s %s %s", t.function, t.input1, t.expected);
        if (count < 3) continue;

        if (run_test(test_num, t)) passed++;
        total++;
        test_num++;
    }
    fclose(f);

    printf("Summary: %d/%d tests passed\n", passed, total);
    return 0;
}
