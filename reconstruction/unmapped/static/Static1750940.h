// Source exposure: binary-analysis; no external implementation source reused.
// Static1750940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750940*);
    virtual void release(Static1750940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750940*);
struct Static1750940 {
    void* value;
    Static1750940();
    ~Static1750940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
