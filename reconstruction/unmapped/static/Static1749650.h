// Source exposure: binary-analysis; no external implementation source reused.
// Static1749650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1749650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1749650*);
    virtual void release(Static1749650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1749650*);
struct Static1749650 {
    void* value;
    Static1749650();
    ~Static1749650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
