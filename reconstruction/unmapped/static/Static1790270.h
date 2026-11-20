// Source exposure: binary-analysis; no external implementation source reused.
// Static1790270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790270*);
    virtual void release(Static1790270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790270*);
struct Static1790270 {
    void* value;
    Static1790270();
    ~Static1790270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
