// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157c3e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157c3e0 LeafForward157c3e0::Forward
#include "LeafForward157c3e0.h"
extern "C" void* leaf_target(void*);
void* LeafForward157c3e0::Forward() { return leaf_target(this); }
