// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157d030, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157d030 LeafForward157d030::Forward
#include "LeafForward157d030.h"
extern "C" void* leaf_target(void*);
void* LeafForward157d030::Forward() { return leaf_target(this); }
