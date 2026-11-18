// Source exposure: binary-analysis; no external implementation source reused.
// Static1778530, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778530;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778530*);
    virtual void release(Static1778530*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778530*);
struct Static1778530 {
    void* value;
    Static1778530();
    ~Static1778530() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
