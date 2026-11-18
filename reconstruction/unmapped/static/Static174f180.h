// Source exposure: binary-analysis; no external implementation source reused.
// Static174f180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174f180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174f180*);
    virtual void release(Static174f180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174f180*);
struct Static174f180 {
    void* value;
    Static174f180();
    ~Static174f180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
