// Source exposure: binary-analysis; no external implementation source reused.
// Static174f1d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f1d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f1d0*);
    virtual void release(Static174f1d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f1d0*);
struct Static174f1d0 {
    void* value;
    Static174f1d0();
    ~Static174f1d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
