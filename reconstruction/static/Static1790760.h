// Source exposure: binary-analysis; no external implementation source reused.
// Static1790760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790760*);
    virtual void release(Static1790760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790760*);
struct Static1790760 {
    void* value;
    Static1790760();
    ~Static1790760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
