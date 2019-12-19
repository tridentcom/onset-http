#include "Plugin.hpp"
#include "Helpers.hpp"
#include <stdio.h> 
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define UNUSED(x) (void) x;

#ifdef LUA_DEFINE
	#undef LUA_DEFINE
#endif

#define LUA_DEFINE(name) Define(#name, [](lua_State *L) -> int

Plugin::Plugin() {

    LUA_DEFINE(httpGet){
        if(lua_gettop(L) != 2){
            return 0;
        }

        const char* host = lua_tostring(L, 1);

        CURL *curl;
        CURLcode res;

        curl = curl_easy_init();

        if(curl) {
            struct string s;
            init_string(&s);

            curl_easy_setopt(curl, CURLOPT_URL, host);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
            res = curl_easy_perform(curl);

            long *rc;
            res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &rc);

            long *cl;
            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD_T, &cl);

            lua_pushstring(L, s.ptr);
            lua_pushinteger(L, (lua_Integer)rc);
            lua_pushinteger(L, (lua_Integer)cl);
            lua_pcall(L, 3, 0, 0);

            free(s.ptr);

            curl_easy_cleanup(curl);
        }

        return 1;
    });

    LUA_DEFINE(httpPost){
        if(lua_gettop(L) != 3){
            return 0;
        }

        const char* host = lua_tostring(L, 1);
        const char* data = lua_tostring(L, 2);

        CURL *curl;
        CURLcode res;

        curl = curl_easy_init();

        if(curl) {
            struct string s;
            init_string(&s);

            curl_easy_setopt(curl, CURLOPT_URL, host);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
            res = curl_easy_perform(curl);

            long *rc;
            res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &rc);

            long *cl;
            res = curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD_T, &cl);

            lua_pushstring(L, s.ptr);
            lua_pushinteger(L, (lua_Integer)rc);
            lua_pushinteger(L, (lua_Integer)cl);
            lua_pcall(L, 3, 0, 0);

            free(s.ptr);

            curl_easy_cleanup(curl);
        }

        return 1;
    });

}