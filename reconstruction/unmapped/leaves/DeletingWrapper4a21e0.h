// Source exposure: binary-analysis
// DeletingWrapper4a21e0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper4a21e0 {
public:
    virtual ~DeletingWrapper4a21e0();
};
static_assert(sizeof(DeletingWrapper4a21e0) == 8, "interface layout");
