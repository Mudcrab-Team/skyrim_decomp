// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11cc150, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11cc150 LeafForward11cc150::Forward
#include "LeafForward11cc150.h"
extern "C" void* leaf_target(void*);
void* LeafForward11cc150::Forward() { return leaf_target(this); }
