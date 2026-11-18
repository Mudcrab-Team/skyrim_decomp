// Source exposure: binary-analysis; no external implementation source reused.
// Static1775f60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775f60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775f60*);
    virtual void release(Static1775f60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775f60*);
struct Static1775f60 {
    void* value;
    Static1775f60();
    ~Static1775f60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
