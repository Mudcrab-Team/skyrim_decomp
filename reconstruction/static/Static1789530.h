// Source exposure: binary-analysis; no external implementation source reused.
// Static1789530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1789530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1789530*);
    virtual void release(Static1789530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1789530*);
struct Static1789530 {
    void* value;
    Static1789530();
    ~Static1789530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
