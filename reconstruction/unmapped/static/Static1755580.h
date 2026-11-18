// Source exposure: binary-analysis; no external implementation source reused.
// Static1755580, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755580;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755580*);
    virtual void release(Static1755580*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755580*);
struct Static1755580 {
    void* value;
    Static1755580();
    ~Static1755580() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
