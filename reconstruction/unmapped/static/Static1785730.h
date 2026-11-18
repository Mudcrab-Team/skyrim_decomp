// Source exposure: binary-analysis; no external implementation source reused.
// Static1785730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1785730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1785730*);
    virtual void release(Static1785730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1785730*);
struct Static1785730 {
    void* value;
    Static1785730();
    ~Static1785730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
