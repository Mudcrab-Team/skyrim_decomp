// Source exposure: binary-analysis
// DeletingLeaf475a20, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf475a20 {
public:
    virtual ~DeletingLeaf475a20() {}
};
static_assert(sizeof(DeletingLeaf475a20) == 8, "minimal virtual interface size");
