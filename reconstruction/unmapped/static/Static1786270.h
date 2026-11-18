// Source exposure: binary-analysis; no external implementation source reused.
// Static1786270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786270*);
    virtual void release(Static1786270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786270*);
struct Static1786270 {
    void* value;
    Static1786270();
    ~Static1786270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
