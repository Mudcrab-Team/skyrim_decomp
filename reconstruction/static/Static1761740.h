// Source exposure: binary-analysis; no external implementation source reused.
// Static1761740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761740*);
    virtual void release(Static1761740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761740*);
struct Static1761740 {
    void* value;
    Static1761740();
    ~Static1761740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
