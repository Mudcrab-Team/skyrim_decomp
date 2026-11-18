// Source exposure: binary-analysis; no external implementation source reused.
// Static174cc90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174cc90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174cc90*);
    virtual void release(Static174cc90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174cc90*);
struct Static174cc90 {
    void* value;
    Static174cc90();
    ~Static174cc90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
