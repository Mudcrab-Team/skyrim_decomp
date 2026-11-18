// Source exposure: binary-analysis; no external implementation source reused.
// Static1763950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1763950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1763950*);
    virtual void release(Static1763950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1763950*);
struct Static1763950 {
    void* value;
    Static1763950();
    ~Static1763950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
