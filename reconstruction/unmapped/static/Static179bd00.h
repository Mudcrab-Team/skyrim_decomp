// Source exposure: binary-analysis; no external implementation source reused.
// Static179bd00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179bd00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179bd00*);
    virtual void release(Static179bd00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179bd00*);
struct Static179bd00 {
    void* value;
    Static179bd00();
    ~Static179bd00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
