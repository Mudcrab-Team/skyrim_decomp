// Source exposure: binary-analysis; no external implementation source reused.
// Static1790610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790610*);
    virtual void release(Static1790610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790610*);
struct Static1790610 {
    void* value;
    Static1790610();
    ~Static1790610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
