// Source exposure: binary-analysis; no external implementation source reused.
// Static179cff0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179cff0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179cff0*);
    virtual void release(Static179cff0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179cff0*);
struct Static179cff0 {
    void* value;
    Static179cff0();
    ~Static179cff0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
