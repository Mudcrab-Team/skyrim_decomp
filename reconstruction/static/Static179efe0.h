// Source exposure: binary-analysis; no external implementation source reused.
// Static179efe0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179efe0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179efe0*);
    virtual void release(Static179efe0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179efe0*);
struct Static179efe0 {
    void* value;
    Static179efe0();
    ~Static179efe0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
