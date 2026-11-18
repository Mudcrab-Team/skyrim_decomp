// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157c990, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157c990 LeafForward157c990::Forward
#include "LeafForward157c990.h"
extern "C" void* leaf_target(void*);
void* LeafForward157c990::Forward() { return leaf_target(this); }
