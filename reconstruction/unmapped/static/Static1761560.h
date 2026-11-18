// Source exposure: binary-analysis; no external implementation source reused.
// Static1761560, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761560;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761560*);
    virtual void release(Static1761560*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761560*);
struct Static1761560 {
    void* value;
    Static1761560();
    ~Static1761560() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
