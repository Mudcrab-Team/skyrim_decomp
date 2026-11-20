// Source exposure: binary-analysis; no external implementation source reused.
// Static179ec20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ec20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ec20*);
    virtual void release(Static179ec20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ec20*);
struct Static179ec20 {
    void* value;
    Static179ec20();
    ~Static179ec20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
