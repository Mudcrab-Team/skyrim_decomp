// Source exposure: binary-analysis; no external implementation source reused.
// Static1771730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771730*);
    virtual void release(Static1771730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771730*);
struct Static1771730 {
    void* value;
    Static1771730();
    ~Static1771730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
