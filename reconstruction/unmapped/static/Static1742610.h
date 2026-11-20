// Source exposure: binary-analysis; no external implementation source reused.
// Static1742610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742610*);
    virtual void release(Static1742610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742610*);
struct Static1742610 {
    void* value;
    Static1742610();
    ~Static1742610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
