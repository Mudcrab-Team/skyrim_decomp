// Source exposure: binary-analysis; no external implementation source reused.
// Static179f350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f350*);
    virtual void release(Static179f350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f350*);
struct Static179f350 {
    void* value;
    Static179f350();
    ~Static179f350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
