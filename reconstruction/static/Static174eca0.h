// Source exposure: binary-analysis; no external implementation source reused.
// Static174eca0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174eca0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174eca0*);
    virtual void release(Static174eca0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174eca0*);
struct Static174eca0 {
    void* value;
    Static174eca0();
    ~Static174eca0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
