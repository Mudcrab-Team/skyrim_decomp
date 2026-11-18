// Source exposure: binary-analysis; no external implementation source reused.
// Static1766650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766650*);
    virtual void release(Static1766650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766650*);
struct Static1766650 {
    void* value;
    Static1766650();
    ~Static1766650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
