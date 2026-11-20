// Source exposure: binary-analysis; no external implementation source reused.
// Code origin: original reconstruction from binary analysis.
// StorageInit2d4030, AdapterBase, Adapter, owner, acquire, grow, release, initialize: GUESS(low) STANDIN
// storage_helper, count, storage, object: GUESS(low) STANDIN
#pragma once
struct AdapterBase {
    virtual bool acquire(unsigned, unsigned) = 0;
    virtual bool grow(unsigned, unsigned, unsigned, unsigned, unsigned) = 0;
    virtual void release() = 0;
    virtual ~AdapterBase() {}
};
struct StorageInit2d4030;
struct Adapter : AdapterBase {
    void* owner;
    Adapter(void* object) : owner(object) {}
    bool acquire(unsigned, unsigned) override;
    bool grow(unsigned, unsigned, unsigned, unsigned, unsigned) override;
    void release() override;
    ~Adapter() override {}
};
extern unsigned storage_helper(unsigned*, AdapterBase*, unsigned, unsigned);
// No size or complete layout is asserted for caller-owned storage.
struct StorageInit2d4030 { static unsigned initialize(void* object); };
