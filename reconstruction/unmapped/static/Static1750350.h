// Source exposure: binary-analysis; no external implementation source reused.
// Static1750350, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750350;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750350*);
    virtual void release(Static1750350*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750350*);
struct Static1750350 {
    void* value;
    Static1750350();
    ~Static1750350() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
