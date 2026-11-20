// Source exposure: binary-analysis; no external implementation source reused.
// Static177baa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177baa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177baa0*);
    virtual void release(Static177baa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177baa0*);
struct Static177baa0 {
    void* value;
    Static177baa0();
    ~Static177baa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
