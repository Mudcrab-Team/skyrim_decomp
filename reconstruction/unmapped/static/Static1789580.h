// Source exposure: binary-analysis; no external implementation source reused.
// Static1789580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789580*);
    virtual void release(Static1789580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789580*);
struct Static1789580 {
    void* value;
    Static1789580();
    ~Static1789580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
