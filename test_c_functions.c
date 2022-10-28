#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// #include <regex.h>

#include "virsh.h"
#include "qvs.h"

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

    for(int i = 0; i < VIRSH_DOMSTATE_REASON_MAX; i++){
        
        shell_out = abnormal_state_reason_arr[i];
        
        if(is_abnormal_state_reason(shell_out)){
            printf("%s is abnormal state\n", shell_out);
        }else{
            printf("%s is normal state\n", shell_out);
        }
    }
}

bool is_not_had_qvs_notify_ok_getway(int redefine_notifyevents)
{
    printf("redefine_notifyevents & HAD_QVS_NOTIFY_OK_GATEWAY: %d\n", redefine_notifyevents & HAD_QVS_NOTIFY_OK_GATEWAY);
    return  (redefine_notifyevents & HAD_QVS_NOTIFY_OK_GATEWAY) == 0;
}

bool is_had_qvs_notify_ok(int redefine_notifyevents)
{
    return redefine_notifyevents >= HAD_QVS_NOTIFY_OK_MIN;
}

bool is_had_qvs_notify_retry(int redefine_notifyevents)
{
    return redefine_notifyevents & HAD_QVS_NOTIFY_RETRY;
}

// bool is_output_format_valid(const char* output) {
//     if(is_empty_str(output)) {
//         return false;
//     }

//     regex_t preg;
//     int comp_success = regcomp(&preg, LIBVIRT_PATTERN, REG_EXTENDED|REG_ICASE);
//     // 0 -> compile success
//     if (comp_success) {
//         return false;
//     }
//     regmatch_t matchptr[1];
//     const size_t nmatch = 1;
//     int status = regexec(&preg, output, nmatch, matchptr, 0);
//     if (status == REG_NOMATCH) { // not match
//         return false;
//     }

//     return true;
// }

void test_qvs_notify_ok_gateway(int redefine_notifyevents)
{
    if(is_not_had_qvs_notify_ok_getway(513)){
        printf("is_not_had_qvs_notify_ok_getway\n");
    }else{
        printf("is_had_qvs_notify_ok_getway\n");
    }
    printf("return of is_not_had_qvs_notify_ok_getway: %d\n", is_not_had_qvs_notify_ok_getway(513));
}

void test_callback_keepalive(int redefine_notifyevents)
{
    if ((is_had_qvs_notify_ok(redefine_notifyevents) || is_had_qvs_notify_retry(redefine_notifyevents)) && 
        is_not_had_qvs_notify_ok_getway(redefine_notifyevents)) {
        printf("keepalive_start\n");        
    } else {
        printf("had_suicide\n");   
    }
}

void test_initialize_char_arr(){
    char output[VIRSH_OUTPUT_MAX] = {0};
    int i=0;
    for(i=0; i<VIRSH_OUTPUT_MAX; i++){
        if(output[i] != '\0'){
            printf("output[i] = %c, is not \\0\n", output[i]);
        }
    }
    printf("All %d for each output[i] is \\0\n", i);
}

void test_is_output_format_valid(){
    
}

int main(int argc, char **argv)
{
    // test_is_abnormal_state_reason();
    // test_strtok();
    // test_strstr();
    // test_callback_keepalive(513);
    test_initialize_char_arr();

    return 0;
}