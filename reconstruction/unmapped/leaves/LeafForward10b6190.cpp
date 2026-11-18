// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10b6190, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10b6190 LeafForward10b6190::Forward
#include "LeafForward10b6190.h"
extern "C" void* leaf_target(void*);
void* LeafForward10b6190::Forward() { return leaf_target(this); }
