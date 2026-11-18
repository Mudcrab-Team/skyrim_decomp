// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardeaffb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xeaffb0 LeafForwardeaffb0::Forward
#include "LeafForwardeaffb0.h"
extern "C" void* leaf_target(void*);
void* LeafForwardeaffb0::Forward() { return leaf_target(this); }
