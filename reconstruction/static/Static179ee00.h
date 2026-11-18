// Source exposure: binary-analysis; no external implementation source reused.
// Static179ee00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179ee00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179ee00*);
    virtual void release(Static179ee00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179ee00*);
struct Static179ee00 {
    void* value;
    Static179ee00();
    ~Static179ee00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
