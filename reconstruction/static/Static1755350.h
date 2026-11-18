// Source exposure: binary-analysis; no external implementation source reused.
// Static1755350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755350*);
    virtual void release(Static1755350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755350*);
struct Static1755350 {
    void* value;
    Static1755350();
    ~Static1755350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
