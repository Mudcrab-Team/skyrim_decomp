// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1257eb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1257eb0 LeafForward1257eb0::Forward
#include "LeafForward1257eb0.h"
extern "C" void* leaf_target(void*);
void* LeafForward1257eb0::Forward() { return leaf_target(this); }
