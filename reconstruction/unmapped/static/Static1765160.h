// Source exposure: binary-analysis; no external implementation source reused.
// Static1765160, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765160;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765160*);
    virtual void release(Static1765160*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765160*);
struct Static1765160 {
    void* value;
    Static1765160();
    ~Static1765160() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
