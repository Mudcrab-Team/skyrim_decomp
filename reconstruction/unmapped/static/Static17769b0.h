// Source exposure: binary-analysis; no external implementation source reused.
// Static17769b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17769b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17769b0*);
    virtual void release(Static17769b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17769b0*);
struct Static17769b0 {
    void* value;
    Static17769b0();
    ~Static17769b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
