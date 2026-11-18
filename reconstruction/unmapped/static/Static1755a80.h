// Source exposure: binary-analysis; no external implementation source reused.
// Static1755a80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755a80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755a80*);
    virtual void release(Static1755a80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755a80*);
struct Static1755a80 {
    void* value;
    Static1755a80();
    ~Static1755a80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
