cc -DTEST source/console/test.c source/console/pm_thread.c source/console/pm_aes.c source/console/pm_b64.c source/console/pm_io.c source/console/pm_parse.c source/console/pm_rand.c source/console/pm_sync.c source/console/pm_glob.c source/console/pm_xcrypt.c -ggdb -O0 -Iinclude -otest_console -lpthread && ./test_console
