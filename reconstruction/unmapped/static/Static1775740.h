// Source exposure: binary-analysis; no external implementation source reused.
// Static1775740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775740*);
    virtual void release(Static1775740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775740*);
struct Static1775740 {
    void* value;
    Static1775740();
    ~Static1775740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
