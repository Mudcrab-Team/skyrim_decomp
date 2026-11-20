// Source exposure: binary-analysis; no external implementation source reused.
// Static1755530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755530*);
    virtual void release(Static1755530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755530*);
struct Static1755530 {
    void* value;
    Static1755530();
    ~Static1755530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
