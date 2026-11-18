// Source exposure: binary-analysis; no external implementation source reused.
// Static17462c0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17462c0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17462c0*);
    virtual void release(Static17462c0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17462c0*);
struct Static17462c0 {
    void* value;
    Static17462c0();
    ~Static17462c0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
