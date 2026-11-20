// Source exposure: binary-analysis; no external implementation source reused.
// Static1759950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759950*);
    virtual void release(Static1759950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759950*);
struct Static1759950 {
    void* value;
    Static1759950();
    ~Static1759950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
