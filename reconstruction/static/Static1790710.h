// Source exposure: binary-analysis; no external implementation source reused.
// Static1790710, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790710;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790710*);
    virtual void release(Static1790710*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790710*);
struct Static1790710 {
    void* value;
    Static1790710();
    ~Static1790710() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
