// Source exposure: binary-analysis; no external implementation source reused.
// Static173f410, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f410;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f410*);
    virtual void release(Static173f410*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f410*);
struct Static173f410 {
    void* value;
    Static173f410();
    ~Static173f410() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
