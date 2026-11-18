// Source exposure: binary-analysis; no external implementation source reused.
// Static17a8fe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a8fe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a8fe0*);
    virtual void release(Static17a8fe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a8fe0*);
struct Static17a8fe0 {
    void* value;
    Static17a8fe0();
    ~Static17a8fe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
