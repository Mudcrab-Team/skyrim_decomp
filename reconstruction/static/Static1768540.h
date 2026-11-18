// Source exposure: binary-analysis; no external implementation source reused.
// Static1768540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768540*);
    virtual void release(Static1768540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768540*);
struct Static1768540 {
    void* value;
    Static1768540();
    ~Static1768540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
