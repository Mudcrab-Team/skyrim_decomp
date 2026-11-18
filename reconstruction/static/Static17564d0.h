// Source exposure: binary-analysis; no external implementation source reused.
// Static17564d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17564d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17564d0*);
    virtual void release(Static17564d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17564d0*);
struct Static17564d0 {
    void* value;
    Static17564d0();
    ~Static17564d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
