// Source exposure: binary-analysis; no external implementation reused.
// LeafForwardebda40, Forward, leaf_target, leaf_global: GUESS(low) STANDIN
// Origin: census-forward-leaf v1
// 0xebda40 LeafForwardebda40::Forward
#include "LeafForwardebda40.h"
extern "C" void* leaf_target(void*);
void* LeafForwardebda40::Forward() { return leaf_target(this); }
