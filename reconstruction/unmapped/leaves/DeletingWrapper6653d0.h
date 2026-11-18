// Source exposure: binary-analysis
// DeletingWrapper6653d0, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-wrapper v1
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingWrapper6653d0 {
public:
    virtual ~DeletingWrapper6653d0();
};
static_assert(sizeof(DeletingWrapper6653d0) == 8, "interface layout");
