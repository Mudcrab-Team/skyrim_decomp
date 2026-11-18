// Source exposure: binary-analysis; no external implementation source reused.
// Static1778080, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778080;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778080*);
    virtual void release(Static1778080*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778080*);
struct Static1778080 {
    void* value;
    Static1778080();
    ~Static1778080() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
