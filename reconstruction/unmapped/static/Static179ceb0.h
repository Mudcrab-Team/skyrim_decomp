// Source exposure: binary-analysis; no external implementation source reused.
// Static179ceb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ceb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ceb0*);
    virtual void release(Static179ceb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ceb0*);
struct Static179ceb0 {
    void* value;
    Static179ceb0();
    ~Static179ceb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
