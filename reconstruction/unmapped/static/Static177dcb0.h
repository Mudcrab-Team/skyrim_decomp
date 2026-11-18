// Source exposure: binary-analysis; no external implementation source reused.
// Static177dcb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177dcb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177dcb0*);
    virtual void release(Static177dcb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177dcb0*);
struct Static177dcb0 {
    void* value;
    Static177dcb0();
    ~Static177dcb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
