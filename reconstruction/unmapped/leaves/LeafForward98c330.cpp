// Source exposure: binary-analysis; no external implementation reused.
// LeafForward98c330, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x98c330 LeafForward98c330::Forward
#include "LeafForward98c330.h"
extern "C" void* leaf_target(void*);
void* LeafForward98c330::Forward() { return leaf_target(this); }
