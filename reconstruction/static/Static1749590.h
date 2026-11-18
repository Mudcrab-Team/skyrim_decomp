// Source exposure: binary-analysis; no external implementation source reused.
// Static1749590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1749590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1749590*);
    virtual void release(Static1749590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1749590*);
struct Static1749590 {
    void* value;
    Static1749590();
    ~Static1749590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
