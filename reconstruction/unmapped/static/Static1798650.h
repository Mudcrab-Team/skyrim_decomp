// Source exposure: binary-analysis; no external implementation source reused.
// Static1798650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1798650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1798650*);
    virtual void release(Static1798650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1798650*);
struct Static1798650 {
    void* value;
    Static1798650();
    ~Static1798650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
