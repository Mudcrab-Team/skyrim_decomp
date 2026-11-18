// Source exposure: binary-analysis; no external implementation source reused.
// Static1750df0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750df0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750df0*);
    virtual void release(Static1750df0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750df0*);
struct Static1750df0 {
    void* value;
    Static1750df0();
    ~Static1750df0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
