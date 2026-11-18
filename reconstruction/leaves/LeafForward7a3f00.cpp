// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7a3f00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7a3f00 LeafForward7a3f00::Forward
#include "LeafForward7a3f00.h"
extern "C" void* leaf_target(void*);
void* LeafForward7a3f00::Forward() { return leaf_target(this); }
