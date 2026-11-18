// Source exposure: binary-analysis; no external implementation source reused.
// Static177d0d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d0d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d0d0*);
    virtual void release(Static177d0d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d0d0*);
struct Static177d0d0 {
    void* value;
    Static177d0d0();
    ~Static177d0d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
