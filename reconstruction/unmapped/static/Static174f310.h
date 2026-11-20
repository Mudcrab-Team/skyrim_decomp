// Source exposure: binary-analysis; no external implementation source reused.
// Static174f310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f310*);
    virtual void release(Static174f310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f310*);
struct Static174f310 {
    void* value;
    Static174f310();
    ~Static174f310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
