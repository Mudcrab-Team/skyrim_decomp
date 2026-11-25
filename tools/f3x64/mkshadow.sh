#!/bin/sh
# Shadow copy of the sibling tree with size/offset static asserts neutralised and
# 32-bit-only allocation operator signatures widened; the clone itself is never touched.
set -e
S=${SIBLING:?path of the sibling clone}
D=${SHADOW:?output directory for the shadow tree}
rm -rf $D; mkdir -p $D; cp -R $S/include $S/src $D/; mkdir $D/build; cp $S/build/units.json $D/build/
find $D -type f \( -name '*.h' -o -name '*.hpp' -o -name '*.inl' -o -name '*.cpp' \) -print0 | xargs -0 perl -0pi -e '
 s/(#define FNV_STATIC_ASSERT\(condition\) typedef char FNV_JOIN\(fnv_static_assert_, __LINE__\)\[)\(condition\) \? 1 : -1\]/${1}1]/g;
 s/^FNV_STATIC_ASSERT\(sizeof\((?:void\*|long)\) == 4\);//mg;
 s/(typedef\s+char\s+\w+\s*\[)[^;]*?\?\s*1\s*:\s*-1\]/${1}1]/gs;
 s/operator (new|new\[\])\(unsigned int/operator $1(size_t/g;
 s/operator delete\(((?:\(void\*\))?this), (?:0x)?[0-9a-fA-F]+\)/operator delete($1)/g;
 s/(\b(?:float|double)\s+(?:__cdecl\s+)?)(sqrtf|acosf|asinf|atan2f|sinf|cosf|tanf|fabsf|expf|logf|powf|sqrt|cos|sin)(\s*\([^)]*\)\s*\{)/${1}f3x_$2$3/g;
 s/typedef\s+unsigned(?:\s+int)?\s+size_t\s*;//g;
 s/typedef\s+unsigned(?:\s+int)?\s+(\w+size_t)\s*;/typedef size_t $1;/g;
 s/^[ \t]*\w*ASSERT\w*\((?:[^;]*sizeof|[^;]*offsetof)[^;]*\);[ \t]*$//mg;
 s/typedef\s+unsigned\s+long\s+__w64\s+hkUlong\s*;/typedef unsigned __int64 hkUlong;/g;
 s/typedef\s+unsigned\s+__w64\s+hk_size_t\s*;/typedef size_t hk_size_t;/g;
 s/^[ \t]*extern\s+"C"\s+[^;{}]*?\b(?:memcpy|memmove|memset|memcmp|_alloca|strcpy_s|strlen|strcmp|memcpy_s|sprintf_s|__security_cookie|__security_check_cookie|__readfsdword|__RTDynamicCast|strrchr|strcat_s|_strnicmp|_ReadWriteBarrier)\b[^;{}]*;[ \t]*$//mg;
 s/typedef\s+unsigned(?:\s+int)?\s+hk_size_t\s*;/typedef size_t hk_size_t;/g;
 s/operator (new|new\[\])\(unsigned( int)?/operator $1(size_t/g;
 s/\b1\s*\/\s*\((?:sizeof|offsetof)\([^)]*\)\s*==\s*\w+\)/1/g;
 s/__asm\s*\{[^{}]*\}/;/g;
 s/^[ \t]*__asm\b[^\n{}]*$/;/mg;'
