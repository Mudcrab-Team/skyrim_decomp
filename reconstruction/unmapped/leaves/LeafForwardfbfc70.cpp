// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardfbfc70, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xfbfc70 LeafForwardfbfc70::Forward
#include "LeafForwardfbfc70.h"
extern "C" void* leaf_target(void*);
void* LeafForwardfbfc70::Forward() { return leaf_target(this); }
