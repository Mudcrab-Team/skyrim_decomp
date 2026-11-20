// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157c980, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157c980 LeafForward157c980::Forward
#include "LeafForward157c980.h"
extern "C" void* leaf_target(void*);
void* LeafForward157c980::Forward() { return leaf_target(this); }
