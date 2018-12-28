
在cocos2d-x/external/lua 目录下新建四个文件夹sproto,bitop,lpeg,lpack。然后将各自的文件放入其中，为了符合cocos2dx的规范，需要在bitop中建立一个bit.h文件，内容如下:
``` 
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
``` 
在lpeg中建立一个lpeg.h文件，内容如下:
``` 
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
``` 
在sproto中建立一个lsproto.h文件，内容如下:
``` 
#ifndef __LUA_LSPROTO_H_
#define __LUA_LSPROTO_H_

#if __cplusplus
extern "C" {
#endif

#include "lauxlib.h"

int luaopen_sproto_core(lua_State *L);

#if __cplusplus
}
#endif

#endif
``` 
在lpack中建立一个lpack.h文件，内容如下:
``` 
#ifndef __LUA_LPACK_H_
#define __LUA_LPACK_H_
#if __cplusplus
extern "C" {
#endif

#include "lauxlib.h"

int luaopen_pack(lua_State *L);

#if __cplusplus
}
#endif
#endif
``` 

在cocos2d-x/cocos/scripting/lua-bindings/manual/network目录下，找到 lua_extensions.c 文件。在头部包含所需文件。
``` 
#include "sproto/lsproto.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
#include "bitop/bit.h"
#endif
#include "lpeg/lpeg.h"
#include "lpack/lpack.h"

在luax_exts内，加入下列几行。

  { "sproto.core", luaopen_sproto_core },
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID)
  { "bit", luaopen_bit },
#endif
  { "lpeg", luaopen_lpeg },
  { "string", luaopen_pack },

``` 
Android支持

在cocos2d-x/cocos/scripting/lua-bindings/proj.android目录下，打开 Android.mk 文件，在那一长串加载c文件后面，加入我们需要的c文件
``` 
      ../../../../external/lua/lpeg/lpcap.c \
      ../../../../external/lua/lpeg/lpcode.c \
      ../../../../external/lua/lpeg/lpprint.c \
      ../../../../external/lua/lpeg/lptree.c \
      ../../../../external/lua/lpeg/lpvm.c \
      ../../../../external/lua/sproto/lsproto.c \
      ../../../../external/lua/sproto/sproto.c \
      ../../../../external/lua/lpack/lpack.c 
``` 
Android支持luajit库，里面已经包含了bit库，所以不用加bit.c了，不然编译的时候会出现多重定义的错误。

总得来说还是很简单的，只需三步：
  文件放到cocos2d-x/external/lua目录下
  修改lua_extensions.c，包含相关文件
  修改Android.mk做Android支持
