// Source exposure: binary-analysis; no external implementation source reused.
// Static179bcb0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179bcb0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179bcb0*);
    virtual void release(Static179bcb0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179bcb0*);
struct Static179bcb0 {
    void* value;
    Static179bcb0();
    ~Static179bcb0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
