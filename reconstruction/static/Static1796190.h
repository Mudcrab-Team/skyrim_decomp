// Source exposure: binary-analysis; no external implementation source reused.
// Static1796190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1796190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1796190*);
    virtual void release(Static1796190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1796190*);
struct Static1796190 {
    void* value;
    Static1796190();
    ~Static1796190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
