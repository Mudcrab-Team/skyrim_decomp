// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1216b30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1216b30 LeafForward1216b30::Forward
#include "LeafForward1216b30.h"
extern "C" void* leaf_target(void*);
void* LeafForward1216b30::Forward() { return leaf_target(this); }
