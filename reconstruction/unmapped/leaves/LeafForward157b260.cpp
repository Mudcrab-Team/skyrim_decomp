// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157b260, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157b260 LeafForward157b260::Forward
#include "LeafForward157b260.h"
extern "C" void* leaf_target(void*);
void* LeafForward157b260::Forward() { return leaf_target(this); }
