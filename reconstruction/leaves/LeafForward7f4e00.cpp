// Source exposure: binary-analysis; no external implementation reused.
// LeafForward7f4e00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x7f4e00 LeafForward7f4e00::Forward
#include "LeafForward7f4e00.h"
extern "C" void* leaf_target(void*);
void* LeafForward7f4e00::Forward() { return leaf_target(this); }
