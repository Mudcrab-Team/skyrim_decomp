// Source exposure: binary-analysis; no external implementation source reused.
// Static1796870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796870*);
    virtual void release(Static1796870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796870*);
struct Static1796870 {
    void* value;
    Static1796870();
    ~Static1796870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
