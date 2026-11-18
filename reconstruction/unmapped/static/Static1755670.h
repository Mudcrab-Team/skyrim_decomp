// Source exposure: binary-analysis; no external implementation source reused.
// Static1755670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755670*);
    virtual void release(Static1755670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755670*);
struct Static1755670 {
    void* value;
    Static1755670();
    ~Static1755670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
