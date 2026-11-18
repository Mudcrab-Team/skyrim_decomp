// Source exposure: binary-analysis; no external implementation source reused.
// Static1778350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778350*);
    virtual void release(Static1778350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778350*);
struct Static1778350 {
    void* value;
    Static1778350();
    ~Static1778350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
