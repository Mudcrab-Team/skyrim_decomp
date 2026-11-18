// Source exposure: binary-analysis
// DeletingWrapper4198a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper4198a0 {
public:
    virtual ~DeletingWrapper4198a0();
};
static_assert(sizeof(DeletingWrapper4198a0) == 8, "interface layout");
