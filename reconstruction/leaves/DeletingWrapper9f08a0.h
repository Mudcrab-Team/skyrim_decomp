// Source exposure: binary-analysis
// DeletingWrapper9f08a0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper9f08a0 {
public:
    virtual ~DeletingWrapper9f08a0();
};
static_assert(sizeof(DeletingWrapper9f08a0) == 8, "interface layout");
