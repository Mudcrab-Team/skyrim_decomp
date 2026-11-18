// Source exposure: binary-analysis; no external implementation source reused.
// Static1799760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799760*);
    virtual void release(Static1799760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799760*);
struct Static1799760 {
    void* value;
    Static1799760();
    ~Static1799760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
