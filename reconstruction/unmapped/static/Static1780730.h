// Source exposure: binary-analysis; no external implementation source reused.
// Static1780730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780730*);
    virtual void release(Static1780730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780730*);
struct Static1780730 {
    void* value;
    Static1780730();
    ~Static1780730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
