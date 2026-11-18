// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157c950, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157c950 LeafForward157c950::Forward
#include "LeafForward157c950.h"
extern "C" void* leaf_target(void*);
void* LeafForward157c950::Forward() { return leaf_target(this); }
