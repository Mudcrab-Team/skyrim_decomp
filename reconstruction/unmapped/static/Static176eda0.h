// Source exposure: binary-analysis; no external implementation source reused.
// Static176eda0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176eda0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176eda0*);
    virtual void release(Static176eda0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176eda0*);
struct Static176eda0 {
    void* value;
    Static176eda0();
    ~Static176eda0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
