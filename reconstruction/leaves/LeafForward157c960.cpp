// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157c960, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157c960 LeafForward157c960::Forward
#include "LeafForward157c960.h"
extern "C" void* leaf_target(void*);
void* LeafForward157c960::Forward() { return leaf_target(this); }
