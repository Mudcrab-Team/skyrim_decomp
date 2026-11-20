// Source exposure: binary-analysis; no external implementation source reused.
// Static1798740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1798740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1798740*);
    virtual void release(Static1798740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1798740*);
struct Static1798740 {
    void* value;
    Static1798740();
    ~Static1798740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
