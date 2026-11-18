// Source exposure: binary-analysis; no external implementation source reused.
// Static1750120, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750120;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750120*);
    virtual void release(Static1750120*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750120*);
struct Static1750120 {
    void* value;
    Static1750120();
    ~Static1750120() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
