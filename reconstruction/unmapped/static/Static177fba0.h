// Source exposure: binary-analysis; no external implementation source reused.
// Static177fba0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177fba0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177fba0*);
    virtual void release(Static177fba0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177fba0*);
struct Static177fba0 {
    void* value;
    Static177fba0();
    ~Static177fba0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
