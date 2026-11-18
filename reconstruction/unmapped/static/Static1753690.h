// Source exposure: binary-analysis; no external implementation source reused.
// Static1753690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753690*);
    virtual void release(Static1753690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753690*);
struct Static1753690 {
    void* value;
    Static1753690();
    ~Static1753690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
