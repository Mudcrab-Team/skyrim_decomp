// Source exposure: binary-analysis; no external implementation source reused.
// Static1785870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785870*);
    virtual void release(Static1785870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785870*);
struct Static1785870 {
    void* value;
    Static1785870();
    ~Static1785870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
