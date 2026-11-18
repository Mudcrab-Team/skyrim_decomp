// Source exposure: binary-analysis; no external implementation source reused.
// Static1740400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740400*);
    virtual void release(Static1740400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740400*);
struct Static1740400 {
    void* value;
    Static1740400();
    ~Static1740400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
