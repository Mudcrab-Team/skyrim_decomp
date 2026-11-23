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
 s/(typedef\s+char\s+\w+\[)[^;]*?\?\s*1\s*:\s*-1\]/${1}1]/gs;
 s/operator (new|new\[\])\(unsigned int/operator $1(size_t/g;
 s/operator delete\(((?:\(void\*\))?this), 0x?[0-9a-fA-F]+\)/operator delete($1)/g;
 s/typedef\s+unsigned(?:\s+int)?\s+size_t\s*;//g;
 s/typedef\s+unsigned(?:\s+int)?\s+hk_size_t\s*;/typedef size_t hk_size_t;/g;
 s/operator (new|new\[\])\(unsigned( int)?/operator $1(size_t/g;
 s/__asm\s*\{[^{}]*\}/;/g;
 s/^[ \t]*__asm\b[^\n{}]*$/;/mg;'
