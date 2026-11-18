// Source exposure: binary-analysis; no external implementation reused.
// LeafForward156fbc0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x156fbc0 LeafForward156fbc0::Forward
#include "LeafForward156fbc0.h"
extern "C" void* leaf_target(void*);
void* LeafForward156fbc0::Forward() { return leaf_target(this); }
