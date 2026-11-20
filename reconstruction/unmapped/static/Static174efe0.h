// Source exposure: binary-analysis; no external implementation source reused.
// Static174efe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174efe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174efe0*);
    virtual void release(Static174efe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174efe0*);
struct Static174efe0 {
    void* value;
    Static174efe0();
    ~Static174efe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
