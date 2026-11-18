// Source exposure: binary-analysis
// DeletingLeafdf3c70, object: GUESS(low) STANDIN
// Origin: scalar-deleting-eight-byte-leaf v3
#pragma once
void operator delete(void*, unsigned __int64) noexcept;
class DeletingLeafdf3c70 {
public:
    virtual ~DeletingLeafdf3c70() {}
};
static_assert(sizeof(DeletingLeafdf3c70) == 8, "minimal virtual interface size");
