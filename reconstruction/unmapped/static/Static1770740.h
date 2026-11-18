// Source exposure: binary-analysis; no external implementation source reused.
// Static1770740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770740*);
    virtual void release(Static1770740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770740*);
struct Static1770740 {
    void* value;
    Static1770740();
    ~Static1770740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
