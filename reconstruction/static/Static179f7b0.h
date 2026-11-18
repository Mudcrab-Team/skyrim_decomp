// Source exposure: binary-analysis; no external implementation source reused.
// Static179f7b0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f7b0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f7b0*);
    virtual void release(Static179f7b0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f7b0*);
struct Static179f7b0 {
    void* value;
    Static179f7b0();
    ~Static179f7b0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
