// Source exposure: binary-analysis; no external implementation source reused.
// Static173f050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f050*);
    virtual void release(Static173f050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f050*);
struct Static173f050 {
    void* value;
    Static173f050();
    ~Static173f050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
