// Source exposure: binary-analysis; no external implementation source reused.
// Static174f680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f680*);
    virtual void release(Static174f680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f680*);
struct Static174f680 {
    void* value;
    Static174f680();
    ~Static174f680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
