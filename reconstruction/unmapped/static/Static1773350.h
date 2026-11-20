// Source exposure: binary-analysis; no external implementation source reused.
// Static1773350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1773350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1773350*);
    virtual void release(Static1773350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1773350*);
struct Static1773350 {
    void* value;
    Static1773350();
    ~Static1773350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
