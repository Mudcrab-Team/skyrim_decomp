// Source exposure: binary-analysis; no external implementation source reused.
// Static1759590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759590*);
    virtual void release(Static1759590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759590*);
struct Static1759590 {
    void* value;
    Static1759590();
    ~Static1759590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
