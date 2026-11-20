// Source exposure: binary-analysis; no external implementation source reused.
// Static17c53d0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c53d0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c53d0*);
    virtual void release(Static17c53d0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c53d0*);
struct Static17c53d0 {
    void* value;
    Static17c53d0();
    ~Static17c53d0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
