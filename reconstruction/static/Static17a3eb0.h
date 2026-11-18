// Source exposure: binary-analysis; no external implementation source reused.
// Static17a3eb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a3eb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a3eb0*);
    virtual void release(Static17a3eb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a3eb0*);
struct Static17a3eb0 {
    void* value;
    Static17a3eb0();
    ~Static17a3eb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
