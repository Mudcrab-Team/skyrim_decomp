// Source exposure: binary-analysis; no external implementation source reused.
// Static1765610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765610*);
    virtual void release(Static1765610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765610*);
struct Static1765610 {
    void* value;
    Static1765610();
    ~Static1765610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
