// Source exposure: binary-analysis; no external implementation source reused.
// Static1789350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789350*);
    virtual void release(Static1789350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789350*);
struct Static1789350 {
    void* value;
    Static1789350();
    ~Static1789350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
