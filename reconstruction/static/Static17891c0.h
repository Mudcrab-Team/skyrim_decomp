// Source exposure: binary-analysis; no external implementation source reused.
// Static17891c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17891c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17891c0*);
    virtual void release(Static17891c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17891c0*);
struct Static17891c0 {
    void* value;
    Static17891c0();
    ~Static17891c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
