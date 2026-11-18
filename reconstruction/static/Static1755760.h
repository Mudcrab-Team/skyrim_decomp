// Source exposure: binary-analysis; no external implementation source reused.
// Static1755760, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755760;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755760*);
    virtual void release(Static1755760*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755760*);
struct Static1755760 {
    void* value;
    Static1755760();
    ~Static1755760() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
