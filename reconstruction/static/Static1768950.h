// Source exposure: binary-analysis; no external implementation source reused.
// Static1768950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1768950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1768950*);
    virtual void release(Static1768950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1768950*);
struct Static1768950 {
    void* value;
    Static1768950();
    ~Static1768950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
