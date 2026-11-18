// Source exposure: binary-analysis; no external implementation source reused.
// Static1785690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785690*);
    virtual void release(Static1785690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785690*);
struct Static1785690 {
    void* value;
    Static1785690();
    ~Static1785690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
