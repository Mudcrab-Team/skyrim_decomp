// Source exposure: binary-analysis; no external implementation source reused.
// Static1750440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750440*);
    virtual void release(Static1750440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750440*);
struct Static1750440 {
    void* value;
    Static1750440();
    ~Static1750440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
