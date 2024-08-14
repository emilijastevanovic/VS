#include "test_b64.h"

void Test_b64_decode(CuTest *tc)
{
    // Primer jednostavnog testa za b64_decode funkciju
    const char *input = "SGVsbG8gd29ybGQ="; // "Hello world" base64 encoded
    const char *expected = "Hello world";
    size_t out_len;
    uint8_t *decoded = b64_decode((const uint8_t*)input, strlen(input), &out_len);

    CuAssertStrEquals(tc, expected, (const char*)decoded);

    free(decoded); // Oslobodite memoriju
}

void Test_b64_encode(CuTest *tc)
{
    // Primer jednostavnog testa za b64_encode funkciju
    const uint8_t *input = (const uint8_t*)"Hello world";
    const char *expected = "SGVsbG8gd29ybGQ=";
    size_t out_len;
    char *encoded = b64_encode(input, strlen((const char*)input), &out_len);

    CuAssertStrEquals(tc, expected, encoded);

    free(encoded); // Oslobodite memoriju
}

CuSuite* TestSuite_b64(void)
{
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, Test_b64_decode);
    SUITE_ADD_TEST(suite, Test_b64_encode);
    return suite;
}

