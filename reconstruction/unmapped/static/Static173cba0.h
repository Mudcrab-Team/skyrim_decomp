// Source exposure: binary-analysis; no external implementation source reused.
// Static173cba0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173cba0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173cba0*);
    virtual void release(Static173cba0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173cba0*);
struct Static173cba0 {
    void* value;
    Static173cba0();
    ~Static173cba0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
