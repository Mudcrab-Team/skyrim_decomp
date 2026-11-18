// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157c970, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157c970 LeafForward157c970::Forward
#include "LeafForward157c970.h"
extern "C" void* leaf_target(void*);
void* LeafForward157c970::Forward() { return leaf_target(this); }
