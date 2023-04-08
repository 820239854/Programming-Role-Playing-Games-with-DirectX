# Programming Role Playing Games with DirectX

### 默认使用9.0c SDK目录
$(DXSDK_DIR)Include;
$(DXSDK_DIR)Lib\x86;

### 有些API变动处 必须安装dx 9.0b sdk
要调整相对于默认Include的相对次序时需要修改VC++目录
> $(IncludePath);D:\SDKs\DX9b\Include

### Error lnk2026: module unsafe for safeseh image
Right-click on your project -> Properties -> 
Configuration Properties -> Linker ->
Advanced and changed "Image Has Safe Exception Handlers" to "No (/SAFESEH:NO)"


### C++: Unresolved external symbol __sprintf and _sscanf
Add the following library to the linker input files:

> legacy_stdio_definitions.lib
VS 2015 now uses inline definitions that call internal functions for many of the stdio.h functions. If an object file (or library member) depends on one of those functions, then the legacy_stdio_definitions.lib provides an externally linkable version of the function that can be linked to.

Your other option is to recompile the unit that depends on those functions with VS 2015 (this is probably the preferred option).

### "afxres.h"丢失
//#include "afxres.h"
#include <windows.h>