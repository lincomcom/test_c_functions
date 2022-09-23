#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "virsh.h"

char* get_domain_state(char* str_in)
{

}

char* get_domain_state_reason(char* str_in)
{

}
void test_strtok()
{
    const char * const str = "shut off (crashed)";
    const char * const delim = "()";
    char buf[30] = {0};
    char *substr = NULL;
    int count = 0;

    strcpy(buf, str);
    printf("original string: %s (@%p)\n", buf, buf);

    substr = strtok(buf, delim);
    do {
        printf("#%d sub string: %s (@%p)\n", count++, substr, substr);
        substr = strtok(NULL, delim);
    } while (substr);

    printf("original string after 'strtok': ");
    for (count = 0; count < strlen(str); count++) {
        printf("%c", buf[count]?:'*');
        // printf("%c", buf[count]);
    }
    printf(" (@%p)\n", buf);
}

void test_strstr()
{
    const char * const haystack = "crashed (unknown)";
    const char * const needle = "crashed";
    const char * const needle_never_found = "crashedd";
    const char * const delim = "()";
    char buf[30] = {0};
    char *substr = NULL;
    int count = 0;
    if(strstr(haystack, needle_never_found))
        printf("Found: %s\n", needle);
    else
        printf("Not found: %s\n", needle);
}

bool is_abnormal_state_reason(const char* shell_out_str)
{
   
    for(int i = 0; i < VIRSH_DOMSTATE_REASON_MAX; i++){
        if (!strncmp(shell_out_str, abnormal_state_reason_arr[i], VIRSH_OUTPUT_MAX))
            return true;
    }   
   
    return false;
}

void test_is_abnormal_state_reason()
{
    const char *shell_out;

    for(int i = 0; i < VIRSH_DOMSTATE_REASON_NORMAL_MAX; i++){
        
        shell_out = abnormal_state_reason_arr[i];
        
        if(is_abnormal_state_reason(shell_out)){
            printf("%s is abnormal state\n", shell_out);
        }else{
            printf("%s is normal state\n", shell_out);
        }
    }
}

int main(int argc, char **argv)
{
    test_is_abnormal_state_reason();
    // test_strtok();
    // test_strstr();

    return 0;
}