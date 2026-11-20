// Source exposure: binary-analysis; no external implementation source reused.
// Static179f580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f580*);
    virtual void release(Static179f580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f580*);
struct Static179f580 {
    void* value;
    Static179f580();
    ~Static179f580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
