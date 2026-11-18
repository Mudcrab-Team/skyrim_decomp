// Source exposure: binary-analysis; no external implementation source reused.
// Static1758690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1758690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1758690*);
    virtual void release(Static1758690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1758690*);
struct Static1758690 {
    void* value;
    Static1758690();
    ~Static1758690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
