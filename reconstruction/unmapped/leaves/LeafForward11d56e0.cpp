// Source exposure: binary-analysis; no external implementation reused.
// LeafForward11d56e0, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0x11d56e0 LeafForward11d56e0::Forward
#include "LeafForward11d56e0.h"
extern "C" void* leaf_target(void*);
void* LeafForward11d56e0::Forward() { return leaf_target(this); }
