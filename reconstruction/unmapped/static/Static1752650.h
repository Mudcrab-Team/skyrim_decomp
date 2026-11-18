// Source exposure: binary-analysis; no external implementation source reused.
// Static1752650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752650*);
    virtual void release(Static1752650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752650*);
struct Static1752650 {
    void* value;
    Static1752650();
    ~Static1752650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
