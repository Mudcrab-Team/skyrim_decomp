// Source exposure: binary-analysis; no external implementation source reused.
// Static1750800, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750800;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750800*);
    virtual void release(Static1750800*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750800*);
struct Static1750800 {
    void* value;
    Static1750800();
    ~Static1750800() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
