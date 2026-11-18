// Source exposure: binary-analysis; no external implementation source reused.
// Static17986a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17986a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17986a0*);
    virtual void release(Static17986a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17986a0*);
struct Static17986a0 {
    void* value;
    Static17986a0();
    ~Static17986a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
