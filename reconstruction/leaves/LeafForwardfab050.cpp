// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfab050, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfab050 LeafForwardfab050::Forward
#include "LeafForwardfab050.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfab050::Forward() { return leaf_target(this); }
