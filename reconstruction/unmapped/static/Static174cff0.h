// Source exposure: binary-analysis; no external implementation source reused.
// Static174cff0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174cff0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174cff0*);
    virtual void release(Static174cff0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174cff0*);
struct Static174cff0 {
    void* value;
    Static174cff0();
    ~Static174cff0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
