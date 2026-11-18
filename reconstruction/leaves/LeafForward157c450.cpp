// Source exposure: binary-analysis; no external implementation reused.
// LeafForward157c450, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x157c450 LeafForward157c450::Forward
#include "LeafForward157c450.h"
extern "C" void* leaf_target(void*);
void* LeafForward157c450::Forward() { return leaf_target(this); }
