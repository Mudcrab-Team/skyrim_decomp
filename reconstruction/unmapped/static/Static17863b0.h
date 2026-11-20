// Source exposure: binary-analysis; no external implementation source reused.
// Static17863b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17863b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17863b0*);
    virtual void release(Static17863b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17863b0*);
struct Static17863b0 {
    void* value;
    Static17863b0();
    ~Static17863b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
