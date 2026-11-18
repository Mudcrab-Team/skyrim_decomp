// Source exposure: binary-analysis; no external implementation source reused.
// Static1788610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1788610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1788610*);
    virtual void release(Static1788610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1788610*);
struct Static1788610 {
    void* value;
    Static1788610();
    ~Static1788610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
