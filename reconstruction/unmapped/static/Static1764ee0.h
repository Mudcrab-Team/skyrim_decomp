// Source exposure: binary-analysis; no external implementation source reused.
// Static1764ee0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764ee0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764ee0*);
    virtual void release(Static1764ee0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764ee0*);
struct Static1764ee0 {
    void* value;
    Static1764ee0();
    ~Static1764ee0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
