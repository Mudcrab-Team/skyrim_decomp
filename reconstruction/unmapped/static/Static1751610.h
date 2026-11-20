// Source exposure: binary-analysis; no external implementation source reused.
// Static1751610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751610*);
    virtual void release(Static1751610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751610*);
struct Static1751610 {
    void* value;
    Static1751610();
    ~Static1751610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
