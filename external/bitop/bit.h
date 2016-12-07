#ifndef __LUA_BITOP_H_
#define __LUA_BITOP_H_

#if __cplusplus
extern "C" {
#endif

#include "lauxlib.h"

LUALIB_API int luaopen_bit(lua_State *L);

#if __cplusplus
}
#endif

#endif