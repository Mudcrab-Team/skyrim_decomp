// Source exposure: binary-analysis; no external implementation source reused.
// Static1766740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766740*);
    virtual void release(Static1766740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766740*);
struct Static1766740 {
    void* value;
    Static1766740();
    ~Static1766740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
