// Source exposure: binary-analysis; no external implementation source reused.
// Static173eaa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173eaa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173eaa0*);
    virtual void release(Static173eaa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173eaa0*);
struct Static173eaa0 {
    void* value;
    Static173eaa0();
    ~Static173eaa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
