// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10aa1d0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10aa1d0 LeafForward10aa1d0::Forward
#include "LeafForward10aa1d0.h"
extern "C" void* leaf_target(void*);
void* LeafForward10aa1d0::Forward() { return leaf_target(this); }
