// Source exposure: binary-analysis; no external implementation source reused.
// Static17641c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17641c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17641c0*);
    virtual void release(Static17641c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17641c0*);
struct Static17641c0 {
    void* value;
    Static17641c0();
    ~Static17641c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
