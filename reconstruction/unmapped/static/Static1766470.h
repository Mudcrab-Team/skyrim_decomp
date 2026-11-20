// Source exposure: binary-analysis; no external implementation source reused.
// Static1766470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766470*);
    virtual void release(Static1766470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766470*);
struct Static1766470 {
    void* value;
    Static1766470();
    ~Static1766470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
