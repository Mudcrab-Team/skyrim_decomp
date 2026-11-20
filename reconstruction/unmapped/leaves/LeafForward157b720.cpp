// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157b720, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157b720 LeafForward157b720::Forward
#include "LeafForward157b720.h"
extern "C" void* leaf_target(void*);
void* LeafForward157b720::Forward() { return leaf_target(this); }
