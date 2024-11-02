#include "s21_string.h"

#include <stdio.h>

#include "s21_string_test.h"

void s21_strlen_test() {
    const char* str = "Hello, World!";
    const char* str2 = "3298425";
    const char* str3 = "";
    int result = s21_strlen(str);
    int result2 = s21_strlen(str2);
    int res3 = s21_strlen(str3);
    if (result > 0) {
        printf("%s\n", str);
        printf("%d\n", result);
        printf("SUCCESS\n");
    } else {
        printf("%s\n", str);
        printf("%d\n", result);
        printf("FAIL\n");
    }

    if (result2 > 0) {
        printf("%s\n", str2);
        printf("%d\n", result2);
        printf("SUCCESS\n");
    } else {
        printf("%s\n", str2);
        printf("%d\n", result2);
        printf("FAIL\n");
    }

    if (res3 == 0) {
        printf("%s\n", str3);
        printf("%d\n", res3);
        printf("SUCCESS\n");
    } else {
        printf("%s\n", str3);
        printf("%d\n", res3);
        printf("FAIL\n");
    }
}

void s21_strcmp_test() {
    const char* str = "Hello, World!";
    const char* str2 = "Hello, World!";
    const char* str3 = "";
    const char* str4 = "123";
    const char* str5 = "abc";
    const char* str6 = "zxc";

    int res1 = s21_strcmp(str, str2);
    if (res1 == 0) {
        printf("%s\n", str);
        printf("%s\n", str2);
        printf("%d\n", res1);
        printf("SUCCESS\n");
    } else {
        printf("%s\n", str);
        printf("%s\n", str2);
        printf("%d\n", res1);
        printf("FAIL\n");
    }

    int res2 = s21_strcmp(str3, str4);
    if (res2 == -1) {
        printf("%s\n", str3);
        printf("%s\n", str4);
        printf("%d\n", res2);
        printf("SUCCESS\n");
    } else {
        printf("%s\n", str3);
        printf("%s\n", str4);
        printf("%d\n", res2);
        printf("FAIL\n");
    }

    int res3 = s21_strcmp(str5, str6);
    if (res3 == -2 || res3 == 2) {
        printf("%s\n", str5);
        printf("%s\n", str6);
        printf("%d\n", res3);
        printf("SUCCESS\n");
    } else {
        printf("%s\n", str5);
        printf("%s\n", str6);
        printf("%d\n", res3);
        printf("FAIL\n");
    }
}

void s21_strcpy_test() {
    char str1[15] = "Hello, World!";
    char str2[15] = "";
    char str3[10] = "123456789";
    char str4[5] = "";
    char str5[5] = "1234";
    char str6[6] = "";
    if (s21_strcpy(str2, str1) && s21_strcmp(str1, str2) == 0) {
        printf("%s\n", str1);
        printf("%s\n", str2);
        printf("SUCCESS\n");
    } else {
        printf("%s\n", str1);
        printf("%s\n", str2);
        printf("FAIL\n");
    }

    if (s21_strcpy(str4, str3) && s21_strcmp(str3, str4) == 0) {
        printf("%s\n", str3);
        printf("%s\n", str4);
        printf("SUCCESS\n");
    } else {
        printf("%s\n", str3);
        printf("%s\n", str4);
        printf("FAIL\n");
    }

    if (s21_strcpy(str6, str5) && s21_strcmp(str5, str6) == 0) {
        printf("%s\n", str5);
        printf("%s\n", str6);
        printf("SUCCESS\n");
    } else {
        printf("%s\n", str5);
        printf("%s\n", str6);
        printf("FAIL\n");
    }
}

void s21_strcat_test() {
    char dest1[100] = "Hello, World!";
    const char* app1 = "Hello, World!";
    char dest2[10] = "123456789";
    const char* app2 = "asfaonfoafn";
    char dest3[11] = "123456789";
    const char* app3 = "1";

    if (s21_strcat(dest1, app1)) {
        printf("%s\n", app1);
        printf("%s\n", dest1);
        printf("SUCCESS\n");
    } else {
        printf("%s\n", app1);
        printf("%s\n", dest1);
        printf("FAIL\n");
    }

    if (s21_strcat(dest2, app2)) {
        printf("%s\n", app2);
        printf("%s\n", dest2);
        printf("SUCCESS\n");
    } else {
        printf("%s\n", app2);
        printf("%s\n", dest2);
        printf("FAIL\n");
    }

    if (s21_strcat(dest3, app3)) {
        printf("%s\n", app3);
        printf("%s\n", dest3);
        printf("SUCCESS\n");
    } else {
        printf("%s\n", app3);
        printf("%s\n", dest3);
        printf("FAIL\n");
    }
}

void s21_strchr_test() {
    const char* str1 = "Hello, World";
    int ch1 = 'W';
    const char* str2 = "123456789";
    int ch2 = 'a';
    const char* str3 = "3afgf df12r 1";
    int ch3 = ' ';

    char* a1 = s21_strchr(str1, ch1);
    char* a2 = s21_strchr(str2, ch2);
    char* a3 = s21_strchr(str3, ch3);

    if (a1 != NULL) {
        printf("%s %c\n", str1, ch1);
        printf("%ld\n", a1 - str1 + 1);
        printf("SUCCESS\n");
    } else {
        printf("%s %c\n", str1, ch1);
        printf("%ld\n", a1 - str1 + 1);
        printf("FAIL\n");
    }

    if (a2 != NULL) {
        printf("%s %c\n", str2, ch2);
        printf("%ld\n", a2 - str2 + 1);
        printf("SUCCESS\n");
    } else {
        printf("%s %c\n", str2, ch2);
        printf("%ld\n", a2 - str2 + 1);
        printf("FAIL\n");
    }

    if (a3 != NULL) {
        printf("%s %c\n", str3, ch3);
        printf("%ld\n", a3 - str3 + 1);
        printf("SUCCESS\n");
    } else {
        printf("%s %c\n", str3, ch3);
        printf("%ld\n", a3 - str3 + 1);
        printf("FAIL\n");
    }
}

void s21_strstr_test() {
    const char* str1 = "123456789";
    const char* str2 = "345";

    const char* str3 = "1234";
    const char* str4 = "a";

    const char* str5 = "ansdnsbms";
    const char* str6 = "ansda";

    char* ch1 = s21_strstr(str2, str1);
    char* ch2 = s21_strstr(str3, str4);
    char* ch3 = s21_strstr(str6, str5);

    if (ch1 != NULL) {
        printf("%s %s\n", str1, str2);
        printf("%ld\n", ch1 - str1 + 1);
        printf("SUCCESS\n");
    } else {
        printf("%s %s\n", str1, str2);
        printf("%ld\n", ch1 - str1 + 1);
        printf("FAIL\n");
    }

    if (ch2 == NULL) {
        printf("%s %s\n", str3, str4);
        printf("%ld\n", ch2 - str3 + 1);
        printf("SUCCESS\n");
    } else {
        printf("%s %s\n", str3, str4);
        printf("NULL\n");
        printf("FAIL\n");
    }

    if (ch3 == NULL) {
        printf("%s %s\n", str5, str6);
        printf("%ld\n", ch3 - str5 + 1);
        printf("SUCCESS\n");
    } else {
        printf("%s %s\n", str5, str6);
        printf("NULL\n");
        printf("FAIL\n");
    }
}
