// Source exposure: binary-analysis; no external implementation source reused.
// Static1747610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1747610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1747610*);
    virtual void release(Static1747610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1747610*);
struct Static1747610 {
    void* value;
    Static1747610();
    ~Static1747610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
