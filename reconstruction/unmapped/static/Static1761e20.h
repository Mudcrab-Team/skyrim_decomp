// Source exposure: binary-analysis; no external implementation source reused.
// Static1761e20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761e20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761e20*);
    virtual void release(Static1761e20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761e20*);
struct Static1761e20 {
    void* value;
    Static1761e20();
    ~Static1761e20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
