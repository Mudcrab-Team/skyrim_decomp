// Source exposure: binary-analysis; no external implementation source reused.
// Static17792f0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17792f0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17792f0*);
    virtual void release(Static17792f0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17792f0*);
struct Static17792f0 {
    void* value;
    Static17792f0();
    ~Static17792f0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
