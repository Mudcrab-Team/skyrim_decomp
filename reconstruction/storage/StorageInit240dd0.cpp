// Source exposure: binary-analysis; no external implementation source reused.
// Code origin: original reconstruction from binary analysis.
// Origin: storage-adapter-initializer v2
// 0x240dd0 StorageInit240dd0::initialize
#include "StorageInit240dd0.h"
unsigned StorageInit240dd0::initialize(void* object)
{
    Adapter adapter(object);
    unsigned& count = *reinterpret_cast<unsigned*>(static_cast<char*>(object) + 16);
    unsigned& storage = *reinterpret_cast<unsigned*>(static_cast<char*>(object) + 24);
    return storage_helper(&storage, &adapter, count, 8);
}
