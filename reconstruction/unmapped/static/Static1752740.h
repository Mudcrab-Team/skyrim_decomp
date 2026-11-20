// Source exposure: binary-analysis; no external implementation source reused.
// Static1752740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1752740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1752740*);
    virtual void release(Static1752740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1752740*);
struct Static1752740 {
    void* value;
    Static1752740();
    ~Static1752740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
