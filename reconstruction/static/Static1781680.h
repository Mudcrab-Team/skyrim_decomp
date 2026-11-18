// Source exposure: binary-analysis; no external implementation source reused.
// Static1781680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781680*);
    virtual void release(Static1781680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781680*);
struct Static1781680 {
    void* value;
    Static1781680();
    ~Static1781680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
