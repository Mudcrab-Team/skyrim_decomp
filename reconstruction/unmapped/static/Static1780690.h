// Source exposure: binary-analysis; no external implementation source reused.
// Static1780690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780690*);
    virtual void release(Static1780690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780690*);
struct Static1780690 {
    void* value;
    Static1780690();
    ~Static1780690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
