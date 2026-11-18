// Source exposure: binary-analysis; no external implementation source reused.
// Static1742190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742190*);
    virtual void release(Static1742190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742190*);
struct Static1742190 {
    void* value;
    Static1742190();
    ~Static1742190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
