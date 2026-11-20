// Source exposure: binary-analysis; no external implementation source reused.
// Static1749160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1749160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1749160*);
    virtual void release(Static1749160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1749160*);
struct Static1749160 {
    void* value;
    Static1749160();
    ~Static1749160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
