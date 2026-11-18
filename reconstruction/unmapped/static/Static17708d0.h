// Source exposure: binary-analysis; no external implementation source reused.
// Static17708d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17708d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17708d0*);
    virtual void release(Static17708d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17708d0*);
struct Static17708d0 {
    void* value;
    Static17708d0();
    ~Static17708d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
