// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157ab30, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157ab30 LeafForward157ab30::Forward
#include "LeafForward157ab30.h"
extern "C" void* leaf_target(void*);
void* LeafForward157ab30::Forward() { return leaf_target(this); }
