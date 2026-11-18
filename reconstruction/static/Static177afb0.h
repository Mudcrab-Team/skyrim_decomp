// Source exposure: binary-analysis; no external implementation source reused.
// Static177afb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177afb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177afb0*);
    virtual void release(Static177afb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177afb0*);
struct Static177afb0 {
    void* value;
    Static177afb0();
    ~Static177afb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
