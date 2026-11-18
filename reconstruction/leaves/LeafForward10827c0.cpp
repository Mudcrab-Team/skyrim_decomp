// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10827c0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10827c0 LeafForward10827c0::Forward
#include "LeafForward10827c0.h"
extern "C" void* leaf_target(void*);
void* LeafForward10827c0::Forward() { return leaf_target(this); }
