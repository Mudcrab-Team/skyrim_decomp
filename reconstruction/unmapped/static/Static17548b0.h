// Source exposure: binary-analysis; no external implementation source reused.
// Static17548b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17548b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17548b0*);
    virtual void release(Static17548b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17548b0*);
struct Static17548b0 {
    void* value;
    Static17548b0();
    ~Static17548b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
