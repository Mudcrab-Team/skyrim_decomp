// Source exposure: binary-analysis; no external implementation source reused.
// Static174eda0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174eda0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174eda0*);
    virtual void release(Static174eda0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174eda0*);
struct Static174eda0 {
    void* value;
    Static174eda0();
    ~Static174eda0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
