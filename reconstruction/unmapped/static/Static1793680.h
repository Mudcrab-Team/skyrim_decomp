// Source exposure: binary-analysis; no external implementation source reused.
// Static1793680, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1793680;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1793680*);
    virtual void release(Static1793680*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1793680*);
struct Static1793680 {
    void* value;
    Static1793680();
    ~Static1793680() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
