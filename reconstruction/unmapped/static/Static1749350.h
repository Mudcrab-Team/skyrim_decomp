// Source exposure: binary-analysis; no external implementation source reused.
// Static1749350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1749350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1749350*);
    virtual void release(Static1749350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1749350*);
struct Static1749350 {
    void* value;
    Static1749350();
    ~Static1749350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
