// Source exposure: binary-analysis; no external implementation source reused.
// Static1774980, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774980;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774980*);
    virtual void release(Static1774980*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774980*);
struct Static1774980 {
    void* value;
    Static1774980();
    ~Static1774980() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
