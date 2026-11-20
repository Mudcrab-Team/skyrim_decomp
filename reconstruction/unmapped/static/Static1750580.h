// Source exposure: binary-analysis; no external implementation source reused.
// Static1750580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750580*);
    virtual void release(Static1750580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750580*);
struct Static1750580 {
    void* value;
    Static1750580();
    ~Static1750580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
