#include "CuTest.h"
#include <stdio.h>

// Uključite zaglavlje testova koje ste napravili
#include "test_b64.h"

// Funkcija koja izvršava sve testove i ispisuje rezultate
void RunAllTests(void)
{
    CuString *output = CuStringNew();
    CuSuite *suite = CuSuiteNew();

    // Dodajte testove u suit
    CuSuiteAddSuite(suite, TestSuite_b64());

    // Pokrenite sve testove
    CuSuiteRun(suite);

    // Ispišite rezultate
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);

    // Očistite memoriju
    CuSuiteDelete(suite);
    CuStringDelete(output);
}

int main(void)
{
    RunAllTests();
    return 0;
}

