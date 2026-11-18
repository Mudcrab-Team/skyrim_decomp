// Source exposure: binary-analysis; no external implementation source reused.
// Static1753730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1753730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1753730*);
    virtual void release(Static1753730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1753730*);
struct Static1753730 {
    void* value;
    Static1753730();
    ~Static1753730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
