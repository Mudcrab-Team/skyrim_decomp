// Source exposure: binary-analysis; no external implementation source reused.
// Static179ebd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ebd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ebd0*);
    virtual void release(Static179ebd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ebd0*);
struct Static179ebd0 {
    void* value;
    Static179ebd0();
    ~Static179ebd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
