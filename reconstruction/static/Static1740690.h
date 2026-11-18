// Source exposure: binary-analysis; no external implementation source reused.
// Static1740690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1740690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1740690*);
    virtual void release(Static1740690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1740690*);
struct Static1740690 {
    void* value;
    Static1740690();
    ~Static1740690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
