// Source exposure: binary-analysis; no external implementation source reused.
// Static1792650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1792650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1792650*);
    virtual void release(Static1792650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1792650*);
struct Static1792650 {
    void* value;
    Static1792650();
    ~Static1792650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
