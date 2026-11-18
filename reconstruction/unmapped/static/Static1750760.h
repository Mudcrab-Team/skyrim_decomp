// Source exposure: binary-analysis; no external implementation source reused.
// Static1750760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750760*);
    virtual void release(Static1750760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750760*);
struct Static1750760 {
    void* value;
    Static1750760();
    ~Static1750760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
