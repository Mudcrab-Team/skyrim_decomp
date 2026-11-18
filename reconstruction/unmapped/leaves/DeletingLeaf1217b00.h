// Source exposure: binary-analysis
// DeletingLeaf1217b00, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeaf1217b00 {
public:
    virtual ~DeletingLeaf1217b00() {}
};
static_assert(sizeof(DeletingLeaf1217b00) == 8, "minimal virtual interface size");
