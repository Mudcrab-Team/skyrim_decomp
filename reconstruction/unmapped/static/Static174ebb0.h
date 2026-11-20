// Source exposure: binary-analysis; no external implementation source reused.
// Static174ebb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ebb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ebb0*);
    virtual void release(Static174ebb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ebb0*);
struct Static174ebb0 {
    void* value;
    Static174ebb0();
    ~Static174ebb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
