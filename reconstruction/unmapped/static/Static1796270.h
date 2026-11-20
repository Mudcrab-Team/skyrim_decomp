// Source exposure: binary-analysis; no external implementation source reused.
// Static1796270, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796270;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796270*);
    virtual void release(Static1796270*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796270*);
struct Static1796270 {
    void* value;
    Static1796270();
    ~Static1796270() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
