// Source exposure: binary-analysis; no external implementation source reused.
// Static17782b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17782b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17782b0*);
    virtual void release(Static17782b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17782b0*);
struct Static17782b0 {
    void* value;
    Static17782b0();
    ~Static17782b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
