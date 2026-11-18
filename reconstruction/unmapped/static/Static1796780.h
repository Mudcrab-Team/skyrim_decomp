// Source exposure: binary-analysis; no external implementation source reused.
// Static1796780, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796780;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796780*);
    virtual void release(Static1796780*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796780*);
struct Static1796780 {
    void* value;
    Static1796780();
    ~Static1796780() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
