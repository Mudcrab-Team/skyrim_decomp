// Source exposure: binary-analysis; no external implementation source reused.
// Static1755300, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755300;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755300*);
    virtual void release(Static1755300*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755300*);
struct Static1755300 {
    void* value;
    Static1755300();
    ~Static1755300() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
