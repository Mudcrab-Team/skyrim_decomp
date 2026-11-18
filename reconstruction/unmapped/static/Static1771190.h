// Source exposure: binary-analysis; no external implementation source reused.
// Static1771190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771190*);
    virtual void release(Static1771190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771190*);
struct Static1771190 {
    void* value;
    Static1771190();
    ~Static1771190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
