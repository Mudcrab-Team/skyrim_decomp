// Source exposure: binary-analysis; no external implementation source reused.
// Static1754950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754950*);
    virtual void release(Static1754950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754950*);
struct Static1754950 {
    void* value;
    Static1754950();
    ~Static1754950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
