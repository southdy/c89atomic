/*
Tests basic logic of all atomic functions. Does not test atomicity.
*/
#include "../c89atomic.h"
#include <stdio.h>


void c89atomic_test__basic__flag_test_and_set()
{
    printf("c89atomic_flag_test_and_set():\n");

    printf("    c89atomic_flag_test_and_set:          ");
    {
        c89atomic_flag a = 0;
        c89atomic_flag b = 0;
        c89atomic_bool r = c89atomic_flag_test_and_set(&b);

        if (a == r && b == 1) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("\n");
}

void c89atomic_test__basic__flag_clear()
{
    printf("c89atomic_flag_clear():\n");

    printf("    c89atomic_flag_clear:                 ");
    {
        c89atomic_flag a = 1;
        c89atomic_flag_clear(&a);

        if (a == 0) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("\n");
}


void c89atomic_test__basic__load()
{
    printf("c89atomic_load_*():\n");

    printf("    c89atomic_load_8:                     ");
    {
        c89atomic_uint8 a = 123;
        c89atomic_uint8 b = c89atomic_load_8(&a);
        if (b == a) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_load_16:                    ");
    {
        c89atomic_uint16 a = 1234;
        c89atomic_uint16 b = c89atomic_load_16(&a);
        if (b == a) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_load_32:                    ");
    {
        c89atomic_uint32 a = 123456;
        c89atomic_uint32 b = c89atomic_load_32(&a);
        if (b == a) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_load_64:                    ");
    {
        c89atomic_uint64 a = 123456789012;
        c89atomic_uint64 b = c89atomic_load_64(&a);
        if (b == a) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("\n");
}

void c89atomic_test__basic__store()
{
    printf("c89atomic_store_*():\n");

    printf("    c89atomic_store_8:                    ");
    {
        c89atomic_uint8 a = 0;
        c89atomic_uint8 b = 123;
        c89atomic_store_8(&a, b);

        if (b == a) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_store_16:                   ");
    {
        c89atomic_uint16 a = 0;
        c89atomic_uint16 b = 1234;
        c89atomic_store_16(&a, b);

        if (b == a) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_store_32:                   ");
    {
        c89atomic_uint32 a = 0;
        c89atomic_uint32 b = 123456;
        c89atomic_store_32(&a, b);

        if (b == a) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_store_64:                   ");
    {
        c89atomic_uint64 a = 0;
        c89atomic_uint64 b = 123456789012;
        c89atomic_store_64(&a, b);

        if (b == a) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("\n");
}

void c89atomic_test__basic__exchange()
{
    printf("c89atomic_exchange_*():\n");

    printf("    c89atomic_exchange_8:                 ");
    {
        c89atomic_uint8 a = 0;
        c89atomic_uint8 b = 0;
        c89atomic_uint8 c = 123;
        c89atomic_uint8 r = c89atomic_exchange_8(&b, c);

        if (r == a && c == b) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_exchange_16:                ");
    {
        c89atomic_uint16 a = 0;
        c89atomic_uint16 b = 0;
        c89atomic_uint16 c = 1234;
        c89atomic_uint16 r = c89atomic_exchange_16(&b, c);

        if (r == a && c == b) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_exchange_32:                ");
    {
        c89atomic_uint32 a = 0;
        c89atomic_uint32 b = 0;
        c89atomic_uint32 c = 123456;
        c89atomic_uint32 r = c89atomic_exchange_32(&b, c);

        if (r == a && c == b) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_exchange_64:                ");
    {
        c89atomic_uint64 a = 0;
        c89atomic_uint64 b = 0;
        c89atomic_uint64 c = 123456789012;
        c89atomic_uint64 r = c89atomic_exchange_64(&b, c);

        if (r == a && c == b) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("\n");
}


void c89atomic_test__basic__compare_exchange_strong()
{
    printf("c89atomic_compare_exchange_strong_*():\n");

    printf("    c89atomic_compare_exchange_strong_8:  ");
    {
        c89atomic_uint8 a = 0;
        c89atomic_uint8 b = a;
        c89atomic_uint8 c = 123;
        c89atomic_bool  r = c89atomic_compare_exchange_strong_8(&a, &b, c);

        if (a == c && b == 0 && r == 1) {
            /* Negative case. Expecting a to remain unchanged, b to be set to 0 (previous value of a) and the result to be false. */
            a = 0;
            b = (c89atomic_uint8)(a + 1);
            r = c89atomic_compare_exchange_strong_8(&a, &b, c);
            if (a == 0 && b == 0 && r == 0) {
                printf("PASSED\n");
            } else {
                printf("FAILED\n");
            }
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_compare_exchange_strong_16: ");
    {
        c89atomic_uint16 a = 0;
        c89atomic_uint16 b = a;
        c89atomic_uint16 c = 1234;
        c89atomic_bool   r = c89atomic_compare_exchange_strong_16(&a, &b, c);

        if (a == c && b == 0 && r == 1) {
            /* Negative case. Expecting a to remain unchanged, b to be set to 0 (previous value of a) and the result to be false. */
            a = 0;
            b = (c89atomic_uint16)(a + 1);
            r = c89atomic_compare_exchange_strong_16(&a, &b, c);
            if (a == 0 && b == 0 && r == 0) {
                printf("PASSED\n");
            } else {
                printf("FAILED\n");
            }
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_compare_exchange_strong_32: ");
    {
        c89atomic_uint32 a = 0;
        c89atomic_uint32 b = a;
        c89atomic_uint32 c = 123456;
        c89atomic_bool   r = c89atomic_compare_exchange_strong_32(&a, &b, c);

        if (a == c && b == 0 && r == 1) {
            /* Negative case. Expecting a to remain unchanged, b to be set to 0 (previous value of a) and the result to be false. */
            a = 0;
            b = a + 1;
            r = c89atomic_compare_exchange_strong_32(&a, &b, c);
            if (a == 0 && b == 0 && r == 0) {
                printf("PASSED\n");
            } else {
                printf("FAILED\n");
            }
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_compare_exchange_strong_64: ");
    {
        c89atomic_uint64 a = 0;
        c89atomic_uint64 b = a;
        c89atomic_uint64 c = 123456789012;
        c89atomic_bool   r = c89atomic_compare_exchange_strong_64(&a, &b, c);

        if (a == c && b == 0 && r == 1) {
            /* Negative case. Expecting a to remain unchanged, b to be set to 0 (previous value of a) and the result to be false. */
            a = 0;
            b = a + 1;
            r = c89atomic_compare_exchange_strong_64(&a, &b, c);
            if (a == 0 && b == 0 && r == 0) {
                printf("PASSED\n");
            } else {
                printf("FAILED\n");
            }
        } else {
            printf("FAILED\n");
        }
    }

    printf("\n");
}


void c89atomic_test__basic__compare_exchange_weak()
{
    printf("c89atomic_compare_exchange_weak_*():\n");

    printf("    c89atomic_compare_exchange_weak_8:    ");
    {
        c89atomic_uint8 a = 0;
        c89atomic_uint8 b = a;
        c89atomic_uint8 c = 123;
        c89atomic_bool  r = c89atomic_compare_exchange_weak_8(&a, &b, c);

        if (a == c && b == 0 && r == 1) {
            /* Negative case. Expecting a to remain unchanged, b to be set to 0 (previous value of a) and the result to be false. */
            a = 0;
            b = (c89atomic_uint8)(a + 1);
            r = c89atomic_compare_exchange_weak_8(&a, &b, c);
            if (a == 0 && b == 0 && r == 0) {
                printf("PASSED\n");
            } else {
                printf("FAILED\n");
            }
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_compare_exchange_weak_16:   ");
    {
        c89atomic_uint16 a = 0;
        c89atomic_uint16 b = a;
        c89atomic_uint16 c = 1234;
        c89atomic_bool   r = c89atomic_compare_exchange_weak_16(&a, &b, c);

        if (a == c && b == 0 && r == 1) {
            /* Negative case. Expecting a to remain unchanged, b to be set to 0 (previous value of a) and the result to be false. */
            a = 0;
            b = (c89atomic_uint16)(a + 1);
            r = c89atomic_compare_exchange_weak_16(&a, &b, c);
            if (a == 0 && b == 0 && r == 0) {
                printf("PASSED\n");
            } else {
                printf("FAILED\n");
            }
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_compare_exchange_weak_32:   ");
    {
        c89atomic_uint32 a = 0;
        c89atomic_uint32 b = a;
        c89atomic_uint32 c = 123456;
        c89atomic_bool   r = c89atomic_compare_exchange_weak_32(&a, &b, c);

        if (a == c && b == 0 && r == 1) {
            /* Negative case. Expecting a to remain unchanged, b to be set to 0 (previous value of a) and the result to be false. */
            a = 0;
            b = a + 1;
            r = c89atomic_compare_exchange_weak_32(&a, &b, c);
            if (a == 0 && b == 0 && r == 0) {
                printf("PASSED\n");
            } else {
                printf("FAILED\n");
            }
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_compare_exchange_weak_64:   ");
    {
        c89atomic_uint64 a = 0;
        c89atomic_uint64 b = a;
        c89atomic_uint64 c = 123456789012;
        c89atomic_bool   r = c89atomic_compare_exchange_weak_64(&a, &b, c);

        if (a == c && b == 0 && r == 1) {
            /* Negative case. Expecting a to remain unchanged, b to be set to 0 (previous value of a) and the result to be false. */
            a = 0;
            b = a + 1;
            r = c89atomic_compare_exchange_weak_64(&a, &b, c);
            if (a == 0 && b == 0 && r == 0) {
                printf("PASSED\n");
            } else {
                printf("FAILED\n");
            }
        } else {
            printf("FAILED\n");
        }
    }

    printf("\n");
}


void c89atomic_test__basic__fetch_add()
{
    printf("c89atomic_fetch_add_*():\n");

    printf("    c89atomic_fetch_add_8:                ");
    {
        c89atomic_uint8 a = 0;
        c89atomic_uint8 b = a;
        c89atomic_uint8 c = 123;
        c89atomic_uint8 r = c89atomic_fetch_add_8(&a, c);

        if (r == b && a == (b + c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_add_16:               ");
    {
        c89atomic_uint16 a = 0;
        c89atomic_uint16 b = a;
        c89atomic_uint16 c = 1234;
        c89atomic_uint16 r = c89atomic_fetch_add_16(&a, c);

        if (r == b && a == (b + c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_add_32:               ");
    {
        c89atomic_uint32 a = 0;
        c89atomic_uint32 b = a;
        c89atomic_uint32 c = 123456;
        c89atomic_uint32 r = c89atomic_fetch_add_32(&a, c);

        if (r == b && a == (b + c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_add_64:               ");
    {
        c89atomic_uint64 a = 0;
        c89atomic_uint64 b = a;
        c89atomic_uint64 c = 123456789012;
        c89atomic_uint64 r = c89atomic_fetch_add_64(&a, c);

        if (r == b && a == (b + c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("\n");
}

void c89atomic_test__basic__fetch_sub()
{
    printf("c89atomic_fetch_sub_*():\n");

    printf("    c89atomic_fetch_sub_8:                ");
    {
        c89atomic_uint8 a = 0;
        c89atomic_uint8 b = a;
        c89atomic_uint8 c = 123;
        c89atomic_uint8 r = c89atomic_fetch_sub_8(&a, c);

        if (r == b && a == (c89atomic_uint8)(b - c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_sub_16:               ");
    {
        c89atomic_uint16 a = 0;
        c89atomic_uint16 b = a;
        c89atomic_uint16 c = 1234;
        c89atomic_uint16 r = c89atomic_fetch_sub_16(&a, c);

        if (r == b && a == (c89atomic_uint16)(b - c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_sub_32:               ");
    {
        c89atomic_uint32 a = 0;
        c89atomic_uint32 b = a;
        c89atomic_uint32 c = 123456;
        c89atomic_uint32 r = c89atomic_fetch_sub_32(&a, c);

        if (r == b && a == (c89atomic_uint32)(b - c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_sub_64:               ");
    {
        c89atomic_uint64 a = 0;
        c89atomic_uint64 b = a;
        c89atomic_uint64 c = 123456789012;
        c89atomic_uint64 r = c89atomic_fetch_sub_64(&a, c);

        if (r == b && a == (c89atomic_uint64)(b - c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("\n");
}


void c89atomic_test__basic__fetch_or()
{
    printf("c89atomic_fetch_or_*():\n");

    printf("    c89atomic_fetch_or_8:                 ");
    {
        c89atomic_uint8 a = 0;
        c89atomic_uint8 b = a;
        c89atomic_uint8 c = 123;
        c89atomic_uint8 r = c89atomic_fetch_or_8(&a, c);

        if (r == b && a == (c89atomic_uint8)(b | c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_or_16:                ");
    {
        c89atomic_uint16 a = 0;
        c89atomic_uint16 b = a;
        c89atomic_uint16 c = 1234;
        c89atomic_uint16 r = c89atomic_fetch_or_16(&a, c);

        if (r == b && a == (c89atomic_uint16)(b | c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_or_32:                ");
    {
        c89atomic_uint32 a = 0;
        c89atomic_uint32 b = a;
        c89atomic_uint32 c = 123456;
        c89atomic_uint32 r = c89atomic_fetch_or_32(&a, c);

        if (r == b && a == (c89atomic_uint32)(b | c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_or_64:                ");
    {
        c89atomic_uint64 a = 0;
        c89atomic_uint64 b = a;
        c89atomic_uint64 c = 123456789012;
        c89atomic_uint64 r = c89atomic_fetch_or_64(&a, c);

        if (r == b && a == (c89atomic_uint64)(b | c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("\n");
}

void c89atomic_test__basic__fetch_xor()
{
    printf("c89atomic_fetch_xor_*():\n");

    printf("    c89atomic_fetch_xor_8:                ");
    {
        c89atomic_uint8 a = 0;
        c89atomic_uint8 b = a;
        c89atomic_uint8 c = 123;
        c89atomic_uint8 r = c89atomic_fetch_xor_8(&a, c);

        if (r == b && a == (c89atomic_uint8)(b ^ c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_xor_16:               ");
    {
        c89atomic_uint16 a = 0;
        c89atomic_uint16 b = a;
        c89atomic_uint16 c = 1234;
        c89atomic_uint16 r = c89atomic_fetch_xor_16(&a, c);

        if (r == b && a == (c89atomic_uint16)(b ^ c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_xor_32:               ");
    {
        c89atomic_uint32 a = 0;
        c89atomic_uint32 b = a;
        c89atomic_uint32 c = 123456;
        c89atomic_uint32 r = c89atomic_fetch_xor_32(&a, c);

        if (r == b && a == (c89atomic_uint32)(b ^ c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_xor_64:               ");
    {
        c89atomic_uint64 a = 0;
        c89atomic_uint64 b = a;
        c89atomic_uint64 c = 123456789012;
        c89atomic_uint64 r = c89atomic_fetch_xor_64(&a, c);

        if (r == b && a == (c89atomic_uint64)(b ^ c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("\n");
}

void c89atomic_test__basic__fetch_and()
{
    printf("c89atomic_fetch_and_*():\n");

    printf("    c89atomic_fetch_and_8:                ");
    {
        c89atomic_uint8 a = 0;
        c89atomic_uint8 b = a;
        c89atomic_uint8 c = 123;
        c89atomic_uint8 r = c89atomic_fetch_and_8(&a, c);

        if (r == b && a == (c89atomic_uint8)(b & c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_and_16:               ");
    {
        c89atomic_uint16 a = 0;
        c89atomic_uint16 b = a;
        c89atomic_uint16 c = 1234;
        c89atomic_uint16 r = c89atomic_fetch_and_16(&a, c);

        if (r == b && a == (c89atomic_uint16)(b & c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_and_32:               ");
    {
        c89atomic_uint32 a = 0;
        c89atomic_uint32 b = a;
        c89atomic_uint32 c = 123456;
        c89atomic_uint32 r = c89atomic_fetch_and_32(&a, c);

        if (r == b && a == (c89atomic_uint32)(b & c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("    c89atomic_fetch_and_64:               ");
    {
        c89atomic_uint64 a = 0;
        c89atomic_uint64 b = a;
        c89atomic_uint64 c = 123456789012;
        c89atomic_uint64 r = c89atomic_fetch_and_64(&a, c);

        if (r == b && a == (c89atomic_uint64)(b & c)) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }
    }

    printf("\n");
}


int main(int argc, char** argv)
{
    c89atomic_test__basic__flag_test_and_set();
    c89atomic_test__basic__flag_clear();
    c89atomic_test__basic__load();
    c89atomic_test__basic__store();
    c89atomic_test__basic__exchange();
    c89atomic_test__basic__compare_exchange_strong();
    c89atomic_test__basic__compare_exchange_weak();
    c89atomic_test__basic__fetch_add();
    c89atomic_test__basic__fetch_sub();
    c89atomic_test__basic__fetch_or();
    c89atomic_test__basic__fetch_xor();
    c89atomic_test__basic__fetch_and();

    /* Putting these functions here for testing that they compile. */
    c89atomic_is_lock_free_8(NULL);
    c89atomic_is_lock_free_16(NULL);
    c89atomic_is_lock_free_32(NULL);
    c89atomic_is_lock_free_64(NULL);
    c89atomic_compiler_fence();
    c89atomic_thread_fence(c89atomic_memory_order_seq_cst);
    c89atomic_signal_fence(c89atomic_memory_order_seq_cst);

    (void)argc;
    (void)argv;

    return 0;
}