// Source exposure: binary-analysis; no external implementation reused.
// LeafForward10defb0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x10defb0 LeafForward10defb0::Forward
#include "LeafForward10defb0.h"
extern "C" void* leaf_target(void*);
void* LeafForward10defb0::Forward() { return leaf_target(this); }
