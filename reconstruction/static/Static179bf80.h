// Source exposure: binary-analysis; no external implementation source reused.
// Static179bf80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179bf80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179bf80*);
    virtual void release(Static179bf80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179bf80*);
struct Static179bf80 {
    void* value;
    Static179bf80();
    ~Static179bf80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
