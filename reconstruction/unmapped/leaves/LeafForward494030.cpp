// Source exposure: binary-analysis; no external implementation reused.
// LeafForward494030, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x494030 LeafForward494030::Forward
#include "LeafForward494030.h"
extern "C" void* leaf_target(void*);
void* LeafForward494030::Forward() { return leaf_target(this); }
