// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10b7e00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10b7e00 LeafForward10b7e00::Forward
#include "LeafForward10b7e00.h"
extern "C" void* leaf_target(void*);
void* LeafForward10b7e00::Forward() { return leaf_target(this); }
