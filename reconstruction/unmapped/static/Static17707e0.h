// Source exposure: binary-analysis; no external implementation source reused.
// Static17707e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17707e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17707e0*);
    virtual void release(Static17707e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17707e0*);
struct Static17707e0 {
    void* value;
    Static17707e0();
    ~Static17707e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
