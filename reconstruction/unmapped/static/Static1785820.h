// Source exposure: binary-analysis; no external implementation source reused.
// Static1785820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785820*);
    virtual void release(Static1785820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785820*);
struct Static1785820 {
    void* value;
    Static1785820();
    ~Static1785820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
