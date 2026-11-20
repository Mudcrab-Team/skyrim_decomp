// Source exposure: binary-analysis; no external implementation source reused.
// Static1757510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1757510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1757510*);
    virtual void release(Static1757510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1757510*);
struct Static1757510 {
    void* value;
    Static1757510();
    ~Static1757510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
