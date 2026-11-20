// Source exposure: binary-analysis; no external implementation source reused.
// Static1777900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1777900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1777900*);
    virtual void release(Static1777900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1777900*);
struct Static1777900 {
    void* value;
    Static1777900();
    ~Static1777900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
