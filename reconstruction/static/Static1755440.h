// Source exposure: binary-analysis; no external implementation source reused.
// Static1755440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755440*);
    virtual void release(Static1755440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755440*);
struct Static1755440 {
    void* value;
    Static1755440();
    ~Static1755440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
