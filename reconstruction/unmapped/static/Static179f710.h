// Source exposure: binary-analysis; no external implementation source reused.
// Static179f710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f710*);
    virtual void release(Static179f710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f710*);
struct Static179f710 {
    void* value;
    Static179f710();
    ~Static179f710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
