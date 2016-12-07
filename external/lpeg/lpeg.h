
#ifndef __LUA_LPEG_H_
#define __LUA_LPEG_H_

#if __cplusplus
extern "C" {
#endif

#include "lpeg/lptypes.h"
#include "lpeg/lpcap.h"
#include "lpeg/lpcode.h"
#include "lpeg/lpprint.h"
#include "lpeg/lptree.h"
#include "lpeg/lpvm.h"

int luaopen_lpeg(lua_State *L);
	

#if __cplusplus
}
#endif

#endif