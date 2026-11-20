// Source exposure: binary-analysis; no external implementation source reused.
// Static17798e0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17798e0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17798e0*);
    virtual void release(Static17798e0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17798e0*);
struct Static17798e0 {
    void* value;
    Static17798e0();
    ~Static17798e0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
