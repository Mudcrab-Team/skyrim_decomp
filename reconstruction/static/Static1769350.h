// Source exposure: binary-analysis; no external implementation source reused.
// Static1769350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1769350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1769350*);
    virtual void release(Static1769350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1769350*);
struct Static1769350 {
    void* value;
    Static1769350();
    ~Static1769350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
