// Source exposure: binary-analysis; no external implementation source reused.
// Static174acb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174acb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174acb0*);
    virtual void release(Static174acb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174acb0*);
struct Static174acb0 {
    void* value;
    Static174acb0();
    ~Static174acb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
