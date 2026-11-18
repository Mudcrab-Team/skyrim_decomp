// Source exposure: binary-analysis; no external implementation source reused.
// Static1755d50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755d50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755d50*);
    virtual void release(Static1755d50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755d50*);
struct Static1755d50 {
    void* value;
    Static1755d50();
    ~Static1755d50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
