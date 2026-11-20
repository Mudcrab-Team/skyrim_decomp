// Source exposure: binary-analysis; no external implementation source reused.
// Static17a8ef0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a8ef0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a8ef0*);
    virtual void release(Static17a8ef0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a8ef0*);
struct Static17a8ef0 {
    void* value;
    Static17a8ef0();
    ~Static17a8ef0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
