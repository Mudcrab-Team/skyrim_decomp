// Source exposure: binary-analysis; no external implementation reused.
// LeafForward4deb10, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x4deb10 LeafForward4deb10::Forward
#include "LeafForward4deb10.h"
extern "C" void* leaf_target(void*);
void* LeafForward4deb10::Forward() { return leaf_target(this); }
