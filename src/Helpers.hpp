#include <PluginSDK.h>
#include <string>
#include <cstring>

struct string {
    char *ptr;
    size_t len;
};

void init_string(struct string *s) 
{
    s->len = 0;
    s->ptr = (char*)malloc(s->len+1);
    if (s->ptr == NULL) {
        Onset::Plugin::Get()->Log("[TRIDENTCOM] Memory allocation failed. Out of memory?");
        exit(EXIT_FAILURE);
    }
    s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
    size_t new_len = s->len + size*nmemb;
    s->ptr = (char*)realloc(s->ptr, new_len+1);
    if (s->ptr == NULL) {
        Onset::Plugin::Get()->Log("[TRIDENTCOM] Memory reallocation failed. Out of memory?");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr+s->len, ptr, size*nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size*nmemb;
}