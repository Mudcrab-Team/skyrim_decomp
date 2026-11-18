// Source exposure: binary-analysis; no external implementation source reused.
// Static1755d00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755d00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755d00*);
    virtual void release(Static1755d00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755d00*);
struct Static1755d00 {
    void* value;
    Static1755d00();
    ~Static1755d00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
