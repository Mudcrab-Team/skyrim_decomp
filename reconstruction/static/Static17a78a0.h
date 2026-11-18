// Source exposure: binary-analysis; no external implementation source reused.
// Static17a78a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a78a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a78a0*);
    virtual void release(Static17a78a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a78a0*);
struct Static17a78a0 {
    void* value;
    Static17a78a0();
    ~Static17a78a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
