// Source exposure: binary-analysis; no external implementation source reused.
// Static1772950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1772950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1772950*);
    virtual void release(Static1772950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1772950*);
struct Static1772950 {
    void* value;
    Static1772950();
    ~Static1772950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
