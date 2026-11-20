// Source exposure: binary-analysis; no external implementation source reused.
// Static1760c00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760c00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760c00*);
    virtual void release(Static1760c00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760c00*);
struct Static1760c00 {
    void* value;
    Static1760c00();
    ~Static1760c00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
