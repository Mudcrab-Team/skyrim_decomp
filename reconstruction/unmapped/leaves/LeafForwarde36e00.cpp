// Source exposure: binary-analysis; no external implementation reused.
// LeafForwarde36e00, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xe36e00 LeafForwarde36e00::Forward
#include "LeafForwarde36e00.h"
extern "C" void* leaf_target(void*);
void* LeafForwarde36e00::Forward() { return leaf_target(this); }
