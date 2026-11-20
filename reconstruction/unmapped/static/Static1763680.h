// Source exposure: binary-analysis; no external implementation source reused.
// Static1763680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763680*);
    virtual void release(Static1763680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763680*);
struct Static1763680 {
    void* value;
    Static1763680();
    ~Static1763680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
