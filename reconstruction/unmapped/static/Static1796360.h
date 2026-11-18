// Source exposure: binary-analysis; no external implementation source reused.
// Static1796360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796360*);
    virtual void release(Static1796360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796360*);
struct Static1796360 {
    void* value;
    Static1796360();
    ~Static1796360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
