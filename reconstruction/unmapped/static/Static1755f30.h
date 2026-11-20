// Source exposure: binary-analysis; no external implementation source reused.
// Static1755f30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755f30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755f30*);
    virtual void release(Static1755f30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755f30*);
struct Static1755f30 {
    void* value;
    Static1755f30();
    ~Static1755f30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
