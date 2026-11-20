// Source exposure: binary-analysis; no external implementation source reused.
// Static177a8d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177a8d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177a8d0*);
    virtual void release(Static177a8d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177a8d0*);
struct Static177a8d0 {
    void* value;
    Static177a8d0();
    ~Static177a8d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
