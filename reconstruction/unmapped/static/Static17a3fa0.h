// Source exposure: binary-analysis; no external implementation source reused.
// Static17a3fa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a3fa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a3fa0*);
    virtual void release(Static17a3fa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a3fa0*);
struct Static17a3fa0 {
    void* value;
    Static17a3fa0();
    ~Static17a3fa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
