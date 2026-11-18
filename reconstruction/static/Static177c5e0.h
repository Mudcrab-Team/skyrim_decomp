// Source exposure: binary-analysis; no external implementation source reused.
// Static177c5e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c5e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c5e0*);
    virtual void release(Static177c5e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c5e0*);
struct Static177c5e0 {
    void* value;
    Static177c5e0();
    ~Static177c5e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
