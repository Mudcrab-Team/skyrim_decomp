// Source exposure: binary-analysis; no external implementation source reused.
// Static1789760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789760*);
    virtual void release(Static1789760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789760*);
struct Static1789760 {
    void* value;
    Static1789760();
    ~Static1789760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
