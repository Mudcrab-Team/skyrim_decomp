// Source exposure: binary-analysis; no external implementation source reused.
// Static174f6d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f6d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f6d0*);
    virtual void release(Static174f6d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f6d0*);
struct Static174f6d0 {
    void* value;
    Static174f6d0();
    ~Static174f6d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
