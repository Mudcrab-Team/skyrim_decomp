// Source exposure: binary-analysis; no external implementation source reused.
// Static1781900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781900*);
    virtual void release(Static1781900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781900*);
struct Static1781900 {
    void* value;
    Static1781900();
    ~Static1781900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
