// Source exposure: binary-analysis; no external implementation source reused.
// Static174e7a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e7a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e7a0*);
    virtual void release(Static174e7a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e7a0*);
struct Static174e7a0 {
    void* value;
    Static174e7a0();
    ~Static174e7a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
