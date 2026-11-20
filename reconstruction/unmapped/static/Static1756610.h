// Source exposure: binary-analysis; no external implementation source reused.
// Static1756610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1756610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1756610*);
    virtual void release(Static1756610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1756610*);
struct Static1756610 {
    void* value;
    Static1756610();
    ~Static1756610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
