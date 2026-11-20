// Source exposure: binary-analysis; no external implementation source reused.
// Static1753870, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753870;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753870*);
    virtual void release(Static1753870*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753870*);
struct Static1753870 {
    void* value;
    Static1753870();
    ~Static1753870() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
