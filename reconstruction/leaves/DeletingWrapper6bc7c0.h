// Source exposure: binary-analysis
// DeletingWrapper6bc7c0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper6bc7c0 {
public:
    virtual ~DeletingWrapper6bc7c0();
};
static_assert(sizeof(DeletingWrapper6bc7c0) == 8, "interface layout");
