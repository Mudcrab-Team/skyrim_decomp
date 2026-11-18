// Source exposure: binary-analysis
// DeletingWrapper5c46a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper5c46a0 {
public:
    virtual ~DeletingWrapper5c46a0();
};
static_assert(sizeof(DeletingWrapper5c46a0) == 8, "interface layout");
