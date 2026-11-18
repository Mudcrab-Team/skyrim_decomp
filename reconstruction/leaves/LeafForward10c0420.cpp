// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10c0420, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10c0420 LeafForward10c0420::Forward
#include "LeafForward10c0420.h"
extern "C" void* leaf_target(void*);
void* LeafForward10c0420::Forward() { return leaf_target(this); }
