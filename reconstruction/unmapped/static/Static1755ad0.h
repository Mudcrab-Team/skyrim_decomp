// Source exposure: binary-analysis; no external implementation source reused.
// Static1755ad0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755ad0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755ad0*);
    virtual void release(Static1755ad0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755ad0*);
struct Static1755ad0 {
    void* value;
    Static1755ad0();
    ~Static1755ad0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
