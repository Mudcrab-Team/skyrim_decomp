// Source exposure: binary-analysis
// DeletingLeaf475a50, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf475a50 {
public:
    virtual ~DeletingLeaf475a50() {}
};
static_assert(sizeof(DeletingLeaf475a50) == 8, "minimal virtual interface size");
