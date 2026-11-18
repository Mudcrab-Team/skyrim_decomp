// Source exposure: binary-analysis; no external implementation source reused.
// Static1755710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1755710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1755710*);
    virtual void release(Static1755710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1755710*);
struct Static1755710 {
    void* value;
    Static1755710();
    ~Static1755710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
