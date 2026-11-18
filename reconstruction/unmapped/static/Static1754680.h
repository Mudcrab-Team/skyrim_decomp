// Source exposure: binary-analysis; no external implementation source reused.
// Static1754680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754680*);
    virtual void release(Static1754680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754680*);
struct Static1754680 {
    void* value;
    Static1754680();
    ~Static1754680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
