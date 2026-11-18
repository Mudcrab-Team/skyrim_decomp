// Source exposure: binary-analysis; no external implementation reused.
// LeafForward1eaf40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x1eaf40 LeafForward1eaf40::Forward
#include "LeafForward1eaf40.h"
extern "C" void* leaf_target(void*);
void* LeafForward1eaf40::Forward() { return leaf_target(this); }
