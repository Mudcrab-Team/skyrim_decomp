// Source exposure: binary-analysis; no external implementation source reused.
// Static1754590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1754590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1754590*);
    virtual void release(Static1754590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1754590*);
struct Static1754590 {
    void* value;
    Static1754590();
    ~Static1754590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
